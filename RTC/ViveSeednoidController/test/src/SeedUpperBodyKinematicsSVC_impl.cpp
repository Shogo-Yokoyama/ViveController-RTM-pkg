// -*-C++-*-
/*!
 * @file  SeedUpperBodyKinematicsSVC_impl.cpp
 * @brief Service implementation code of SeedUpperBodyKinematics.idl
 *
 */

#include "SeedUpperBodyKinematicsSVC_impl.h"

/*
 * Example implementational code for IDL interface IK_RTC::RightArmKinematicsInterface
 */
IK_RTC_RightArmKinematicsInterfaceSVC_impl::IK_RTC_RightArmKinematicsInterfaceSVC_impl()
{
  // Please add extra constructor code here.
}


IK_RTC_RightArmKinematicsInterfaceSVC_impl::~IK_RTC_RightArmKinematicsInterfaceSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
IK_RTC::RETURN_ID* IK_RTC_RightArmKinematicsInterfaceSVC_impl::solveRightArmIkSetWaistJoint(const IK_RTC::Rotation& eerot, const IK_RTC::FramePos& eetrans, const IK_RTC::WaistFrame& WaistPos, const IK_RTC::JointPos& nowJointPos, IK_RTC::JointPos_out solRightJointPos)
{
	IK_RTC::RETURN_ID* result;
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <IK_RTC::RETURN_ID* IK_RTC_RightArmKinematicsInterfaceSVC_impl::solveRightArmIkSetWaistJoint(const IK_RTC::Rotation& eerot, const IK_RTC::FramePos& eetrans, const IK_RTC::WaistFrame& WaistPos, const IK_RTC::JointPos& nowJointPos, IK_RTC::JointPos_out solRightJointPos)>"
#endif
  return result;
}

IK_RTC::RETURN_ID* IK_RTC_RightArmKinematicsInterfaceSVC_impl::solveRightArmIk(const IK_RTC::Rotation& eerot, const IK_RTC::FramePos& eetrans, const IK_RTC::JointPos& nowJointPos, IK_RTC::JointPos_out solRightJointPos)
{
	IK_RTC::RETURN_ID* result;
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <IK_RTC::RETURN_ID* IK_RTC_RightArmKinematicsInterfaceSVC_impl::solveRightArmIk(const IK_RTC::Rotation& eerot, const IK_RTC::FramePos& eetrans, const IK_RTC::JointPos& nowJointPos, IK_RTC::JointPos_out solRightJointPos)>"
#endif
  return result;
}

IK_RTC::RETURN_ID* IK_RTC_RightArmKinematicsInterfaceSVC_impl::solveRightArmFk(const IK_RTC::JointPos& RightJointPos, IK_RTC::Rotation_out eerot, IK_RTC::FramePos_out eetrans)
{
	IK_RTC::RETURN_ID* result;
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <IK_RTC::RETURN_ID* IK_RTC_RightArmKinematicsInterfaceSVC_impl::solveRightArmFk(const IK_RTC::JointPos& RightJointPos, IK_RTC::Rotation_out eerot, IK_RTC::FramePos_out eetrans)>"
#endif
  return result;
}



// End of example implementational code

/*
 * Example implementational code for IDL interface IK_RTC::LeftArmKinematicsInterface
 */
IK_RTC_LeftArmKinematicsInterfaceSVC_impl::IK_RTC_LeftArmKinematicsInterfaceSVC_impl()
{
  // Please add extra constructor code here.
}


IK_RTC_LeftArmKinematicsInterfaceSVC_impl::~IK_RTC_LeftArmKinematicsInterfaceSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
IK_RTC::RETURN_ID* IK_RTC_LeftArmKinematicsInterfaceSVC_impl::solveLeftArmIkSetWaistJoint(const IK_RTC::Rotation& eerot, const IK_RTC::FramePos& eetrans, const IK_RTC::WaistFrame& WaistPos, const IK_RTC::JointPos& nowJointPos, IK_RTC::JointPos_out solLeftJointPos)
{
	IK_RTC::RETURN_ID* result;
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <IK_RTC::RETURN_ID* IK_RTC_LeftArmKinematicsInterfaceSVC_impl::solveLeftArmIkSetWaistJoint(const IK_RTC::Rotation& eerot, const IK_RTC::FramePos& eetrans, const IK_RTC::WaistFrame& WaistPos, const IK_RTC::JointPos& nowJointPos, IK_RTC::JointPos_out solLeftJointPos)>"
#endif
  return result;
}

IK_RTC::RETURN_ID* IK_RTC_LeftArmKinematicsInterfaceSVC_impl::solveLeftArmIk(const IK_RTC::Rotation& eerot, const IK_RTC::FramePos& eetrans, const IK_RTC::JointPos& nowJointPos, IK_RTC::JointPos_out solLeftJointPos)
{
	IK_RTC::RETURN_ID* result;
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <IK_RTC::RETURN_ID* IK_RTC_LeftArmKinematicsInterfaceSVC_impl::solveLeftArmIk(const IK_RTC::Rotation& eerot, const IK_RTC::FramePos& eetrans, const IK_RTC::JointPos& nowJointPos, IK_RTC::JointPos_out solLeftJointPos)>"
#endif
  return result;
}

IK_RTC::RETURN_ID* IK_RTC_LeftArmKinematicsInterfaceSVC_impl::solveLeftArmFk(const IK_RTC::JointPos& LeftJointPos, IK_RTC::Rotation_out eerot, IK_RTC::FramePos_out eetrans)
{
	IK_RTC::RETURN_ID* result;
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <IK_RTC::RETURN_ID* IK_RTC_LeftArmKinematicsInterfaceSVC_impl::solveLeftArmFk(const IK_RTC::JointPos& LeftJointPos, IK_RTC::Rotation_out eerot, IK_RTC::FramePos_out eetrans)>"
#endif
  return result;
}



// End of example implementational code



