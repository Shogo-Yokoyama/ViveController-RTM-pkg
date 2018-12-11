// -*- C++ -*-
/*!
 * @file  ViveToVelocity.cpp
 * @brief converter from VIVE data to velocity
 * @date $Date$
 *
 * $Id$
 */

#include "ViveToVelocity.h"

// Module specification
// <rtc-template block="module_spec">
static const char* vivetovelocity_spec[] =
  {
    "implementation_id", "ViveToVelocity",
    "type_name",         "ViveToVelocity",
    "description",       "converter from VIVE data to velocity",
    "version",           "1.0.0",
    "vendor",            "rsdlab",
    "category",          "data converter",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.debug", "0",
    "conf.default.gainX", "0.1",
    "conf.default.gainYaw", "1",
    "conf.default.controllerIndex", "0",
    "conf.default.operationMode", "0",

    // Widget
    "conf.__widget__.debug", "text",
    "conf.__widget__.gainX", "text",
    "conf.__widget__.gainYaw", "text",
    "conf.__widget__.controllerIndex", "text",
    "conf.__widget__.operationMode", "text",
    // Constraints

    "conf.__type__.debug", "int",
    "conf.__type__.gainX", "double",
    "conf.__type__.gainYaw", "double",
    "conf.__type__.controllerIndex", "int",
    "conf.__type__.operationMode", "int",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ViveToVelocity::ViveToVelocity(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_controllerIn("Controller", m_controller),
    m_velocityOut("Velocity", m_velocity)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ViveToVelocity::~ViveToVelocity()
{
}



RTC::ReturnCode_t ViveToVelocity::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("Controller", m_controllerIn);
  
  // Set OutPort buffer
  addOutPort("Velocity", m_velocityOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("debug", m_debug, "0");
  bindParameter("gainX", m_gainX, "0.1");
  bindParameter("gainYaw", m_gainYaw, "1");
  bindParameter("controllerIndex", m_controllerIndex, "0");
  bindParameter("operationMode", m_operationMode, "0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ViveToVelocity::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveToVelocity::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveToVelocity::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ViveToVelocity::onActivated(RTC::UniqueId ec_id)
{
	m_initPosFlag = true;

	m_velocity.data.vx = 0.0;
	m_velocity.data.vy = 0.0;
	m_velocity.data.va = 0.0;
	m_velocityOut.write();
  
	return RTC::RTC_OK;
}


RTC::ReturnCode_t ViveToVelocity::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ViveToVelocity::onExecute(RTC::UniqueId ec_id)
{
	if (m_controllerIn.isNew())
	{
		m_controllerIn.read();

		// 使用するコントローラが利用可能かどうか
		if (m_controller.deviceNum >= m_controllerIndex)
		{
			std::cout << "Controller Disconnect" << std::endl;
		}
		else
		{
			getVelocity();
			m_velocityOut.write();

			if (m_debug)
			{
				printf_s("VeloY : %.3f[m/s]    VeloYaw : %.3f[rad/s]\n", m_velocity.data.vx, m_velocity.data.va);
			}
		}
	}
  
	return RTC::RTC_OK;
}

void ViveToVelocity::getVelocity()
{
	if (m_operationMode == 0)
	{
		m_velocity.data.vx = m_gainX * m_controller.data[m_controllerIndex].pady;
		m_velocity.data.vy = 0.0;
		m_velocity.data.va = m_gainYaw * -m_controller.data[m_controllerIndex].padx;
	}
	else
	{
		if (m_initPosFlag)
		{
			m_initPosFlag = false;
			m_initVeloX = m_controller.data[m_controllerIndex].controllerPoseVel.pose.position.x;
			m_initVeloY = m_controller.data[m_controllerIndex].controllerPoseVel.pose.position.y;
			m_initVeloZ = m_controller.data[m_controllerIndex].controllerPoseVel.pose.position.z;
		}

		//直進速度の設定
		if (m_initVeloY - m_controller.data[m_controllerIndex].controllerPoseVel.pose.position.y > 0.3)
		{
			std::cout << "Back" << std::endl;
			m_velocity.data.vx = -0.5;
		}
		else if (m_initVeloZ - m_controller.data[m_controllerIndex].controllerPoseVel.pose.position.z >0.3)
		{
			std::cout << "Go ahead" << std::endl;
			m_velocity.data.vx = 0.5;
		}
		else
		{
			std::cout << "No Operation" << std::endl;
			m_velocity.data.vx = 0.0;
		}

		//回転角速度の設定
		if (-m_initVeloX + m_controller.data[m_controllerIndex].controllerPoseVel.pose.position.x > 0.3)
		{
			std::cout << "Turn Right" << std::endl;
			m_velocity.data.va = -1.0;
		}
		else if (-m_initVeloX + m_controller.data[m_controllerIndex].controllerPoseVel.pose.position.x < -0.3)
		{
			std::cout << "Turn Left" << std::endl;
			m_velocity.data.va = 1.0;
		}
		else
		{
			m_velocity.data.va = 0.0;
		}

		m_velocity.data.vy = 0.0;
	}
}

/*
RTC::ReturnCode_t ViveToVelocity::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveToVelocity::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveToVelocity::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveToVelocity::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveToVelocity::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ViveToVelocityInit(RTC::Manager* manager)
  {
    coil::Properties profile(vivetovelocity_spec);
    manager->registerFactory(profile,
                             RTC::Create<ViveToVelocity>,
                             RTC::Delete<ViveToVelocity>);
  }
  
};


