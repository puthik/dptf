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

#include "DomainTemperature_000.h"

DomainTemperature_000::DomainTemperature_000(
	UIntN participantIndex,
	UIntN domainIndex,
	std::shared_ptr<ParticipantServicesInterface> participantServicesInterface)
	: DomainTemperatureBase(participantIndex, domainIndex, participantServicesInterface)
{
	// Do nothing.  Not an error.
}

TemperatureStatus DomainTemperature_000::getTemperatureStatus(UIntN participantIndex, UIntN domainIndex)
{
	throw not_implemented();
}

TemperatureThresholds DomainTemperature_000::getTemperatureThresholds(UIntN participantIndex, UIntN domainIndex)
{
	throw not_implemented();
}

void DomainTemperature_000::setTemperatureThresholds(
	UIntN participantIndex,
	UIntN domainIndex,
	const TemperatureThresholds& temperatureThresholds)
{
	throw not_implemented();
}

DptfBuffer DomainTemperature_000::getCalibrationTable(UIntN participantIndex, UIntN domainIndex)
{
	throw not_implemented();
}

DptfBuffer DomainTemperature_000::getPollingTable(UIntN participantIndex, UIntN domainIndex)
{
	throw not_implemented();
}

Bool DomainTemperature_000::isVirtualTemperature(UIntN participantIndex, UIntN domainIndex)
{
	return false;
}

void DomainTemperature_000::setVirtualTemperature(
	UIntN participantIndex,
	UIntN domainIndex,
	const Temperature& temperature)
{
	throw not_implemented();
}

void DomainTemperature_000::sendActivityLoggingDataIfEnabled(UIntN participantIndex, UIntN domainIndex)
{
	throw not_implemented();
}

void DomainTemperature_000::clearCachedData(void)
{
	// Do nothing.  Not an error.
}

std::shared_ptr<XmlNode> DomainTemperature_000::getXml(UIntN domainIndex)
{
	throw not_implemented();
}

std::string DomainTemperature_000::getName(void)
{
	return "Temperature Control (Version 0)";
}
