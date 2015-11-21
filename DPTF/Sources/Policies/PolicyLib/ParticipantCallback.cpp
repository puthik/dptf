/******************************************************************************
** Copyright (c) 2013-2015 Intel Corporation All Rights Reserved
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

#include "ParticipantCallback.h"
using namespace std;

ParticipantCallback::ParticipantCallback()
    : m_timeStamp(Constants::Invalid),
    m_callbackHandle(Constants::Invalid)
{
}

ParticipantCallback::ParticipantCallback(const TimeSpan& callbackTime, UInt64 timeStamp, UInt64 callbackHandle)
    : m_timeDelta(callbackTime),
    m_timeStamp(timeStamp),
    m_callbackHandle(callbackHandle)
{
}

ParticipantCallback::~ParticipantCallback()
{
}

const TimeSpan& ParticipantCallback::getTimeDelta() const
{
    return m_timeDelta;
}

UInt64 ParticipantCallback::getTimeStamp() const
{
    return m_timeStamp;
}

UInt64 ParticipantCallback::getCallbackHandle() const
{
    return m_callbackHandle;
}