//***************************************************************************
//
//  GFXMenuItem.hpp
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

#ifndef __Blokade__GFXMenuItem__hpp
#define __Blokade__GFXMenuItem__hpp

#pragma once

#include <SFML/Graphics.hpp>
#include "GFXRuntime.hpp"
#include "GFXBean.hpp"

class GFXMenu;

//&=========================================================================*
//&      Class  GFXMenuItem
//&=========================================================================*
//
//==========================================================================*
class GFXMenuItem : public sf::Drawable {
    
// =============================
// ======== P U B L I C ========
public:
    
    enum TYPE {
        EMPTY = 0,
        BUTTON,
        VALUE_SELECTOR
    };

    //&---------------------------------------------------------------------*
    //&      Constructor  GFXMenuItem
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    GFXMenuItem() {};

    //&---------------------------------------------------------------------*
    //&      Destructor  GFXMenuItem
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    ~GFXMenuItem() {};
        
    //&---------------------------------------------------------------------*
    //&      Method  reset
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void reset() {}
    
    //&---------------------------------------------------------------------*
    //&      Method  getHeight
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual const int getHeight() { return 0; }
    
    //&---------------------------------------------------------------------*
    //&      Method  isSelected
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual bool isSelected() { return false; }
    
    //&---------------------------------------------------------------------*
    //&      Method  setSelected
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void setSelected(bool id_state) {}
    

    //&---------------------------------------------------------------------*
    //&      Method  setPosition
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void setPosition(const int id_x, const int id_y) {}

    //&---------------------------------------------------------------------*
    //&      Method  update
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void update(GFXRuntime* id_pRuntime) {}

    //&---------------------------------------------------------------------*
    //&      Method  getTag
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual const int getTag() { return -1; }
    
    //&---------------------------------------------------------------------*
    //&      Method  getType
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual const TYPE getType() { return TYPE::EMPTY; }
    
    //&---------------------------------------------------------------------*
    //&      Method  selectNextValue
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void selectNextValue() {}
    
    //&---------------------------------------------------------------------*
    //&      Method  selectPreviousValue
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void selectPreviousValue() {}
    
    //&---------------------------------------------------------------------*
    //&      Method  getSelectedValue
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual const GFXBean* getSelectedValue() { return NULL; }

    //&---------------------------------------------------------------------*
    //&      Method  setSelectedValue
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void setSelectedValue(const GFXBean* id_pValue) {}

    //&---------------------------------------------------------------------*
    //&      Method  setSelectedIndex
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void setSelectedIndex(const int id_index) {}

// =============================
// ===== P R O T E C T E D =====
protected:

    const GFXMenu* m_pParent = NULL;
    int m_childIndex = 0;
    
// =============================
// ======= P R I V A T E =======
private:

};

#endif /* defined(__Blokade__GFXMenuItem__hpp) */