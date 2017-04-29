/*******************************************************************************
** This file is provided under a dual BSD/GPLv2 license.  When using or
** redistributing this file, you may do so under either license.
**
** GPL LICENSE SUMMARY
**
** Copyright (c) 2013-2017 Intel Corporation All Rights Reserved
**
** This program is free software; you can redistribute it and/or modify it under
** the terms of version 2 of the GNU General Public License as published by the
** Free Software Foundation.
**
** This program is distributed in the hope that it will be useful, but WITHOUT
** ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
** FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
** details.
**
** You should have received a copy of the GNU General Public License along with
** this program; if not, write to the Free Software  Foundation, Inc.,
** 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
** The full GNU General Public License is included in this distribution in the
** file called LICENSE.GPL.
**
** BSD LICENSE
**
** Copyright (c) 2013-2017 Intel Corporation All Rights Reserved
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**
** * Redistributions of source code must retain the above copyright notice, this
**   list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice,
**   this list of conditions and the following disclaimer in the documentation
**   and/or other materials provided with the distribution.
** * Neither the name of Intel Corporation nor the names of its contributors may
**   be used to endorse or promote products derived from this software without
**   specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  SPECIAL, EXEMPLARY, OR
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
** POSSIBILITY OF SUCH DAMAGE.
**
*******************************************************************************/

#pragma once

#include "esif_sdk.h"

/*
 * Domain Type
 */

typedef enum esif_domain_type {
	ESIF_DOMAIN_TYPE_INVALID = -1,
	ESIF_DOMAIN_TYPE_PROCESSOR = 0,
	ESIF_DOMAIN_TYPE_GRAPHICS = 1,
	ESIF_DOMAIN_TYPE_MEMORY = 2,
	ESIF_DOMAIN_TYPE_TEMPERATURE = 3,
	ESIF_DOMAIN_TYPE_FAN = 4,
	ESIF_DOMAIN_TYPE_CHIPSET = 5,
	ESIF_DOMAIN_TYPE_ETHERNET = 6,
	ESIF_DOMAIN_TYPE_WIRELESS = 7,
	ESIF_DOMAIN_TYPE_AHCI = 8,
	ESIF_DOMAIN_TYPE_MULTIFUNCTION = 9,
	ESIF_DOMAIN_TYPE_DISPLAY = 10,
	ESIF_DOMAIN_TYPE_BATTERYCHARGER = 11,
	ESIF_DOMAIN_TYPE_BATTERY = 12,
	ESIF_DOMAIN_TYPE_AUDIO = 13,
	ESIF_DOMAIN_TYPE_OTHER = 14,
	ESIF_DOMAIN_TYPE_WWAN = 15,
	ESIF_DOMAIN_TYPE_POWER = 17,
	ESIF_DOMAIN_TYPE_THERMISTOR = 18,
	ESIF_DOMAIN_TYPE_INFRARED = 19,
	ESIF_DOMAIN_TYPE_VIRTUAL = 21,
	ESIF_DOMAIN_TYPE_AMBIENT = 22,
	ESIF_DOMAIN_TYPE_CAM2D = 27,
	ESIF_DOMAIN_TYPE_NVME = 29,
	ESIF_DOMAIN_TYPE_DSX = 30,
	ESIF_DOMAIN_TYPE_RFEM = 32,
	ESIF_DOMAIN_TYPE_M2CNV = 33,
	ESIF_DOMAIN_TYPE_SOCCNV = 34,
	ESIF_DOMAIN_TYPE_IVCAM = 35,
	ESIF_DOMAIN_TYPE_DGFXCORE = 36,
	ESIF_DOMAIN_TYPE_DGFXMEM = 37,
	ESIF_DOMAIN_TYPE_DGFXMCP = 38,
	ESIF_DOMAIN_TYPE_ALL = 255,
} esif_domain_type_t;

/* Max Enum Value for Iteration purposes (Excluding ALL) */
#define MAX_ESIF_DOMAIN_TYPE_ENUM_VALUE  ESIF_DOMAIN_TYPE_DGFXMCP

static ESIF_INLINE esif_string esif_domain_type_str(esif_domain_type_t type)
{
	switch (type) {
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_INVALID);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_PROCESSOR);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_GRAPHICS);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_MEMORY);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_TEMPERATURE);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_FAN);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_CHIPSET);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_ETHERNET);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_WIRELESS);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_AHCI);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_MULTIFUNCTION);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_DISPLAY);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_BATTERYCHARGER);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_BATTERY);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_AUDIO);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_OTHER);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_WWAN);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_POWER);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_THERMISTOR);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_INFRARED);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_VIRTUAL);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_AMBIENT);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_CAM2D);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_NVME);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_DSX);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_RFEM);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_M2CNV);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_SOCCNV);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_IVCAM);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_DGFXCORE);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_DGFXMEM);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_DGFXMCP);
	ESIF_CASE_ENUM(ESIF_DOMAIN_TYPE_ALL);
	}
	return ESIF_NOT_AVAILABLE;
}
