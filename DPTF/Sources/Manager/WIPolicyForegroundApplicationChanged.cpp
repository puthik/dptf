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

#include "WIPolicyForegroundApplicationChanged.h"
#include "PolicyManagerInterface.h"
#include "EsifServicesInterface.h"

WIPolicyForegroundApplicationChanged::WIPolicyForegroundApplicationChanged(
	DptfManagerInterface* dptfManager,
	const std::string& foregroundApplicationName)
	: WorkItem(dptfManager, FrameworkEvent::PolicyForegroundApplicationChanged)
	, m_foregroundApplicationName(foregroundApplicationName)
{
}

WIPolicyForegroundApplicationChanged::~WIPolicyForegroundApplicationChanged(void)
{
}

void WIPolicyForegroundApplicationChanged::execute(void)
{
	writeWorkItemStartingInfoMessage();

	auto policyManager = getPolicyManager();
	UIntN policyListCount = policyManager->getPolicyListCount();

	for (UIntN i = 0; i < policyListCount; i++)
	{
		try
		{
			getDptfManager()->getEventCache()->foregroundApplication.set(m_foregroundApplicationName);
			Policy* policy = policyManager->getPolicyPtr(i);
			policy->executePolicyForegroundApplicationChanged(m_foregroundApplicationName);
		}
		catch (policy_index_invalid ex)
		{
			// do nothing.  No item in the policy list at this index.
		}
		catch (std::exception& ex)
		{
			writeWorkItemErrorMessagePolicy(ex, "Policy::executePolicyForegroundApplicationChanged", i);
		}
	}
}
