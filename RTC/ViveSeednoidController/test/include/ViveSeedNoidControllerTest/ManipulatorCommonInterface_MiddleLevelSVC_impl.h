// -*-C++-*-
/*!
 * @file  ManipulatorCommonInterface_MiddleLevelSVC_impl.h
 * @brief Service implementation header of ManipulatorCommonInterface_MiddleLevel.idl
 *
 */

#include "ManipulatorCommonInterface_DataTypesSkel.h"
#include "BasicDataTypeSkel.h"

#include "ManipulatorCommonInterface_MiddleLevelSkel.h"

#ifndef MANIPULATORCOMMONINTERFACE_MIDDLELEVELSVC_IMPL_H
#define MANIPULATORCOMMONINTERFACE_MIDDLELEVELSVC_IMPL_H
 
/*!
 * @class JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl
 * Example class implementing IDL interface JARA_ARM::ManipulatorCommonInterface_Middle
 */
class JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl
 : public virtual POA_JARA_ARM::ManipulatorCommonInterface_Middle,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl();

   // attributes and operations
   JARA_ARM::RETURN_ID closeGripper();
   JARA_ARM::RETURN_ID getBaseOffset(JARA_ARM::HgMatrix offset);
   JARA_ARM::RETURN_ID getFeedbackPosCartesian(JARA_ARM::CarPosWithElbow& pos);
   JARA_ARM::RETURN_ID getMaxSpeedCartesian(JARA_ARM::CartesianSpeed& speed);
   JARA_ARM::RETURN_ID getMaxSpeedJoint(JARA_ARM::DoubleSeq_out speed);
   JARA_ARM::RETURN_ID getMinAccelTimeCartesian(::CORBA::Double& aclTime);
   JARA_ARM::RETURN_ID getMinAccelTimeJoint(::CORBA::Double& aclTime);
   JARA_ARM::RETURN_ID getSoftLimitCartesian(JARA_ARM::LimitValue& xLimit, JARA_ARM::LimitValue& yLimit, JARA_ARM::LimitValue& zLimit);
   JARA_ARM::RETURN_ID moveGripper(JARA_ARM::ULONG angleRatio);
   JARA_ARM::RETURN_ID moveLinearCartesianAbs(const JARA_ARM::CarPosWithElbow& carPoint);
   JARA_ARM::RETURN_ID moveLinearCartesianRel(const JARA_ARM::CarPosWithElbow& carPoint);
   JARA_ARM::RETURN_ID movePTPCartesianAbs(const JARA_ARM::CarPosWithElbow& carPoint);
   JARA_ARM::RETURN_ID movePTPCartesianRel(const JARA_ARM::CarPosWithElbow& carPoint);
   JARA_ARM::RETURN_ID movePTPJointAbs(const JARA_ARM::JointPos& jointPoints);
   JARA_ARM::RETURN_ID movePTPJointRel(const JARA_ARM::JointPos& jointPoints);
   JARA_ARM::RETURN_ID openGripper();
   JARA_ARM::RETURN_ID pause();
   JARA_ARM::RETURN_ID resume();
   JARA_ARM::RETURN_ID stop();
   JARA_ARM::RETURN_ID setAccelTimeCartesian(::CORBA::Double aclTime);
   JARA_ARM::RETURN_ID setAccelTimeJoint(::CORBA::Double aclTime);
   JARA_ARM::RETURN_ID setBaseOffset(const JARA_ARM::HgMatrix offset);
   JARA_ARM::RETURN_ID setControlPointOffset(const JARA_ARM::HgMatrix offset);
   JARA_ARM::RETURN_ID setMaxSpeedCartesian(const JARA_ARM::CartesianSpeed& speed);
   JARA_ARM::RETURN_ID setMaxSpeedJoint(const JARA_ARM::DoubleSeq& speed);
   JARA_ARM::RETURN_ID setMinAccelTimeCartesian(::CORBA::Double aclTime);
   JARA_ARM::RETURN_ID setMinAccelTimeJoint(::CORBA::Double aclTime);
   JARA_ARM::RETURN_ID setSoftLimitCartesian(const JARA_ARM::LimitValue& xLimit, const JARA_ARM::LimitValue& yLimit, const JARA_ARM::LimitValue& zLimit);
   JARA_ARM::RETURN_ID setSpeedCartesian(JARA_ARM::ULONG spdRatio);
   JARA_ARM::RETURN_ID setSpeedJoint(JARA_ARM::ULONG spdRatio);
   JARA_ARM::RETURN_ID moveCircularCartesianAbs(const JARA_ARM::CarPosWithElbow& carPointR, const JARA_ARM::CarPosWithElbow& carPointT);
   JARA_ARM::RETURN_ID moveCircularCartesianRel(const JARA_ARM::CarPosWithElbow& carPointR, const JARA_ARM::CarPosWithElbow& carPointT);
   JARA_ARM::RETURN_ID setHome(const JARA_ARM::JointPos& jointPoint);
   JARA_ARM::RETURN_ID getHome(JARA_ARM::JointPos_out jointPoint);
   JARA_ARM::RETURN_ID goHome();
   JARA_ARM::RETURN_ID getSpeedCartesian(JARA_ARM::ULONG& spdRatio);
   JARA_ARM::RETURN_ID getSpeedJoint(JARA_ARM::ULONG& spdRatio);
   JARA_ARM::RETURN_ID setGraspForce(JARA_ARM::ULONG forceRatio);
   JARA_ARM::RETURN_ID getGraspForce(JARA_ARM::ULONG& forceRatio);
   JARA_ARM::RETURN_ID moveLinearCartesianAbsCmdCycle(const JARA_ARM::CarPosWithElbow& carPoint);
   JARA_ARM::RETURN_ID moveLinearCartesianRelCmdCycle(const JARA_ARM::CarPosWithElbow& carPoint);
   JARA_ARM::RETURN_ID movePTPCartesianAbsCmdCycle(const JARA_ARM::CarPosWithElbow& carPoint);
   JARA_ARM::RETURN_ID movePTPCartesianRelCmdCycle(const JARA_ARM::CarPosWithElbow& carPoint);
   JARA_ARM::RETURN_ID movePTPJointAbsCmdCycle(const JARA_ARM::JointPos& jointPoints);
   JARA_ARM::RETURN_ID movePTPJointRelCmdCycle(const JARA_ARM::JointPos& jointPoints);

};



#endif // MANIPULATORCOMMONINTERFACE_MIDDLELEVELSVC_IMPL_H


