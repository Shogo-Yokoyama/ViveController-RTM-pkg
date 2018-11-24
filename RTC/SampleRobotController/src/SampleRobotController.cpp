// -*- C++ -*-
/*!
 * @file  SampleRobotController.cpp
 * @brief SampleRobotController
 * @date $Date$
 *
 * $Id$
 */

#include "SampleRobotController.h"

// Module specification
// <rtc-template block="module_spec">
static const char* samplerobotcontroller_spec[] =
  {
    "implementation_id", "SampleRobotController",
    "type_name",         "SampleRobotController",
    "description",       "SampleRobotController",
    "version",           "1.0.0",
    "vendor",            "rsdlab",
    "category",          "robot controller used to vr componen",
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
SampleRobotController::SampleRobotController(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_controllerIn("Controller", m_controller),
    m_hmdIn("Hmd", m_hmd),
    m_trackerIn("Tracker", m_tracker)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SampleRobotController::~SampleRobotController()
{
}



RTC::ReturnCode_t SampleRobotController::onInitialize()
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
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SampleRobotController::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleRobotController::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleRobotController::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SampleRobotController::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SampleRobotController::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SampleRobotController::onExecute(RTC::UniqueId ec_id)
{
	system("cls");

	if (m_hmdIn.isNew())
	{
		m_hmdIn.read();

		for (int i = 0; i < m_hmd.data.length(); i++)
		{
			printf_s("HMD%d        | posx:%.2f   posy:%.2f   posz:%.2f \n"
				, i
				, m_hmd.data[i].pose.position.x
				, m_hmd.data[i].pose.position.y
				, m_hmd.data[i].pose.position.z);
		}
	}
	if (m_controllerIn.isNew())
	{
		m_controllerIn.read();

		for (int i = 0; i < m_hmd.data.length(); i++)
		{
			printf_s("Controller%d | posx:%.2f   posy:%.2f   posz:%.2f \n"
				, i
				, m_controller.data[i].controllerPoseVel.pose.position.x
				, m_controller.data[i].controllerPoseVel.pose.position.y
				, m_controller.data[i].controllerPoseVel.pose.position.z);
		}
	}
	if (m_trackerIn.isNew())
	{
		m_trackerIn.read();

		for (int i = 0; i < m_tracker.data.length(); i++)
		{
			printf_s("Tracker%d    | posx:%.2f   posy:%.2f   posz:%.2f \n"
				, i
				, m_tracker.data[i].pose.position.x
				, m_tracker.data[i].pose.position.y
				, m_tracker.data[i].pose.position.z);
		}
	}

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SampleRobotController::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleRobotController::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleRobotController::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleRobotController::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleRobotController::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SampleRobotControllerInit(RTC::Manager* manager)
  {
    coil::Properties profile(samplerobotcontroller_spec);
    manager->registerFactory(profile,
                             RTC::Create<SampleRobotController>,
                             RTC::Delete<SampleRobotController>);
  }
  
};


