/*******************************************************************************
 * shroudBNC - an object-oriented framework for IRC                            *
 * Copyright (C) 2005 Gunnar Beutner                                           *
 *                                                                             *
 * This program is free software; you can redistribute it and/or               *
 * modify it under the terms of the GNU General Public License                 *
 * as published by the Free Software Foundation; either version 2              *
 * of the License, or (at your option) any later version.                      *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 * GNU General Public License for more details.                                *
 *                                                                             *
 * You should have received a copy of the GNU General Public License           *
 * along with this program; if not, write to the Free Software                 *
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA. *
 *******************************************************************************/

#if !defined(AFX_BOUNCERCONFIG_H__573EF68F_20D5_46A3_AE5D_311447241847__INCLUDED_)
#define AFX_BOUNCERCONFIG_H__573EF68F_20D5_46A3_AE5D_311447241847__INCLUDED_

#ifndef AFX_HASHTABLE_H__FA383811_CE36_4970_9236_9F1EAECC6998__INCLUDED_
#include "Hashtable.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <typename value_type, bool casesensitive = false> class CHashtable;

typedef struct config_s {
	char* Name;
	char* Value;
} config_t;

class CBouncerConfig {
	CHashtable<char*>* m_Settings;

	char* m_File;
	bool m_WriteLock;

	void ParseConfig(const char* Filename);
	void Persist(void);
public:
	CBouncerConfig(const char* Filename);
	virtual ~CBouncerConfig();

	virtual int ReadInteger(const char* Setting);
	virtual const char* ReadString(const char* Setting);

	virtual void WriteInteger(const char* Setting, const int Value);
	virtual void WriteString(const char* Setting, const char* Value);

	virtual hash_t<char*>* GetSettings(void);
	virtual int GetSettingCount(void);

	virtual const char* GetFilename(void);
};

#endif // !defined(AFX_BOUNCERCONFIG_H__573EF68F_20D5_46A3_AE5D_311447241847__INCLUDED_)
