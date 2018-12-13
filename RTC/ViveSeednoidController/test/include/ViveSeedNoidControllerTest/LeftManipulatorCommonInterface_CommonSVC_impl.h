// -*-C++-*-
/*!
 * @file  LeftManipulatorCommonInterface_CommonSVC_impl.h
 * @brief Service implementation header of LeftManipulatorCommonInterface_Common.idl
 *
 */

#include "LeftManipulatorCommonInterface_DataTypesSkel.h"
#include "BasicDataTypeSkel.h"

#include "LeftManipulatorCommonInterface_CommonSkel.h"

#ifndef LEFTMANIPULATORCOMMONINTERFACE_COMMONSVC_IMPL_H
#define LEFTMANIPULATORCOMMONINTERFACE_COMMONSVC_IMPL_H
 
/*!
 * @class JARA_ARM_LEFT_LeftManipulatorCommonInterface_CommonSVC_impl
 * Example class implementing IDL interface JARA_ARM_LEFT::LeftManipulatorCommonInterface_Common
 */
class JARA_ARM_LEFT_LeftManipulatorCommonInterface_CommonSVC_impl
 : public virtual POA_JARA_ARM_LEFT::LeftManipulatorCommonInterface_Common,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~JARA_ARM_LEFT_LeftManipulatorCommonInterface_CommonSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   JARA_ARM_LEFT_LeftManipulatorCommonInterface_CommonSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~JARA_ARM_LEFT_LeftManipulatorCommonInterface_CommonSVC_impl();

   // attributes and operations
   JARA_ARM_LEFT::RETURN_ID* clearAlarms();
   JARA_ARM_LEFT::RETURN_ID* getActiveAlarm(JARA_ARM_LEFT::AlarmSeq_out alarms);
   JARA_ARM_LEFT::RETURN_ID* getFeedbackPosJoint(JARA_ARM_LEFT::JointPos_out pos);
   JARA_ARM_LEFT::RETURN_ID* getManipInfo(JARA_ARM_LEFT::ManipInfo_out mInfo);
   JARA_ARM_LEFT::RETURN_ID* getSoftLimitJoint(JARA_ARM_LEFT::LimitSeq_out softLimit);
   JARA_ARM_LEFT::RETURN_ID* getState(JARA_ARM_LEFT::ULONG& state);
   JARA_ARM_LEFT::RETURN_ID* servoOFF();
   JARA_ARM_LEFT::RETURN_ID* servoON();
   JARA_ARM_LEFT::RETURN_ID* setSoftLimitJoint(const JARA_ARM_LEFT::LimitSeq& softLimit);

};



#endif // LEFTMANIPULATORCOMMONINTERFACE_COMMONSVC_IMPL_H


