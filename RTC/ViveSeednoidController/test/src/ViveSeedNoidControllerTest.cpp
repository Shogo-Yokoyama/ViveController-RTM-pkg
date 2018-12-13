// -*- C++ -*-
/*!
 * @file  ViveSeedNoidControllerTest.cpp
 * @brief SEED-Noid's upper body controller with HTC VIVE
 * @date $Date$
 *
 * $Id$
 */

#include "ViveSeedNoidControllerTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* viveseednoidcontroller_spec[] =
  {
    "implementation_id", "ViveSeedNoidControllerTest",
    "type_name",         "ViveSeedNoidControllerTest",
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
ViveSeedNoidControllerTest::ViveSeedNoidControllerTest(RTC::Manager* manager)
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
ViveSeedNoidControllerTest::~ViveSeedNoidControllerTest()
{
}



RTC::ReturnCode_t ViveSeedNoidControllerTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("Controller", m_controllerOut);
  addOutPort("Hmd", m_hmdOut);
  addOutPort("Tracker", m_trackerOut);
  
  // Set service provider to Ports
  m_RightManipulatorCommonInterface_CommonPort.registerProvider("ManipulatorCommonInterface_Common", "JARA_ARM::ManipulatorCommonInterface_Common", m_ManipulatorCommonInterface_Common);
  m_RightManipulatorCommonInterface_MiddlePort.registerProvider("ManipulatorCommonInterface_Middle", "JARA_ARM::ManipulatorCommonInterface_Middle", m_ManipulatorCommonInterface_Middle);
  m_LeftManipulatorCommonInterface_CommonPort.registerProvider("LeftManipulatorCommonInterface_Common", "JARA_ARM_LEFT::LeftManipulatorCommonInterface_Common", m_LeftManipulatorCommonInterface_Common);
  m_LeftManipulatorCommonInterface_MiddlePort.registerProvider("LeftManipulatorCommonInterface_Middle", "JARA_ARM_LEFT::LeftManipulatorCommonInterface_Middle", m_LeftManipulatorCommonInterface_Middle);
  m_WaistInterfacePort.registerProvider("WaistInterface", "WaistNeck::WaistInterface", m_WaistInterface);
  m_NeckInterfacePort.registerProvider("NeckInterface", "WaistNeck::NeckInterface", m_NeckInterface);
  m_LifterPosePort.registerProvider("lifter", "SeedNoid_Lifter::LifterPoseInterface", m_lifter);
  m_RightArmKinematicsInterfacePort.registerProvider("RightArmKinematicsInterface", "IK_RTC::RightArmKinematicsInterface", m_RightArmKinematicsInterface);
  m_LeftArmKinematicsInterfacePort.registerProvider("LeftArmKinematicsInterface", "IK_RTC::LeftArmKinematicsInterface", m_LeftArmKinematicsInterface);
  
  // Set service consumers to Ports
  
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
RTC::ReturnCode_t ViveSeedNoidControllerTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveSeedNoidControllerTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveSeedNoidControllerTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ViveSeedNoidControllerTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ViveSeedNoidControllerTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ViveSeedNoidControllerTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ViveSeedNoidControllerTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveSeedNoidControllerTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveSeedNoidControllerTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveSeedNoidControllerTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ViveSeedNoidControllerTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ViveSeedNoidControllerTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(viveseednoidcontroller_spec);
    manager->registerFactory(profile,
                             RTC::Create<ViveSeedNoidControllerTest>,
                             RTC::Delete<ViveSeedNoidControllerTest>);
  }
  
};


