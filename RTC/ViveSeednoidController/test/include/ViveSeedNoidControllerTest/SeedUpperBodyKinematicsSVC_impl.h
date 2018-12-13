// -*-C++-*-
/*!
 * @file  SeedUpperBodyKinematicsSVC_impl.h
 * @brief Service implementation header of SeedUpperBodyKinematics.idl
 *
 */

#include "BasicDataTypeSkel.h"

#include "SeedUpperBodyKinematicsSkel.h"

#ifndef SEEDUPPERBODYKINEMATICSSVC_IMPL_H
#define SEEDUPPERBODYKINEMATICSSVC_IMPL_H
 
/*!
 * @class IK_RTC_RightArmKinematicsInterfaceSVC_impl
 * Example class implementing IDL interface IK_RTC::RightArmKinematicsInterface
 */
class IK_RTC_RightArmKinematicsInterfaceSVC_impl
 : public virtual POA_IK_RTC::RightArmKinematicsInterface,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~IK_RTC_RightArmKinematicsInterfaceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   IK_RTC_RightArmKinematicsInterfaceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~IK_RTC_RightArmKinematicsInterfaceSVC_impl();

   // attributes and operations
   IK_RTC::RETURN_ID* solveRightArmIkSetWaistJoint(const IK_RTC::Rotation& eerot, const IK_RTC::FramePos& eetrans, const IK_RTC::WaistFrame& WaistPos, const IK_RTC::JointPos& nowJointPos, IK_RTC::JointPos_out solRightJointPos);
   IK_RTC::RETURN_ID* solveRightArmIk(const IK_RTC::Rotation& eerot, const IK_RTC::FramePos& eetrans, const IK_RTC::JointPos& nowJointPos, IK_RTC::JointPos_out solRightJointPos);
   IK_RTC::RETURN_ID* solveRightArmFk(const IK_RTC::JointPos& RightJointPos, IK_RTC::Rotation_out eerot, IK_RTC::FramePos_out eetrans);

};

/*!
 * @class IK_RTC_LeftArmKinematicsInterfaceSVC_impl
 * Example class implementing IDL interface IK_RTC::LeftArmKinematicsInterface
 */
class IK_RTC_LeftArmKinematicsInterfaceSVC_impl
 : public virtual POA_IK_RTC::LeftArmKinematicsInterface,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~IK_RTC_LeftArmKinematicsInterfaceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   IK_RTC_LeftArmKinematicsInterfaceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~IK_RTC_LeftArmKinematicsInterfaceSVC_impl();

   // attributes and operations
   IK_RTC::RETURN_ID* solveLeftArmIkSetWaistJoint(const IK_RTC::Rotation& eerot, const IK_RTC::FramePos& eetrans, const IK_RTC::WaistFrame& WaistPos, const IK_RTC::JointPos& nowJointPos, IK_RTC::JointPos_out solLeftJointPos);
   IK_RTC::RETURN_ID* solveLeftArmIk(const IK_RTC::Rotation& eerot, const IK_RTC::FramePos& eetrans, const IK_RTC::JointPos& nowJointPos, IK_RTC::JointPos_out solLeftJointPos);
   IK_RTC::RETURN_ID* solveLeftArmFk(const IK_RTC::JointPos& LeftJointPos, IK_RTC::Rotation_out eerot, IK_RTC::FramePos_out eetrans);

};



#endif // SEEDUPPERBODYKINEMATICSSVC_IMPL_H


