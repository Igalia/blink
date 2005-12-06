/*
 * This file is part of the DOM implementation for KDE.
 *
 * Copyright (C) 2000 Lars Knoll (knoll@kde.org)
 *           (C) 2000 Antti Koivisto (koivisto@kde.org)
 *           (C) 2000 Dirk Mueller (mueller@kde.org)
 * Copyright (C) 2003, 2005 Apple Computer, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#ifndef KHTML_DataRef_H
#define KHTML_DataRef_H

namespace khtml {

template <class DATA>
class DataRef
{
public:

    DataRef() : m_data(0) { }
    
    DataRef(const DataRef<DATA>& d)
    {
    	m_data = d.m_data;
	m_data->ref();
    }

    ~DataRef()
    {
    	if(m_data)
            m_data->deref();
    }

    const DATA* operator->() const
    {
    	return m_data;
    }

    const DATA* get() const
    {
    	return m_data;
    }

    DATA* access()
    {
    	if (!m_data->hasOneRef()) {
	    m_data->deref();
	    m_data = new DATA(*m_data);
	    m_data->ref();
	}
	return m_data;
    }

    void init()
    {
    	m_data = new DATA;
	m_data->ref();
    }

    DataRef<DATA>& operator=(const DataRef<DATA>& d)
    {
    	if (m_data == d.m_data)
	    return *this;
    	if (m_data)
    	    m_data->deref();
    	m_data = d.m_data;
	m_data->ref();

	return *this;
    }

    bool operator == (const DataRef<DATA>& o) const
    {
	return (*m_data == *(o.m_data));
    }
    
    bool operator != (const DataRef<DATA>& o) const
    {
	return (*m_data != *(o.m_data));
    }

private:
    DATA* m_data;
};

};

#endif

