// -*-C++-*-
/*!
 * @file  WaistNeckInterfaceSVC_impl.h
 * @brief Service implementation header of WaistNeckInterface.idl
 *
 */

#include "BasicDataTypeSkel.h"

#include "WaistNeckInterfaceSkel.h"

#ifndef WAISTNECKINTERFACESVC_IMPL_H
#define WAISTNECKINTERFACESVC_IMPL_H
 
/*!
 * @class WaistNeck_NeckInterfaceSVC_impl
 * Example class implementing IDL interface WaistNeck::NeckInterface
 */
class WaistNeck_NeckInterfaceSVC_impl
 : public virtual POA_WaistNeck::NeckInterface,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~WaistNeck_NeckInterfaceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   WaistNeck_NeckInterfaceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~WaistNeck_NeckInterfaceSVC_impl();

   // attributes and operations
   WaistNeck::RETURN_ID* getFeedbackPosNeck(WaistNeck::NeckPos_out pos);
   WaistNeck::RETURN_ID* getNeckInfo(WaistNeck::ManipInfo_out mInfo);
   WaistNeck::RETURN_ID* getSoftLimitNeck(WaistNeck::LimitSeq_out softLimit);
   WaistNeck::RETURN_ID* getState(WaistNeck::ULONG& state);
   WaistNeck::RETURN_ID* servoOFF();
   WaistNeck::RETURN_ID* servoON();
   WaistNeck::RETURN_ID* setSoftLimitNeck(const WaistNeck::LimitSeq& softLimit);
   WaistNeck::RETURN_ID* getMaxSpeedNeck(WaistNeck::DoubleSeq_out speed);
   WaistNeck::RETURN_ID* getMinAccelTimeNeck(::CORBA::Double& aclTime);
   WaistNeck::RETURN_ID* movePTPNeckAbs(const WaistNeck::NeckPos& neckPoints);
   WaistNeck::RETURN_ID* movePTPNeckRel(const WaistNeck::NeckPos& neckPoints);
   WaistNeck::RETURN_ID* pause();
   WaistNeck::RETURN_ID* resume();
   WaistNeck::RETURN_ID* stop();
   WaistNeck::RETURN_ID* setAccelTimeNeck(::CORBA::Double aclTime);
   WaistNeck::RETURN_ID* setMaxSpeedNeck(const WaistNeck::DoubleSeq& speed);
   WaistNeck::RETURN_ID* setMinAccelTimeNeck(::CORBA::Double aclTime);
   WaistNeck::RETURN_ID* setSpeedNeck(WaistNeck::ULONG spdRatio);
   WaistNeck::RETURN_ID* getSpeedNeck(WaistNeck::ULONG& spdRatio);
   WaistNeck::RETURN_ID* movePTPNeckAbsCmdCycle(const WaistNeck::NeckPos& neckPoints);
   WaistNeck::RETURN_ID* movePTPNeckRelCmdCycle(const WaistNeck::NeckPos& neckPoints);

};

/*!
 * @class WaistNeck_WaistInterfaceSVC_impl
 * Example class implementing IDL interface WaistNeck::WaistInterface
 */
class WaistNeck_WaistInterfaceSVC_impl
 : public virtual POA_WaistNeck::WaistInterface,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~WaistNeck_WaistInterfaceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   WaistNeck_WaistInterfaceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~WaistNeck_WaistInterfaceSVC_impl();

   // attributes and operations
   WaistNeck::RETURN_ID* getFeedbackPosWaist(WaistNeck::WaistPos_out pos);
   WaistNeck::RETURN_ID* getWaistInfo(WaistNeck::ManipInfo_out mInfo);
   WaistNeck::RETURN_ID* getSoftLimitWaist(WaistNeck::LimitSeq_out softLimit);
   WaistNeck::RETURN_ID* getState(WaistNeck::ULONG& state);
   WaistNeck::RETURN_ID* servoOFF();
   WaistNeck::RETURN_ID* servoON();
   WaistNeck::RETURN_ID* setSoftLimitWaist(const WaistNeck::LimitSeq& softLimit);
   WaistNeck::RETURN_ID* getMaxSpeedWaist(WaistNeck::DoubleSeq_out speed);
   WaistNeck::RETURN_ID* getMinAccelTimeWaist(::CORBA::Double& aclTime);
   WaistNeck::RETURN_ID* movePTPWaistAbs(const WaistNeck::WaistPos& waistPoints);
   WaistNeck::RETURN_ID* movePTPWaistRel(const WaistNeck::WaistPos& waistPoints);
   WaistNeck::RETURN_ID* pause();
   WaistNeck::RETURN_ID* resume();
   WaistNeck::RETURN_ID* stop();
   WaistNeck::RETURN_ID* setAccelTimeWaist(::CORBA::Double aclTime);
   WaistNeck::RETURN_ID* setMaxSpeedWaist(const WaistNeck::DoubleSeq& speed);
   WaistNeck::RETURN_ID* setMinAccelTimeWaist(::CORBA::Double aclTime);
   WaistNeck::RETURN_ID* setSpeedWaist(WaistNeck::ULONG spdRatio);
   WaistNeck::RETURN_ID* getSpeedWaist(WaistNeck::ULONG& spdRatio);
   WaistNeck::RETURN_ID* movePTPWaistAbsCmdCycle(const WaistNeck::WaistPos& waistPoints);
   WaistNeck::RETURN_ID* movePTPWaistRelCmdCycle(const WaistNeck::WaistPos& waistPoints);

};



#endif // WAISTNECKINTERFACESVC_IMPL_H


