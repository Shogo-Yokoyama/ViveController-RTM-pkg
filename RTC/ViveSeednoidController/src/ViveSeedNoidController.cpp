// -*- C++ -*-
/*!
 * @file  ViveSeedNoidController.cpp
 * @brief SEED-Noid's upper body controller with HTC VIVE
 * @date $Date$
 *
 * $Id$
 */

#include "ViveSeedNoidController.h"

// Module specification
// <rtc-template block="module_spec">
static const char* viveseednoidcontroller_spec[] =
  {
    "implementation_id", "ViveSeedNoidController",
    "type_name",         "ViveSeedNoidController",
    "description",       "SEED-Noid's upper body controller with HTC VIVE",
    "version",           "1.0.0",
    "vendor",            "rsdlab",
    "category",          "robot controller",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ViveSeedNoidController::ViveSeedNoidController(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_controllerIn("Controller", m_controller),
    m_hmdIn("Hmd", m_hmd),
    m_trackerIn("Tracker", m_tracker),
    m_RightManipulatorCommonInterface_CommonPort("RightManipulatorCommonInterface_Common"),
    m_RightManipulatorCommonInterface_MiddlePort("RightManipulatorCommonInterface_Middle"),
    m_LeftManipulatorCommonInterface_CommonPort("LeftManipulatorCommonInterface_Common"),
    m_LeftManipulatorCommonInterface_MiddlePort("LeftManipulatorCommonInterface_Middle"),
    m_WaistInterfacePort("WaistInterface"),
    m_NeckInterfacePort("NeckInterface"),
    m_LifterPosePort("LifterPose"),
    m_RightArmKinematicsInterfacePort("RightArmKinematicsInterface"),
    m_LeftArmKinematicsInterfacePort("LeftArmKinematicsInterface")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ViveSeedNoidController::~ViveSeedNoidController()
{
}



RTC::ReturnCode_t ViveSeedNoidController::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("Controller", m_controllerIn);
  addInPort("Hmd", m_hmdIn);
  addInPort("Tracker", m_trackerIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  m_RightManipulatorCommonInterface_CommonPort.registerConsumer("ManipulatorCommonInterface_Common", "JARA_ARM::ManipulatorCommonInterface_Common", m_ManipulatorCommonInterface_Common);
  m_RightManipulatorCommonInterface_MiddlePort.registerConsumer("ManipulatorCommonInterface_Middle", "JARA_ARM::ManipulatorCommonInterface_Middle", m_ManipulatorCommonInterface_Middle);
  m_LeftManipulatorCommonInterface_CommonPort.registerConsumer("LeftManipulatorCommonInterface_Common", "JARA_ARM_LEFT::LeftManipulatorCommonInterface_Common", m_LeftManipulatorCommonInterface_Common);
  m_LeftManipulatorCommonInterface_MiddlePort.registerConsumer("LeftManipulatorCommonInterface_Middle", "JARA_ARM_LEFT::LeftManipulatorCommonInterface_Middle", m_LeftManipulatorCommonInterface_Middle);
  m_WaistInterfacePort.registerConsumer("WaistInterface", "WaistNeck::WaistInterface", m_WaistInterface);
  m_NeckInterfacePort.registerConsumer("NeckInterface", "WaistNeck::NeckInterface", m_NeckInterface);
  m_LifterPosePort.registerConsumer("lifter", "SeedNoid_Lifter::LifterPoseInterface", m_lifter);
  m_RightArmKinematicsInterfacePort.registerConsumer("RightArmKinematicsInterface", "IK_RTC::RightArmKinematicsInterface", m_RightArmKinematicsInterface);
  m_LeftArmKinematicsInterfacePort.registerConsumer("LeftArmKinematicsInterface", "IK_RTC::LeftArmKinematicsInterface", m_LeftArmKinematicsInterface);
  
  // Set CORBA Service Ports
  addPort(m_RightManipulatorCommonInterface_CommonPort);
  addPort(m_RightManipulatorCommonInterface_MiddlePort);
  addPort(m_LeftManipulatorCommonInterface_CommonPort);
  addPort(m_LeftManipulatorCommonInterface_MiddlePort);
  addPort(m_WaistInterfacePort);
  addPort(m_NeckInterfacePort);
  addPort(m_LifterPosePort);
  addPort(m_RightArmKinematicsInterfacePort);
  addPort(m_LeftArmKinematicsInterfacePort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ViveSeedNoidController::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveSeedNoidController::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveSeedNoidController::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ViveSeedNoidController::onActivated(RTC::UniqueId ec_id)
{
	Sleep(1);	//プロバイダより遅くActivateするため
	getDefaultPosFlag = true;
	bfrGripperFlag = GRIPPER_OPEN;
	controllerIndex = 0;	//今回は右腕制御のみ　//左腕・頭部の制御も実装予定
	initMove();
	Sleep(3);
  
	return RTC::RTC_OK;
}


RTC::ReturnCode_t ViveSeedNoidController::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ViveSeedNoidController::onExecute(RTC::UniqueId ec_id)
{
	if (m_controllerIn.read())
	{
		m_controllerIn.read();

		// トリガーを引いたときのコントローラの位置をSEED-Noidの手先の初期位置とする
		if (m_controller.data[controllerIndex].trigger == 1.0 && getDefaultPosFlag)
		{
			getDefaultPosFlag = false;
			getDefaultVivePos();
		}

		// グリップボタンを押しているときのみアームを操作
		if (m_controller.data[controllerIndex].gripButton)
		{
			//グリッパー閉
			if (bfrGripperFlag == GRIPPER_OPEN && m_controller.data[controllerIndex].trigger == 1.0)
			{
				m_rid_right = m_ManipulatorCommonInterface_Middle->closeGripper();
				if (m_rid_right->id != 0) {//Error
					std::cout << "closeGripper ERROR" << std::endl;
					std::cout << m_rid_right->comment << std::endl << std::endl;
				}
			}
			//グリッパー開
			else if (bfrGripperFlag == GRIPPER_CLOSE && m_controller.data[controllerIndex].trigger != 1.0)
			{
				m_rid_right = m_ManipulatorCommonInterface_Middle->openGripper();
				if (m_rid_right->id != 0) {//Error
					std::cout << "openGripper ERROR" << std::endl;
					std::cout << m_rid_right->comment << std::endl << std::endl;
				}
			}
			//アーム操作
			else
			{
				getTargetPos();
			}
		}
	}

	bfrGripperFlag = (m_controller.data[controllerIndex].trigger == 1.0) ? GRIPPER_CLOSE : GRIPPER_OPEN;
  
	return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ViveSeedNoidController::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveSeedNoidController::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveSeedNoidController::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveSeedNoidController::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveSeedNoidController::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

void ViveSeedNoidController::getDefaultVivePos()
{
	defaultVivePos.x = m_controller.data[controllerIndex].controllerPoseVel.pose.position.x;
	defaultVivePos.y = m_controller.data[controllerIndex].controllerPoseVel.pose.position.y;
	defaultVivePos.z = m_controller.data[controllerIndex].controllerPoseVel.pose.position.z;
}

int ViveSeedNoidController::getTargetPos()
{
	double roll;
	double pitch;
	double yaw;
	double calceerot[9];
	IK_RTC::Rotation eerot;
	IK_RTC::FramePos eetrans;
	IK_RTC::WaistFrame WaistPos;
	IK_RTC::JointPos nowJointPos;
	IK_RTC::JointPos_var solRightJointPosvar;
	IK_RTC::JointPos solRightJointPos;
	eerot.length(9);
	eetrans.length(3);
	nowJointPos.length(10);
	solRightJointPos.length(10);
	JARA_ARM::JointPos jointPoint;
	jointPoint.length(7);
	WaistNeck::WaistPos waistPoint;
	waistPoint.length(3);

	roll = 90;
	pitch = -90;
	yaw = 0;
	WaistPos.yaw = 0;
	WaistPos.pitch = 0;
	WaistPos.roll = 0;
	TransRot(calceerot, roll, pitch, yaw);
	eetrans[0] = 400 - (m_controller.data[controllerIndex].controllerPoseVel.pose.position.z - defaultVivePos.z) * 1000; //[mm];//x
	eetrans[1] = -200 - (m_controller.data[controllerIndex].controllerPoseVel.pose.position.x - defaultVivePos.x) * 1000;//y
	eetrans[2] = 300 + ((m_controller.data[controllerIndex].controllerPoseVel.pose.position.y - defaultVivePos.y) * 1000) - 200;//z↑すぎるのでz-200

	for (int j = 0; j < 10; j++)
	{
		nowJointPos[j] = 0;
	}
	for (int i = 0; i < 9; i++) {
		eerot[i] = calceerot[i];
	}

	m_rid_RIK = m_RightArmKinematicsInterface->solveRightArmIkSetWaistJoint(eerot, eetrans, WaistPos, nowJointPos, solRightJointPosvar);
	if (m_rid_RIK->id != 0) {//Error
		std::cout << "solveRightIkSetWaistJoint ERROR" << std::endl;
		std::cout << m_rid_RIK->comment << std::endl << std::endl;
		return -1;
	}
	solRightJointPos = solRightJointPosvar;

	waistPoint[0] = solRightJointPos[0];
	waistPoint[1] = solRightJointPos[1];
	waistPoint[2] = solRightJointPos[2];
	for (int k = 0; k < 7; k++)
	{
		jointPoint[k] = solRightJointPos[k + 3];
	}
	m_rid_waist = m_WaistInterface->movePTPWaistAbs(waistPoint);
	if (m_rid_waist->id != 0) {//Error
		std::cout << "movePTPWaistAbs ERROR" << std::endl;
		std::cout << m_rid_waist->comment << std::endl << std::endl;
	}

	m_rid_right = m_ManipulatorCommonInterface_Middle->movePTPJointAbs(jointPoint);
	if (m_rid_right->id != 0) {//Error
		std::cout << "movePTPJointAbs ERROR" << std::endl;
		std::cout << m_rid_right->comment << std::endl << std::endl;
	}
	return 0;
}

int ViveSeedNoidController::initMove()
{
	//double x;
	//double y;
	//double z;
	double roll;
	double pitch;
	double yaw;
	double calceerot[9];
	IK_RTC::Rotation eerot;
	IK_RTC::FramePos eetrans;
	IK_RTC::WaistFrame WaistPos;
	IK_RTC::JointPos nowJointPos;
	IK_RTC::JointPos_var solRightJointPosvar;
	IK_RTC::JointPos solRightJointPos;
	eerot.length(9);
	eetrans.length(3);
	nowJointPos.length(10);
	solRightJointPos.length(10);
	JARA_ARM::JointPos jointPoint;
	jointPoint.length(7);
	WaistNeck::WaistPos waistPoint;
	waistPoint.length(3);

	roll = 90;
	pitch = -90;
	yaw = 0;
	WaistPos.yaw = 0;
	WaistPos.pitch = 0;
	WaistPos.roll = 0;
	TransRot(calceerot, roll, pitch, yaw);
	eetrans[0] = 400; //[mm];//x
	eetrans[1] = -300;//y
	eetrans[2] = 200;//z

	for (int j = 0; j < 10; j++)
	{
		nowJointPos[j] = 0;
	}
	for (int i = 0; i < 9; i++) {
		eerot[i] = calceerot[i];
	}

	m_rid_RIK = m_RightArmKinematicsInterface->solveRightArmIkSetWaistJoint(eerot, eetrans, WaistPos, nowJointPos, solRightJointPosvar);
	if (m_rid_RIK->id != 0) {//Error
		std::cout << "solveRightIkSetWaistJoint ERROR" << std::endl;
		std::cout << m_rid_RIK->comment << std::endl << std::endl;
		return -1;
	}
	solRightJointPos = solRightJointPosvar;

	waistPoint[0] = solRightJointPos[0];
	waistPoint[1] = solRightJointPos[1];
	waistPoint[2] = solRightJointPos[2];
	for (int k = 0; k < 7; k++)
	{
		jointPoint[k] = solRightJointPos[k + 3];
	}
	m_rid_waist = m_WaistInterface->movePTPWaistAbs(waistPoint);
	if (m_rid_waist->id != 0) {//Error
		std::cout << "movePTPWaistAbs ERROR" << std::endl;
		std::cout << m_rid_waist->comment << std::endl << std::endl;
	}

	m_rid_right = m_ManipulatorCommonInterface_Middle->movePTPJointAbs(jointPoint);
	if (m_rid_right->id != 0) {//Error
		std::cout << "movePTPJointAbs ERROR" << std::endl;
		std::cout << m_rid_right->comment << std::endl << std::endl;
	}
	return 0;

}

/************************************************

	void TransRot(double eerot[],double roll,double pitch,double yaw)

	概要：ロールピッチヨー[deg]から先端姿勢の回転行列を求める

	引数：
　　　　　　　double eerot[]・・・計算した行列を格納する配列
								 |0 1 2|
								 |3 4 5|
								 |6 7 8|
			 double roll・・・ロール回転角度
			 double pitch・・・ピッチ回転角度
			 double yaw・・・ヨー回転角度

	戻り値：なし

*************************************************/
void ViveSeedNoidController::TransRot(double eerot[], double roll, double pitch, double yaw)
{
	//ロールピッチヨー　ロボット工学（遠山茂樹著）p25
	double Rrotx;
	double Rroty;
	double Rrotz;
	Rrotx = roll * M_PI / 180;
	Rroty = pitch * M_PI / 180;
	Rrotz = yaw * M_PI / 180;
	//std::cout << "Rrtx = " << Rrotx << std::endl;
	//std::cout << "Rrty = " << Rroty << std::endl;
	//std::cout << "Rrtz = " << Rrotz << std::endl;
	eerot[0] = cos(Rroty)*cos(Rrotz);
	eerot[1] = cos(Rrotz)*sin(Rroty)*sin(Rrotx) - sin(Rrotz)*cos(Rrotx);
	eerot[2] = cos(Rrotz)*sin(Rroty)*cos(Rrotx) + sin(Rrotz)*sin(Rrotx);
	eerot[3] = sin(Rrotz)*cos(Rroty);
	eerot[4] = sin(Rrotz)*sin(Rroty)*sin(Rrotx) + cos(Rrotz)*cos(Rrotx);
	eerot[5] = sin(Rrotz)*sin(Rroty)*cos(Rrotx) - cos(Rrotz)*sin(Rrotx);
	eerot[6] = -sin(Rroty);
	eerot[7] = cos(Rroty)*sin(Rrotx);
	eerot[8] = cos(Rroty)*cos(Rrotx);
	//for(int j=0;j<9;j++){
	//    printf("eerot[%d] = %f\n",j,eerot[j]);
	//}

}


/************************************************

		Frame Solve_Rot(double eerot[]);

	概要：先端姿勢の回転行列から、ロールピッチヨー[deg]を求める

	引数：
　　　　　　　double eerot[]・・・姿勢行列を格納する配列
								 |0 1 2|
								 |3 4 5|
								 |6 7 8|

	戻り値：姿勢（ロールピッチヨー）

*************************************************/
Frame  ViveSeedNoidController::Solve_Rot(double eerot[])
{
	Frame rotation;
	double phi;//φ
	double theta;//θ
	double psi;//ψ

	for (int i = 0; i < 9; i++)
	{
		if (eerot[i] > 1)
			eerot[i] = 1;
		if (eerot[i] < -1)
			eerot[i] = -1;
	}

	psi = atan2(eerot[3], eerot[0]);
	theta = atan2(-eerot[6], sqrt(eerot[7] * eerot[7] + eerot[8] * eerot[8]));
	phi = atan2(eerot[7], eerot[8]);

	//phi = atan2(eerot[3], eerot[0]);
	//theta =  asin(-eerot[6]);
	//psi = atan2(eerot[7], eerot[8]);  

	rotation.roll = phi * 180 / M_PI;
	rotation.pitch = theta * 180 / M_PI;
	rotation.yaw = psi * 180 / M_PI;

	return rotation;
}


extern "C"
{
 
  void ViveSeedNoidControllerInit(RTC::Manager* manager)
  {
    coil::Properties profile(viveseednoidcontroller_spec);
    manager->registerFactory(profile,
                             RTC::Create<ViveSeedNoidController>,
                             RTC::Delete<ViveSeedNoidController>);
  }
  
};


