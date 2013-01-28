//***************************************************************************
//
//  GFXMenuSelector.hpp
//  Blokade
//
//  Created by moonfirefy on 2013-01-24.
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

#ifndef __Blokade__GFXMenuSelector__hpp
#define __Blokade__GFXMenuSelector__hpp

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "GFXMenuItem.hpp"
#include "GFXFont.hpp"
#include "GFXBean.hpp"
#include "ResourcePath.hpp"

//&=========================================================================*
//&      Class  GFXMenuSelector
//&=========================================================================*
//
//==========================================================================*
class GFXMenuSelector : public GFXMenuItem, public sf::Drawable {
    
// =============================
// ======== P U B L I C ========
public:
    
    //&---------------------------------------------------------------------*
    //&      Constructor  GFXMenuSelector
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    GFXMenuSelector() {}
    
    //&---------------------------------------------------------------------*
    //&      Destructor  ~GFXMenuSelector
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    ~GFXMenuSelector() {}
    
    //&---------------------------------------------------------------------*
    //&      Method  init
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool init(const char* id_pLabel, const int id_tag, const std::vector<GFXBean>* it_pValues);
    
    //&---------------------------------------------------------------------*
    //&      Method  init
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool init(const unsigned char* id_pLabel, const int id_tag, const std::vector<GFXBean>* it_pValues);

    //&---------------------------------------------------------------------*
    //&      Method  init
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool init(const char* id_pLabel, const int id_x, const int id_y, const int id_tag,
              const std::vector<GFXBean>* it_pValues);
    
    //&---------------------------------------------------------------------*
    //&      Method  setPosition
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setPosition(const int id_x, const int id_y);
    
    //&---------------------------------------------------------------------*
    //&      Method  setClickSurfaceMargin
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setClickSurfaceMargin(float id_leftRight, float id_topBottom) {}
    
    //&---------------------------------------------------------------------*
    //&      Method  update
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void update(GFXRuntime* id_pRuntime) {}
    
    //&---------------------------------------------------------------------*
    //&      Method  isSelected
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool isSelected();
    
    //&---------------------------------------------------------------------*
    //&      Method  setSelected
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setSelected(bool id_state);
    
    //&---------------------------------------------------------------------*
    //&      Method  reset
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void reset();
    
    //&---------------------------------------------------------------------*
    //&      Method  getTag
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const int getTag();
    
    //&---------------------------------------------------------------------*
    //&      Method  getType
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const TYPE getType();
    
    //&---------------------------------------------------------------------*
    //&      Method  selectNextValue
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void selectNextValue();
    
    //&---------------------------------------------------------------------*
    //&      Method  selectPreviousValue
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void selectPreviousValue();
    
    //&---------------------------------------------------------------------*
    //&      Method  getSelectedValue
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const GFXBean* getSelectedValue();
    
    //&---------------------------------------------------------------------*
    //&      Method  setSelectedValue
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setSelectedValue(const GFXBean* id_pValue);

    //&---------------------------------------------------------------------*
    //&      Method  setSelectedIndex
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setSelectedIndex(const int id_index);

// =============================
// ======= P R I V A T E =======
private:
    
    //&---------------------------------------------------------------------*
    //&      Method  draw
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void draw(sf::RenderTarget& id_rTarget, sf::RenderStates id_states) const;
    
    static sf::Texture m_buttonsSheet;
    static bool m_init;
    
   // const char* m_pLabel = NULL;
    //const char* m_pValue = NULL;
    static const int LABEL_X_OFFSET = 50;
    static const int LABEL_Y_OFFSET = 23;
    
    const std::vector<GFXBean>* m_pValues;
    int m_selectedValueIndex = -1;
    
    int m_tag = -1;
    
    int m_x = 0;
    int m_y = 0;
    
    GFXFont m_fontLabel;
    GFXFont m_fontValue;
    
    sf::Sprite m_normalSprite;
    sf::Sprite m_selectedSprite;
    sf::FloatRect m_clickSurfaceRect;
    
    bool m_isSelected;
    
    static const int BUTTON_WIDTH = 650;
    static const int BUTTON_HEIGHT = 120;
    static const int INDEX_NORMAL = 1;
    static const int INDEX_SELECTED = 0;
    
};

#endif /* defined(__Blokade__GFXMenuSelector__hpp) */
