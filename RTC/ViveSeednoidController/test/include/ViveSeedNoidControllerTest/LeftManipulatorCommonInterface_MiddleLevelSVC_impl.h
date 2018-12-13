// -*-C++-*-
/*!
 * @file  LeftManipulatorCommonInterface_MiddleLevelSVC_impl.h
 * @brief Service implementation header of LeftManipulatorCommonInterface_MiddleLevel.idl
 *
 */

#include "LeftManipulatorCommonInterface_DataTypesSkel.h"
#include "BasicDataTypeSkel.h"

#include "LeftManipulatorCommonInterface_MiddleLevelSkel.h"

#ifndef LEFTMANIPULATORCOMMONINTERFACE_MIDDLELEVELSVC_IMPL_H
#define LEFTMANIPULATORCOMMONINTERFACE_MIDDLELEVELSVC_IMPL_H
 
/*!
 * @class JARA_ARM_LEFT_LeftManipulatorCommonInterface_MiddleSVC_impl
 * Example class implementing IDL interface JARA_ARM_LEFT::LeftManipulatorCommonInterface_Middle
 */
class JARA_ARM_LEFT_LeftManipulatorCommonInterface_MiddleSVC_impl
 : public virtual POA_JARA_ARM_LEFT::LeftManipulatorCommonInterface_Middle,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~JARA_ARM_LEFT_LeftManipulatorCommonInterface_MiddleSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   JARA_ARM_LEFT_LeftManipulatorCommonInterface_MiddleSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~JARA_ARM_LEFT_LeftManipulatorCommonInterface_MiddleSVC_impl();

   // attributes and operations
   JARA_ARM_LEFT::RETURN_ID* closeGripper();
   JARA_ARM_LEFT::RETURN_ID* getBaseOffset(JARA_ARM_LEFT::HgMatrix offset);
   JARA_ARM_LEFT::RETURN_ID* getFeedbackPosCartesian(JARA_ARM_LEFT::CarPosWithElbow& pos);
   JARA_ARM_LEFT::RETURN_ID* getMaxSpeedCartesian(JARA_ARM_LEFT::CartesianSpeed& speed);
   JARA_ARM_LEFT::RETURN_ID* getMaxSpeedJoint(JARA_ARM_LEFT::DoubleSeq_out speed);
   JARA_ARM_LEFT::RETURN_ID* getMinAccelTimeCartesian(::CORBA::Double& aclTime);
   JARA_ARM_LEFT::RETURN_ID* getMinAccelTimeJoint(::CORBA::Double& aclTime);
   JARA_ARM_LEFT::RETURN_ID* getSoftLimitCartesian(JARA_ARM_LEFT::LimitValue& xLimit, JARA_ARM_LEFT::LimitValue& yLimit, JARA_ARM_LEFT::LimitValue& zLimit);
   JARA_ARM_LEFT::RETURN_ID* moveGripper(JARA_ARM_LEFT::ULONG angleRatio);
   JARA_ARM_LEFT::RETURN_ID* moveLinearCartesianAbs(const JARA_ARM_LEFT::CarPosWithElbow& carPoint);
   JARA_ARM_LEFT::RETURN_ID* moveLinearCartesianRel(const JARA_ARM_LEFT::CarPosWithElbow& carPoint);
   JARA_ARM_LEFT::RETURN_ID* movePTPCartesianAbs(const JARA_ARM_LEFT::CarPosWithElbow& carPoint);
   JARA_ARM_LEFT::RETURN_ID* movePTPCartesianRel(const JARA_ARM_LEFT::CarPosWithElbow& carPoint);
   JARA_ARM_LEFT::RETURN_ID* movePTPJointAbs(const JARA_ARM_LEFT::JointPos& jointPoints);
   JARA_ARM_LEFT::RETURN_ID* movePTPJointRel(const JARA_ARM_LEFT::JointPos& jointPoints);
   JARA_ARM_LEFT::RETURN_ID* openGripper();
   JARA_ARM_LEFT::RETURN_ID* pause();
   JARA_ARM_LEFT::RETURN_ID* resume();
   JARA_ARM_LEFT::RETURN_ID* stop();
   JARA_ARM_LEFT::RETURN_ID* setAccelTimeCartesian(::CORBA::Double aclTime);
   JARA_ARM_LEFT::RETURN_ID* setAccelTimeJoint(::CORBA::Double aclTime);
   JARA_ARM_LEFT::RETURN_ID* setBaseOffset(const JARA_ARM_LEFT::HgMatrix offset);
   JARA_ARM_LEFT::RETURN_ID* setControlPointOffset(const JARA_ARM_LEFT::HgMatrix offset);
   JARA_ARM_LEFT::RETURN_ID* setMaxSpeedCartesian(const JARA_ARM_LEFT::CartesianSpeed& speed);
   JARA_ARM_LEFT::RETURN_ID* setMaxSpeedJoint(const JARA_ARM_LEFT::DoubleSeq& speed);
   JARA_ARM_LEFT::RETURN_ID* setMinAccelTimeCartesian(::CORBA::Double aclTime);
   JARA_ARM_LEFT::RETURN_ID* setMinAccelTimeJoint(::CORBA::Double aclTime);
   JARA_ARM_LEFT::RETURN_ID* setSoftLimitCartesian(const JARA_ARM_LEFT::LimitValue& xLimit, const JARA_ARM_LEFT::LimitValue& yLimit, const JARA_ARM_LEFT::LimitValue& zLimit);
   JARA_ARM_LEFT::RETURN_ID* setSpeedCartesian(JARA_ARM_LEFT::ULONG spdRatio);
   JARA_ARM_LEFT::RETURN_ID* setSpeedJoint(JARA_ARM_LEFT::ULONG spdRatio);
   JARA_ARM_LEFT::RETURN_ID* moveCircularCartesianAbs(const JARA_ARM_LEFT::CarPosWithElbow& carPointR, const JARA_ARM_LEFT::CarPosWithElbow& carPointT);
   JARA_ARM_LEFT::RETURN_ID* moveCircularCartesianRel(const JARA_ARM_LEFT::CarPosWithElbow& carPointR, const JARA_ARM_LEFT::CarPosWithElbow& carPointT);
   JARA_ARM_LEFT::RETURN_ID* setHome(const JARA_ARM_LEFT::JointPos& jointPoint);
   JARA_ARM_LEFT::RETURN_ID* getHome(JARA_ARM_LEFT::JointPos_out jointPoint);
   JARA_ARM_LEFT::RETURN_ID* goHome();
   JARA_ARM_LEFT::RETURN_ID* getSpeedCartesian(JARA_ARM_LEFT::ULONG& spdRatio);
   JARA_ARM_LEFT::RETURN_ID* getSpeedJoint(JARA_ARM_LEFT::ULONG& spdRatio);
   JARA_ARM_LEFT::RETURN_ID* setGraspForce(JARA_ARM_LEFT::ULONG forceRatio);
   JARA_ARM_LEFT::RETURN_ID* getGraspForce(JARA_ARM_LEFT::ULONG& forceRatio);
   JARA_ARM_LEFT::RETURN_ID* moveLinearCartesianAbsCmdCycle(const JARA_ARM_LEFT::CarPosWithElbow& carPoint);
   JARA_ARM_LEFT::RETURN_ID* moveLinearCartesianRelCmdCycle(const JARA_ARM_LEFT::CarPosWithElbow& carPoint);
   JARA_ARM_LEFT::RETURN_ID* movePTPCartesianAbsCmdCycle(const JARA_ARM_LEFT::CarPosWithElbow& carPoint);
   JARA_ARM_LEFT::RETURN_ID* movePTPCartesianRelCmdCycle(const JARA_ARM_LEFT::CarPosWithElbow& carPoint);
   JARA_ARM_LEFT::RETURN_ID* movePTPJointAbsCmdCycle(const JARA_ARM_LEFT::JointPos& jointPoints);
   JARA_ARM_LEFT::RETURN_ID* movePTPJointRelCmdCycle(const JARA_ARM_LEFT::JointPos& jointPoints);

};



#endif // LEFTMANIPULATORCOMMONINTERFACE_MIDDLELEVELSVC_IMPL_H


