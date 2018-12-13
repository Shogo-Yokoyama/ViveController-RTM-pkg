// -*- C++ -*-
/*!
 * @file  ViveSeedNoidControllerTest.h
 * @brief SEED-Noid's upper body controller with HTC VIVE
 * @date  $Date$
 *
 * $Id$
 */

#ifndef VIVESEEDNOIDCONTROLLER_TEST__H
#define VIVESEEDNOIDCONTROLLER_TEST_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">
#include "ManipulatorCommonInterface_CommonSVC_impl.h"
#include "ManipulatorCommonInterface_MiddleLevelSVC_impl.h"
#include "LeftManipulatorCommonInterface_CommonSVC_impl.h"
#include "LeftManipulatorCommonInterface_MiddleLevelSVC_impl.h"
#include "WaistNeckInterfaceSVC_impl.h"
#include "SeedNoid_LifterSVC_impl.h"
#include "SeedUpperBodyKinematicsSVC_impl.h"
#include "VIVESVC_impl.h"

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="port_stub_h">
using namespace ViveControl;
// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

using namespace RTC;

/*!
 * @class ViveSeedNoidControllerTest
 * @brief SEED-Noid's upper body controller with HTC VIVE
 *
 */
class ViveSeedNoidControllerTest
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  ViveSeedNoidControllerTest(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~ViveSeedNoidControllerTest();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   * formaer rtc_init_entry() 
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   * former rtc_stopping_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /***
   *
   * The activated action (Active state entry action)
   * former rtc_active_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   *
   * The deactivated action (Active state exit action)
   * former rtc_active_exit()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   *
   * The execution action that is invoked periodically
   * former rtc_active_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   * former rtc_aborting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   * former rtc_error_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   * This is same but different the former rtc_init_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  ViveControl::TimedViveControllerSeq m_controller;
  /*!
   */
  OutPort<ViveControl::TimedViveControllerSeq> m_controllerOut;
  ViveControl::TimedVivePoseVelSeq m_hmd;
  /*!
   */
  OutPort<ViveControl::TimedVivePoseVelSeq> m_hmdOut;
  ViveControl::TimedVivePoseVelSeq m_tracker;
  /*!
   */
  OutPort<ViveControl::TimedVivePoseVelSeq> m_trackerOut;
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  /*!
   */
  RTC::CorbaPort m_RightManipulatorCommonInterface_CommonPort;
  /*!
   */
  RTC::CorbaPort m_RightManipulatorCommonInterface_MiddlePort;
  /*!
   */
  RTC::CorbaPort m_LeftManipulatorCommonInterface_CommonPort;
  /*!
   */
  RTC::CorbaPort m_LeftManipulatorCommonInterface_MiddlePort;
  /*!
   */
  RTC::CorbaPort m_WaistInterfacePort;
  /*!
   */
  RTC::CorbaPort m_NeckInterfacePort;
  /*!
   */
  RTC::CorbaPort m_LifterPosePort;
  /*!
   */
  RTC::CorbaPort m_RightArmKinematicsInterfacePort;
  /*!
   */
  RTC::CorbaPort m_LeftArmKinematicsInterfacePort;
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  /*!
   */
  ManipulatorCommonInterface_CommonSVC_impl m_ManipulatorCommonInterface_Common;
  /*!
   */
  ManipulatorCommonInterface_MiddleSVC_impl m_ManipulatorCommonInterface_Middle;
  /*!
   */
  LeftManipulatorCommonInterface_CommonSVC_impl m_LeftManipulatorCommonInterface_Common;
  /*!
   */
  LeftManipulatorCommonInterface_MiddleSVC_impl m_LeftManipulatorCommonInterface_Middle;
  /*!
   */
  WaistInterfaceSVC_impl m_WaistInterface;
  /*!
   */
  NeckInterfaceSVC_impl m_NeckInterface;
  /*!
   */
  LifterPoseInterfaceSVC_impl m_lifter;
  /*!
   */
  RightArmKinematicsInterfaceSVC_impl m_RightArmKinematicsInterface;
  /*!
   */
  LeftArmKinematicsInterfaceSVC_impl m_LeftArmKinematicsInterface;
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

};


extern "C"
{
  DLL_EXPORT void ViveSeedNoidControllerTestInit(RTC::Manager* manager);
};

#endif // VIVESEEDNOIDCONTROLLER_TEST_H
