//***************************************************************************
//
//  GFXMenuButton.hpp
//  Blokade
//
//  Created by moonfirefy on 2013-01-13.
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

#ifndef __Blokade__GFXMenuButton__hpp
#define __Blokade__GFXMenuButton__hpp

#pragma once

#include <SFML/Graphics.hpp>
#include "GFXMenuItem.hpp"
#include "GFXFont.hpp"
#include "../ResourcePath.hpp"

//&=========================================================================*
//&      Class  GFXMenuButton
//&=========================================================================*
//
//==========================================================================*
class GFXMenuButton : public GFXMenuItem, public sf::Drawable {

// =============================
// ======== P U B L I C ========
public:

    //&---------------------------------------------------------------------*
    //&      Constructor  GFXMenuButton
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    GFXMenuButton() {}

    //&---------------------------------------------------------------------*
    //&      Destructor  ~GFXMenuButton
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    ~GFXMenuButton() {}

    //&---------------------------------------------------------------------*
    //&      Method  init
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool init(const char* id_pLabel, const int id_tag);

    //&---------------------------------------------------------------------*
    //&      Method  init
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool init(const unsigned char* id_pLabel, const int id_tag);

    //&---------------------------------------------------------------------*
    //&      Method  init
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool init(const char* id_pLabel, const int id_x, const int id_y, const int id_tag);

    //&---------------------------------------------------------------------*
    //&      Method  setPosition
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setPosition(const int id_x, const int id_y);

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
    //&      Method  getHeight
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const int getHeight();

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

    const char* m_pLabel = NULL;
    int m_labelXOffset = 0;
    static const int LABEL_Y_OFFSET = 23;

    int m_tag = -1;

    GFXFont m_font;

    sf::Sprite m_normalSprite;
    sf::Sprite m_selectedSprite;
    sf::FloatRect m_clickSurfaceRect;

    bool m_isSelected;

    static const int BUTTON_WIDTH = 338;
    static const int BUTTON_HEIGHT = 120;
    static const int INDEX_NORMAL = 1;
    static const int INDEX_SELECTED = 0;

};

#endif /* defined(__Blokade__GFXMenuButton__hpp) */
