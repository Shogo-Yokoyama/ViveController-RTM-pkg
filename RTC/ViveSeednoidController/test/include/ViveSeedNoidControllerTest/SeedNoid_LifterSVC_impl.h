// -*-C++-*-
/*!
 * @file  SeedNoid_LifterSVC_impl.h
 * @brief Service implementation header of SeedNoid_Lifter.idl
 *
 */

#include "BasicDataTypeSkel.h"
#include "ExtendedDataTypesSkel.h"

#include "SeedNoid_LifterSkel.h"

#ifndef SEEDNOID_LIFTERSVC_IMPL_H
#define SEEDNOID_LIFTERSVC_IMPL_H
 
/*!
 * @class SeedNoid_Lifter_LifterPoseInterfaceSVC_impl
 * Example class implementing IDL interface SeedNoid_Lifter::LifterPoseInterface
 */
class SeedNoid_Lifter_LifterPoseInterfaceSVC_impl
 : public virtual POA_SeedNoid_Lifter::LifterPoseInterface,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~SeedNoid_Lifter_LifterPoseInterfaceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   SeedNoid_Lifter_LifterPoseInterfaceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~SeedNoid_Lifter_LifterPoseInterfaceSVC_impl();

   // attributes and operations
   SeedNoid_Lifter::RETURN_VALUE setLifterTime(::CORBA::Double MoveTime);
   SeedNoid_Lifter::RETURN_VALUE sendLifterAngle(const SeedNoid_Lifter::LifterAngle& targetLifterAngle);
   SeedNoid_Lifter::RETURN_VALUE sendLifterPose(const RTC::Point3D& targetLifterPose);
   SeedNoid_Lifter::RETURN_VALUE getLifterAngle(SeedNoid_Lifter::LifterAngle& currentLifterAngle);
   SeedNoid_Lifter::RETURN_VALUE getLifterPose(RTC::Point3D& currentLifterPose);
   SeedNoid_Lifter::RETURN_VALUE getSoftLimitLifter(SeedNoid_Lifter::LimitSeq_out softLimit);
   SeedNoid_Lifter::RETURN_VALUE setSoftLimitLifter(const SeedNoid_Lifter::LimitSeq& softLimit);
   SeedNoid_Lifter::RETURN_VALUE getMaxSpeedLifter(SeedNoid_Lifter::DoubleSeq_out speed);
   SeedNoid_Lifter::RETURN_VALUE getMinAccelTimeLifter(::CORBA::Double& aclTime);
   SeedNoid_Lifter::RETURN_VALUE pause();
   SeedNoid_Lifter::RETURN_VALUE resume();
   SeedNoid_Lifter::RETURN_VALUE stop();
   SeedNoid_Lifter::RETURN_VALUE setAccelTimeLifter(::CORBA::Double aclTime);
   SeedNoid_Lifter::RETURN_VALUE setMaxSpeedLifter(const SeedNoid_Lifter::DoubleSeq& speed);
   SeedNoid_Lifter::RETURN_VALUE setMinAccelTimeLifter(::CORBA::Double aclTime);
   SeedNoid_Lifter::RETURN_VALUE setSpeedLifter(SeedNoid_Lifter::ULONG spdRatio);
   SeedNoid_Lifter::RETURN_VALUE getSpeedLifter(SeedNoid_Lifter::ULONG& spdRatio);

};



#endif // SEEDNOID_LIFTERSVC_IMPL_H


