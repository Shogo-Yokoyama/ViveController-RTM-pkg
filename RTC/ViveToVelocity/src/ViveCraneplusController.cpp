// -*- C++ -*-
/*!
 * @file  ViveCraneplusController.cpp
 * @brief The controller of CRANE+ with HTC VIVE
 * @date $Date$
 *
 * $Id$
 */

#include "ViveCraneplusController.h"

// Module specification
// <rtc-template block="module_spec">
static const char* vivecranepluscontroller_spec[] =
  {
    "implementation_id", "ViveCraneplusController",
    "type_name",         "ViveCraneplusController",
    "description",       "The controller of CRANE+ with HTC VIVE",
    "version",           "1.0.0",
    "vendor",            "rsdlab",
    "category",          "The robot controller",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.speed", "20",
    "conf.default.controllerIndex", "0",

    // Widget
    "conf.__widget__.speed", "text",
    "conf.__widget__.controllerIndex", "text",
    // Constraints

    "conf.__type__.speed", "int",
    "conf.__type__.controllerIndex", "int",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ViveCraneplusController::ViveCraneplusController(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_controllerIn("Controller", m_controller),
    m_ManipulatorCommonInterface_CommonPort("ManipulatorCommonInterface_Common"),
    m_ManipulatorCommonInterface_MiddlePort("ManipulatorCommonInterface_Middle")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ViveCraneplusController::~ViveCraneplusController()
{
}



RTC::ReturnCode_t ViveCraneplusController::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("Controller", m_controllerIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  m_ManipulatorCommonInterface_CommonPort.registerConsumer("ManipulatorCommonInterface_Common", "JARA_ARM::ManipulatorCommonInterface_Common", m_ManipulatorCommonInterface_Common);
  m_ManipulatorCommonInterface_MiddlePort.registerConsumer("ManipulatorCommonInterface_Middle", "JARA_ARM::ManipulatorCommonInterface_Middle", m_ManipulatorCommonInterface_Middle);
  
  // Set CORBA Service Ports
  addPort(m_ManipulatorCommonInterface_CommonPort);
  addPort(m_ManipulatorCommonInterface_MiddlePort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("speed", m_Speed, "20");
  bindParameter("controllerIndex", m_controllerIndex, "0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ViveCraneplusController::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveCraneplusController::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveCraneplusController::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ViveCraneplusController::onActivated(RTC::UniqueId ec_id)
{
	//プロバイダより遅くActivateするため
	Sleep(1000);

	//関節速度の設定
	JARA_ARM::ULONG spdRation = m_Speed;
	m_ManipulatorCommonInterface_Middle->setSpeedJoint(spdRation);

	m_rid = m_ManipulatorCommonInterface_Common->servoON();
	if (m_rid->id != 0){//Error
		std::cout << "Servo ON ERROR" << std::endl;
		std::cout << m_rid->comment << std::endl << std::endl;
	}

	getDefaultPosFlag = true;
	bfrGripperFlag = GRIPPER_OPEN;
  
	return RTC::RTC_OK;
}


RTC::ReturnCode_t ViveCraneplusController::onDeactivated(RTC::UniqueId ec_id)
{
	m_rid = m_ManipulatorCommonInterface_Common->servoOFF();
	if (m_rid->id != 0){//Error
		std::cout << "Servo OFF ERROR" << std::endl;
		std::cout << m_rid->comment << std::endl << std::endl;
	}
  
	return RTC::RTC_OK;
}


RTC::ReturnCode_t ViveCraneplusController::onExecute(RTC::UniqueId ec_id)
{
	if (m_controllerIn.isNew())
	{
		m_controllerIn.read();

		if (getDefaultPosFlag)
		{
			getDefaultPosFlag = false;
			defaultVivePos.x = m_controller.data[m_controllerIndex].controllerPoseVel.pose.position.x;
			defaultVivePos.y = m_controller.data[m_controllerIndex].controllerPoseVel.pose.position.y;
			defaultVivePos.z = m_controller.data[m_controllerIndex].controllerPoseVel.pose.position.z;
		}

		//グリッパー閉
		if (bfrGripperFlag == GRIPPER_OPEN && m_controller.data[m_controllerIndex].trigger == 1.0)
		{
			m_rid = m_ManipulatorCommonInterface_Middle->closeGripper();
			if (m_rid->id != 0){//Error
				std::cout << "closeGripper ERROR" << std::endl;
				std::cout << m_rid->comment << std::endl << std::endl;
			}
		}
		//グリッパー開
		else if (bfrGripperFlag == GRIPPER_CLOSE && m_controller.data[m_controllerIndex].trigger != 1.0)
		{
			m_rid = m_ManipulatorCommonInterface_Middle->openGripper();
			if (m_rid->id != 0){//Error
				std::cout << "openGripper ERROR" << std::endl;
				std::cout << m_rid->comment << std::endl << std::endl;
			}
		}
		//アーム操作
		else
		{
			getTargetPos();
		}
	}

	bfrGripperFlag = (m_controller.data[m_controllerIndex].trigger == 1.0) ? GRIPPER_CLOSE : GRIPPER_OPEN;

  
	return RTC::RTC_OK;
}

void ViveCraneplusController::getTargetPos()
{
	//姿勢は自動で計算されるため初期化のみ
	//1列目
	pos.carPos[0][0] = cos(0);
	pos.carPos[1][0] = sin(0);
	pos.carPos[2][0] = 0.0;

	//2列目
	pos.carPos[0][1] = -sin(0);
	pos.carPos[1][1] = cos(0);
	pos.carPos[2][1] = 0.0;

	//3列目
	pos.carPos[0][2] = 0.0;
	pos.carPos[1][2] = 0.0;
	pos.carPos[2][2] = 1.0;

	//4列目
	// 座標系 CRANE+ : HTC VIVE = X : -Z / Y : -X / Z :  Y
	pos.carPos[0][3] =
		250 - (m_controller.data[m_controllerIndex].controllerPoseVel.pose.position.z - defaultVivePos.z) * 1000; //[mm]
	pos.carPos[1][3] =
		250 - (m_controller.data[m_controllerIndex].controllerPoseVel.pose.position.x - defaultVivePos.x) * 1000;
	pos.carPos[2][3] =
		250 + (m_controller.data[m_controllerIndex].controllerPoseVel.pose.position.y - defaultVivePos.y) * 1000;

	m_rid = m_ManipulatorCommonInterface_Middle->movePTPCartesianAbs(pos);
	if (m_rid->id != 0){//Error
		std::cout << "movePTPCartesianAbs ERROR" << std::endl;
		std::cout << m_rid->comment << std::endl << std::endl;
	}
}

/*
RTC::ReturnCode_t ViveCraneplusController::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveCraneplusController::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveCraneplusController::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveCraneplusController::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveCraneplusController::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ViveCraneplusControllerInit(RTC::Manager* manager)
  {
    coil::Properties profile(vivecranepluscontroller_spec);
    manager->registerFactory(profile,
                             RTC::Create<ViveCraneplusController>,
                             RTC::Delete<ViveCraneplusController>);
  }
  
};


