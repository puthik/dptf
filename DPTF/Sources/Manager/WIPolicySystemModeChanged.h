/******************************************************************************
** Copyright (c) 2013-2022 Intel Corporation All Rights Reserved
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
#include "WorkItem.h"
#include "SystemMode.h"
#include "ManagerLogger.h"

class WIPolicySystemModeChanged : public WorkItem
{
public:
	WIPolicySystemModeChanged(DptfManagerInterface* dptfManager, SystemMode::Type systemMode);
	virtual ~WIPolicySystemModeChanged(void);

	virtual void onExecute(void) override final;

private:
	const SystemMode::Type m_systemMode;
};
