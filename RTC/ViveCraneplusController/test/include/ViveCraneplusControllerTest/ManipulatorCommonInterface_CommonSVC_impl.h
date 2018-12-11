// -*-C++-*-
/*!
 * @file  ManipulatorCommonInterface_CommonSVC_impl.h
 * @brief Service implementation header of ManipulatorCommonInterface_Common.idl
 *
 */

#include "ManipulatorCommonInterface_DataTypesSkel.h"
#include "BasicDataTypeSkel.h"

#include "ManipulatorCommonInterface_CommonSkel.h"

#ifndef MANIPULATORCOMMONINTERFACE_COMMONSVC_IMPL_H
#define MANIPULATORCOMMONINTERFACE_COMMONSVC_IMPL_H
 
/*!
 * @class JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl
 * Example class implementing IDL interface JARA_ARM::ManipulatorCommonInterface_Common
 */
class JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl
 : public virtual POA_JARA_ARM::ManipulatorCommonInterface_Common,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl();

   // attributes and operations
   JARA_ARM::RETURN_ID clearAlarms();
   JARA_ARM::RETURN_ID getActiveAlarm(JARA_ARM::AlarmSeq_out alarms);
   JARA_ARM::RETURN_ID getFeedbackPosJoint(JARA_ARM::JointPos_out pos);
   JARA_ARM::RETURN_ID getManipInfo(JARA_ARM::ManipInfo_out mInfo);
   JARA_ARM::RETURN_ID getSoftLimitJoint(JARA_ARM::LimitSeq_out softLimit);
   JARA_ARM::RETURN_ID getState(JARA_ARM::ULONG& state);
   JARA_ARM::RETURN_ID servoOFF();
   JARA_ARM::RETURN_ID servoON();
   JARA_ARM::RETURN_ID setSoftLimitJoint(const JARA_ARM::LimitSeq& softLimit);

};



#endif // MANIPULATORCOMMONINTERFACE_COMMONSVC_IMPL_H


