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

#include "PolicyServicesDomainPowerControl.h"
#include "ParticipantManagerInterface.h"

PolicyServicesDomainPowerControl::PolicyServicesDomainPowerControl(DptfManagerInterface* dptfManager, UIntN policyIndex)
	: PolicyServices(dptfManager, policyIndex)
{
}

PowerControlDynamicCapsSet PolicyServicesDomainPowerControl::getPowerControlDynamicCapsSet(
	UIntN participantIndex,
	UIntN domainIndex)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->getPowerControlDynamicCapsSet(domainIndex);
}

void PolicyServicesDomainPowerControl::setPowerControlDynamicCapsSet(
	UIntN participantIndex,
	UIntN domainIndex,
	PowerControlDynamicCapsSet capsSet)
{
	throwIfNotWorkItemThread();
	getParticipantManager()
		->getParticipantPtr(participantIndex)
		->setPowerControlDynamicCapsSet(domainIndex, getPolicyIndex(), capsSet);
}

Bool PolicyServicesDomainPowerControl::isPowerLimitEnabled(
	UIntN participantIndex,
	UIntN domainIndex,
	PowerControlType::Type controlType)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->isPowerLimitEnabled(domainIndex, controlType);
}

Power PolicyServicesDomainPowerControl::getPowerLimit(
	UIntN participantIndex,
	UIntN domainIndex,
	PowerControlType::Type controlType)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->getPowerLimit(domainIndex, controlType);
}

void PolicyServicesDomainPowerControl::setPowerLimit(
	UIntN participantIndex,
	UIntN domainIndex,
	PowerControlType::Type controlType,
	const Power& powerLimit)
{
	throwIfNotWorkItemThread();
	getParticipantManager()
		->getParticipantPtr(participantIndex)
		->setPowerLimit(domainIndex, getPolicyIndex(), controlType, powerLimit);
}

void PolicyServicesDomainPowerControl::setPowerLimitIgnoringCaps(
	UIntN participantIndex,
	UIntN domainIndex,
	PowerControlType::Type controlType,
	const Power& powerLimit)
{
	throwIfNotWorkItemThread();
	getParticipantManager()
		->getParticipantPtr(participantIndex)
		->setPowerLimitIgnoringCaps(domainIndex, getPolicyIndex(), controlType, powerLimit);
}

TimeSpan PolicyServicesDomainPowerControl::getPowerLimitTimeWindow(
	UIntN participantIndex,
	UIntN domainIndex,
	PowerControlType::Type controlType)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()
		->getParticipantPtr(participantIndex)
		->getPowerLimitTimeWindow(domainIndex, controlType);
}

void PolicyServicesDomainPowerControl::setPowerLimitTimeWindow(
	UIntN participantIndex,
	UIntN domainIndex,
	PowerControlType::Type controlType,
	const TimeSpan& timeWindow)
{
	throwIfNotWorkItemThread();
	getParticipantManager()
		->getParticipantPtr(participantIndex)
		->setPowerLimitTimeWindow(domainIndex, getPolicyIndex(), controlType, timeWindow);
}

void PolicyServicesDomainPowerControl::setPowerLimitTimeWindowIgnoringCaps(
	UIntN participantIndex,
	UIntN domainIndex,
	PowerControlType::Type controlType,
	const TimeSpan& timeWindow)
{
	throwIfNotWorkItemThread();
	getParticipantManager()
		->getParticipantPtr(participantIndex)
		->setPowerLimitTimeWindowIgnoringCaps(domainIndex, getPolicyIndex(), controlType, timeWindow);
}

Percentage PolicyServicesDomainPowerControl::getPowerLimitDutyCycle(
	UIntN participantIndex,
	UIntN domainIndex,
	PowerControlType::Type controlType)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()
		->getParticipantPtr(participantIndex)
		->getPowerLimitDutyCycle(domainIndex, controlType);
}

void PolicyServicesDomainPowerControl::setPowerLimitDutyCycle(
	UIntN participantIndex,
	UIntN domainIndex,
	PowerControlType::Type controlType,
	const Percentage& dutyCycle)
{
	throwIfNotWorkItemThread();
	getParticipantManager()
		->getParticipantPtr(participantIndex)
		->setPowerLimitDutyCycle(domainIndex, getPolicyIndex(), controlType, dutyCycle);
}

void PolicyServicesDomainPowerControl::setPowerCapsLock(UIntN participantIndex, UIntN domainIndex, Bool lock)
{
	throwIfNotWorkItemThread();
	getParticipantManager()->getParticipantPtr(participantIndex)->setPowerCapsLock(domainIndex, getPolicyIndex(), lock);
}

Bool PolicyServicesDomainPowerControl::isPowerShareControl(UIntN participantIndex, UIntN domainIndex)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->isPowerShareControl(domainIndex);
}

double PolicyServicesDomainPowerControl::getPidKpTerm(UIntN participantIndex, UIntN domainIndex)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->getPidKpTerm(domainIndex);
}

double PolicyServicesDomainPowerControl::getPidKiTerm(UIntN participantIndex, UIntN domainIndex)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->getPidKiTerm(domainIndex);
}

TimeSpan PolicyServicesDomainPowerControl::getTau(UIntN participantIndex, UIntN domainIndex)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->getTau(domainIndex);
}

TimeSpan PolicyServicesDomainPowerControl::getFastPollTime(UIntN participantIndex, UIntN domainIndex)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->getFastPollTime(domainIndex);
}

TimeSpan PolicyServicesDomainPowerControl::getSlowPollTime(UIntN participantIndex, UIntN domainIndex)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->getSlowPollTime(domainIndex);
}

UInt32 PolicyServicesDomainPowerControl::getWeightedSlowPollAvgConstant(UIntN participantIndex, UIntN domainIndex)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->getWeightedSlowPollAvgConstant(domainIndex);
}

UInt32 PolicyServicesDomainPowerControl::getRaplEnergyCounter(UIntN participantIndex, UIntN domainIndex)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->getRaplEnergyCounter(domainIndex);
}

double PolicyServicesDomainPowerControl::getRaplEnergyUnit(UIntN participantIndex, UIntN domainIndex)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->getRaplEnergyUnit(domainIndex);
}

UInt32 PolicyServicesDomainPowerControl::getRaplEnergyCounterWidth(UIntN participantIndex, UIntN domainIndex)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->getRaplEnergyCounterWidth(domainIndex);
}

Power PolicyServicesDomainPowerControl::getSlowPollPowerThreshold(UIntN participantIndex, UIntN domainIndex)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->getSlowPollPowerThreshold(domainIndex);
}

Power PolicyServicesDomainPowerControl::getInstantaneousPower(UIntN participantIndex, UIntN domainIndex)
{
	throwIfNotWorkItemThread();
	return getParticipantManager()->getParticipantPtr(participantIndex)->getInstantaneousPower(domainIndex);
}