/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \file      Parameter.h
 * \brief     Definition of parameter class
 * \author    Padmaja A, Tobias Lorenz
 * \copyright Copyright (c) 2011, Robert Bosch Engineering and Business Solutions. All rights reserved.
 *
 * Definition of the parameter class.
 */

#ifndef Parameter_H
#define Parameter_H

#include <list>
#include <string>

#include "ParameterVal.h"

using namespace std;

class CParameters
{
public:
    string			m_ObjectId;
    string			m_ParamType;
    SIG_VALUE       m_MaxVal;
    SIG_VALUE		m_MinVal;
    string    		m_ValRange;
    SIG_VALUE	    m_InitVal;
    string			m_ParamName;
    bool            m_RangeError;
    bool            m_defError;
    list<CParameterValues> m_listParamValues[6];
    CParameters();
    int Format(char *pcLine);
    CParameters& operator=(CParameters& param);
    int FormatParamValue(char *pcLine);
    int ReadDefaultVal(char *pcToken);
    friend bool WriteParametersToFile(fstream& fileOutput, list<CParameters> &m_listParameter);
    virtual ~CParameters();
};



#endif