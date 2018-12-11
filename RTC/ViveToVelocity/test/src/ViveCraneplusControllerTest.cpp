// -*- C++ -*-
/*!
 * @file  ViveCraneplusControllerTest.cpp
 * @brief The controller of CRANE+ with HTC VIVE
 * @date $Date$
 *
 * $Id$
 */

#include "ViveCraneplusControllerTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* vivecranepluscontroller_spec[] =
  {
    "implementation_id", "ViveCraneplusControllerTest",
    "type_name",         "ViveCraneplusControllerTest",
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
ViveCraneplusControllerTest::ViveCraneplusControllerTest(RTC::Manager* manager)
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
ViveCraneplusControllerTest::~ViveCraneplusControllerTest()
{
}



RTC::ReturnCode_t ViveCraneplusControllerTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("Controller", m_controllerOut);
  
  // Set service provider to Ports
  m_ManipulatorCommonInterface_CommonPort.registerProvider("ManipulatorCommonInterface_Common", "JARA_ARM::ManipulatorCommonInterface_Common", m_ManipulatorCommonInterface_Common);
  m_ManipulatorCommonInterface_MiddlePort.registerProvider("ManipulatorCommonInterface_Middle", "JARA_ARM::ManipulatorCommonInterface_Middle", m_ManipulatorCommonInterface_Middle);
  
  // Set service consumers to Ports
  
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
RTC::ReturnCode_t ViveCraneplusControllerTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveCraneplusControllerTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveCraneplusControllerTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ViveCraneplusControllerTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ViveCraneplusControllerTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ViveCraneplusControllerTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ViveCraneplusControllerTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveCraneplusControllerTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveCraneplusControllerTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveCraneplusControllerTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveCraneplusControllerTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ViveCraneplusControllerTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(vivecranepluscontroller_spec);
    manager->registerFactory(profile,
                             RTC::Create<ViveCraneplusControllerTest>,
                             RTC::Delete<ViveCraneplusControllerTest>);
  }
  
};


