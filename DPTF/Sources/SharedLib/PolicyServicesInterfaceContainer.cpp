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

#include "PolicyServicesInterfaceContainer.h"

PolicyServicesInterfaceContainer::PolicyServicesInterfaceContainer(void)
	: domainActiveControl(nullptr)
	, domainActivityStatus(nullptr)
	, domainConfigTdpControl(nullptr)
	, domainCoreControl(nullptr)
	, domainDisplayControl(nullptr)
	, domainPeakPowerControl(nullptr)
	, domainPerformanceControl(nullptr)
	, domainPowerControl(nullptr)
	, domainPowerStatus(nullptr)
	, domainPlatformPowerControl(nullptr)
	, domainPlatformPowerStatus(nullptr)
	, domainPriority(nullptr)
	, domainRfProfileControl(nullptr)
	, domainRfProfileStatus(nullptr)
	, domainTccOffsetControl(nullptr)
	, domainTemperature(nullptr)
	, domainUtilization(nullptr)
	, participantGetSpecificInfo(nullptr)
	, participantProperties(nullptr)
	, participantSetSpecificInfo(nullptr)
	, platformConfigurationData(nullptr)
	, platformNotification(nullptr)
	, platformPowerState(nullptr)
	, policyEventRegistration(nullptr)
	, policyInitiatedCallback(nullptr)
	, messageLogging(nullptr)
	, workloadHintConfiguration(nullptr)
	, platformState(nullptr)
{
}
