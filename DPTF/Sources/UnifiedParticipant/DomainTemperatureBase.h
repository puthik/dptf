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
#include "DomainTemperatureInterface.h"
#include "ControlBase.h"
#include "ParticipantServicesInterface.h"
#include "ParticipantActivityLoggingInterface.h"
#include <CachedValue.h>

class DomainTemperatureBase : public ControlBase,
							  public DomainTemperatureInterface,
							  public ParticipantActivityLoggingInterface
{
public:
	DomainTemperatureBase(
		UIntN participantIndex,
		UIntN domainIndex,
		std::shared_ptr<ParticipantServicesInterface> participantServicesInterface);
	virtual ~DomainTemperatureBase();

	// DomainTemperatureInterface
	virtual TemperatureThresholds getTemperatureThresholds(UIntN participantIndex, UIntN domainIndex) override;
	virtual void setTemperatureThresholds(
		UIntN participantIndex,
		UIntN domainIndex,
		const TemperatureThresholds& temperatureThresholds) override;

	// ParticipantActivityLoggingInterface
	virtual void sendActivityLoggingDataIfEnabled(UIntN participantIndex, UIntN domainIndex) override;

private:
	Temperature getAuxTemperatureThreshold(UIntN domainIndex, UInt8 auxNumber);
	Temperature getHysteresis(UIntN domainIndex) const;
	void setAux0(Temperature& aux0, UIntN domainIndex);
	void setAux1(Temperature& aux1, UIntN domainIndex);

protected:
	CachedValue<Temperature> m_lastSetAux0;
	CachedValue<Temperature> m_lastSetAux1;
};
