// -*- C++ -*-
/*!
 * @file  ViveSeedNoidController.h
 * @brief SEED-Noid's upper body controller with HTC VIVE
 * @date  $Date$
 *
 * $Id$
 */

#ifndef VIVESEEDNOIDCONTROLLER_H
#define VIVESEEDNOIDCONTROLLER_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "ManipulatorCommonInterface_CommonStub.h"
#include "ManipulatorCommonInterface_MiddleLevelStub.h"
#include "LeftManipulatorCommonInterface_CommonStub.h"
#include "LeftManipulatorCommonInterface_MiddleLevelStub.h"
#include "WaistNeckInterfaceStub.h"
#include "SeedNoid_LifterStub.h"
#include "SeedUpperBodyKinematicsStub.h"
#include "VIVEStub.h"

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

#define _USE_MATH_DEFINES
#include <math.h>
#include <Windows.h>

//ロールピッチヨー
typedef struct
{
	double roll;
	double pitch;
	double yaw;
}Frame;

enum {
	GRIPPER_OPEN = 0,
	GRIPPER_CLOSE = 1,
};

typedef struct {
	double x;
	double y;
	double z;
}Pos;


using namespace RTC;

/*!
 * @class ViveSeedNoidController
 * @brief SEED-Noid's upper body controller with HTC VIVE
 *
 */
class ViveSeedNoidController
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  ViveSeedNoidController(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~ViveSeedNoidController();

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
  ViveControl::TimedViveControllerSeq m_controller;
  /*!
   */
  InPort<ViveControl::TimedViveControllerSeq> m_controllerIn;
  ViveControl::TimedVivePoseVelSeq m_hmd;
  /*!
   */
  InPort<ViveControl::TimedVivePoseVelSeq> m_hmdIn;
  ViveControl::TimedVivePoseVelSeq m_tracker;
  /*!
   */
  InPort<ViveControl::TimedVivePoseVelSeq> m_trackerIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  
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
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  /*!
   */
  RTC::CorbaConsumer<JARA_ARM::ManipulatorCommonInterface_Common> m_ManipulatorCommonInterface_Common;
  /*!
   */
  RTC::CorbaConsumer<JARA_ARM::ManipulatorCommonInterface_Middle> m_ManipulatorCommonInterface_Middle;
  /*!
   */
  RTC::CorbaConsumer<JARA_ARM_LEFT::LeftManipulatorCommonInterface_Common> m_LeftManipulatorCommonInterface_Common;
  /*!
   */
  RTC::CorbaConsumer<JARA_ARM_LEFT::LeftManipulatorCommonInterface_Middle> m_LeftManipulatorCommonInterface_Middle;
  /*!
   */
  RTC::CorbaConsumer<WaistNeck::WaistInterface> m_WaistInterface;
  /*!
   */
  RTC::CorbaConsumer<WaistNeck::NeckInterface> m_NeckInterface;
  /*!
   */
  RTC::CorbaConsumer<SeedNoid_Lifter::LifterPoseInterface> m_lifter;
  /*!
   */
  RTC::CorbaConsumer<IK_RTC::RightArmKinematicsInterface> m_RightArmKinematicsInterface;
  /*!
   */
  RTC::CorbaConsumer<IK_RTC::LeftArmKinematicsInterface> m_LeftArmKinematicsInterface;
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>
	 int controllerIndex;

	 void TransRot(double eerot[], double roll, double pitch, double yaw);
	 Frame Solve_Rot(double eerot[]);
	 IK_RTC::RETURN_ID_var m_rid_RIK;
	 IK_RTC::RETURN_ID_var m_rid_LIK;
	 JARA_ARM::RETURN_ID_var m_rid_right;
	 JARA_ARM_LEFT::RETURN_ID_var m_rid_left;
	 WaistNeck::RETURN_ID_var m_rid_neck;
	 WaistNeck::RETURN_ID_var m_rid_waist;

	 Pos defaultVivePos;
	 int getDefaultPosFlag;
	 int bfrGripperFlag;

	 void getDefaultVivePos();
	 int getTargetPos();
	 int initMove();
};


extern "C"
{
  DLL_EXPORT void ViveSeedNoidControllerInit(RTC::Manager* manager);
};

#endif // VIVESEEDNOIDCONTROLLER_H
