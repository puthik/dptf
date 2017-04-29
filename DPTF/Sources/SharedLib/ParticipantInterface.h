/******************************************************************************
** Copyright (c) 2013-2017 Intel Corporation All Rights Reserved
**
** Licensed under the Apache License, Version 2.0 (the "License"); you may not
** use this file except in compliance with the License.
**
** You may obtain a copy of the License at
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
** WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**
** See the License for the specific language governing permissions and
** limitations under the License.
**
******************************************************************************/

#pragma once

#include "Dptf.h"
#include "ParticipantServicesInterface.h"
#include "DomainActiveControlInterface.h"
#include "DomainActivityStatusInterface.h"
#include "DomainConfigTdpControlInterface.h"
#include "DomainCoreControlInterface.h"
#include "DomainDisplayControlInterface.h"
#include "DomainPeakPowerControlInterface.h"
#include "DomainPerformanceControlInterface.h"
#include "DomainPowerControlInterface.h"
#include "DomainPowerStatusInterface.h"
#include "DomainPriorityInterface.h"
#include "DomainRfProfileControlInterface.h"
#include "DomainRfProfileStatusInterface.h"
#include "DomainTemperatureInterface.h"
#include "DomainTccOffsetControlInterface.h"
#include "DomainUtilizationInterface.h"
#include "ParticipantGetSpecificInfoInterface.h"
#include "ParticipantPropertiesInterface.h"
#include "ParticipantSetSpecificInfoInterface.h"
#include "DomainPlatformPowerControlInterface.h"
#include "DomainPlatformPowerStatusInterface.h"

class XmlNode;

class ParticipantInterface : public DomainActiveControlInterface,
							 public DomainActivityStatusInterface,
							 public DomainConfigTdpControlInterface,
							 public DomainCoreControlInterface,
							 public DomainDisplayControlInterface,
							 public DomainPeakPowerControlInterface,
							 public DomainPerformanceControlInterface,
							 public DomainPowerControlInterface,
							 public DomainPowerStatusInterface,
							 public DomainPlatformPowerControlInterface,
							 public DomainPlatformPowerStatusInterface,
							 public DomainPriorityInterface,
							 public DomainRfProfileControlInterface,
							 public DomainRfProfileStatusInterface,
							 public DomainTemperatureInterface,
							 public DomainTccOffsetControlInterface,
							 public DomainUtilizationInterface,
							 public ParticipantGetSpecificInfoInterface,
							 public ParticipantPropertiesInterface,
							 public ParticipantSetSpecificInfoInterface
{
public:
	virtual ~ParticipantInterface(){};

	// Participant
	virtual void createParticipant(
		const Guid& guid,
		UIntN participantIndex,
		Bool enabled,
		const std::string& name,
		const std::string& description,
		BusType::Type busType,
		const PciInfo& pciInfo,
		const AcpiInfo& acpiInfo,
		std::shared_ptr<ParticipantServicesInterface> participantServicesInterface) = 0;
	virtual void destroyParticipant(void) = 0;
	virtual void enableParticipant(void) = 0;
	virtual void disableParticipant(void) = 0;
	virtual Bool isParticipantEnabled(void) = 0;

	// Domain
	virtual void createDomain(
		const Guid& guid,
		UIntN participantIndex,
		UIntN domainIndex,
		Bool enabled,
		DomainType::Type domainType,
		const std::string& name,
		const std::string& description,
		DomainFunctionalityVersions domainFunctionalityVersions) = 0;
	virtual void destroyDomain(const Guid& guid) = 0;
	virtual void enableDomain(UIntN domainIndex) = 0;
	virtual void disableDomain(UIntN domainIndex) = 0;
	virtual Bool isDomainEnabled(UIntN domainIndex) = 0;

	// Misc
	virtual std::string getName(void) const = 0;
	virtual std::shared_ptr<XmlNode> getXml(UIntN domainIndex) const = 0;
	virtual std::shared_ptr<XmlNode> getStatusAsXml(UIntN domainIndex) const = 0;

	// Event handlers
	virtual void connectedStandbyEntry(void) = 0;
	virtual void connectedStandbyExit(void) = 0;
	virtual void suspend(void) = 0;
	virtual void resume(void) = 0;
	virtual void activityLoggingEnabled(UInt32 domainIndex, UInt32 capabilityBitMask) = 0;
	virtual void activityLoggingDisabled(UInt32 domainIndex, UInt32 capabilityBitMask) = 0;
	virtual void domainConfigTdpCapabilityChanged(void) = 0;
	virtual void domainCoreControlCapabilityChanged(void) = 0;
	virtual void domainDisplayControlCapabilityChanged(void) = 0;
	virtual void domainDisplayStatusChanged(void) = 0;
	virtual void domainPerformanceControlCapabilityChanged(void) = 0;
	virtual void domainPerformanceControlsChanged(void) = 0;
	virtual void domainPowerControlCapabilityChanged(void) = 0;
	virtual void domainPriorityChanged(void) = 0;
	virtual void domainRadioConnectionStatusChanged(RadioConnectionStatus::Type radioConnectionStatus) = 0;
	virtual void domainRfProfileChanged(void) = 0;
	virtual void domainTemperatureThresholdCrossed(void) = 0;
	virtual void participantSpecificInfoChanged(void) = 0;
	virtual void domainVirtualSensorCalibrationTableChanged(void) = 0;
	virtual void domainVirtualSensorPollingTableChanged(void) = 0;
	virtual void domainVirtualSensorRecalcChanged(void) = 0;
	virtual void domainBatteryStatusChanged(void) = 0;
	virtual void domainBatteryInformationChanged(void) = 0;
	virtual void domainPlatformPowerSourceChanged(void) = 0;
	virtual void domainAdapterPowerRatingChanged(void) = 0;
	virtual void domainChargerTypeChanged(void) = 0;
	virtual void domainPlatformRestOfPowerChanged(void) = 0;
	virtual void domainMaxBatteryPowerChanged(void) = 0;
	virtual void domainPlatformBatterySteadyStateChanged(void) = 0;
	virtual void domainACNominalVoltageChanged(void) = 0;
	virtual void domainACOperationalCurrentChanged(void) = 0;
	virtual void domainAC1msPercentageOverloadChanged(void) = 0;
	virtual void domainAC2msPercentageOverloadChanged(void) = 0;
	virtual void domainAC10msPercentageOverloadChanged(void) = 0;
	virtual void domainEnergyThresholdCrossed(void) = 0;
};

//
// To make it easy to switch from static to dynamic linking, we will expose the following as
// "C" functions like we do in the policies.  It may be that we statically link the participant code
// since there is only one participant and we know the entry point.  But, we can easily change it later
// if needed since the functions are already in place.
//
extern "C" {
typedef ParticipantInterface* (*CreateParticipantInstanceFuncPtr)(void);
ParticipantInterface* CreateParticipantInstance(void);

typedef void (*DestroyParticipantInstanceFuncPtr)(ParticipantInterface* participantInterface);
void DestroyParticipantInstance(ParticipantInterface* participantInterface);
}
