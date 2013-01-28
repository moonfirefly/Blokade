//***************************************************************************
//
//  GFXBean.cpp
//  Blokade
//
//  Created by moonfirefy on 2013-01-21.
//
//*-------------------------------------------------------------------------*
//
// Copyright 2013 moonfirefy
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//***************************************************************************

#include "GFXBean.hpp"

//&---------------------------------------------------------------------*
//&      Constructor  GFXBean
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
GFXBean::GFXBean(const char* id_label, int id_value) {
    m_label = id_label;
    m_value = id_value;
}

//&---------------------------------------------------------------------*
//&      Constructor  GFXBean
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
GFXBean::GFXBean(const unsigned char* id_label, int id_value) {
    m_label = (char*)id_label;
    m_value = id_value;
}

//&---------------------------------------------------------------------*
//&      Constructor  GFXBean
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
GFXBean::GFXBean(const char* id_label, int id_value, void* id_pData) {
    m_label = id_label;
    m_value = id_value;
    m_pData = id_pData;
}

//&---------------------------------------------------------------------*
//&      Constructor  GFXBean
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
GFXBean::GFXBean(const unsigned char* id_label, int id_value, void* id_pData) {
    m_label = (char*)id_label;
    m_value = id_value;
    m_pData = id_pData;
}

//&---------------------------------------------------------------------*
//&      Method  getLabel
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const char* GFXBean::getLabel() const {
    return m_label;
}

//&---------------------------------------------------------------------*
//&      Method  getValue
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const int GFXBean::getValue() const {
    return m_value;
}

//&---------------------------------------------------------------------*
//&      Method  setData
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXBean::setData(const void* id_pData) {
    m_pData = id_pData;
}

//&---------------------------------------------------------------------*
//&      Method  getData
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const void* GFXBean::getData() const {
    return m_pData;
}

//&---------------------------------------------------------------------*
//&      Operator  ==
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXBean::operator==(const GFXBean& id_rOtherBean) const {
    if (m_value == id_rOtherBean.getValue()) {
        return true;
    }
    else {
        return false;
    }
}
