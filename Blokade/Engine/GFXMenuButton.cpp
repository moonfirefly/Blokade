//***************************************************************************
//
//  GFXMenuButton.cpp
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

#include "GFXMenuButton.hpp"

// Initialize static members
bool GFXMenuButton::m_init = false;
sf::Texture GFXMenuButton::m_buttonsSheet;

//&---------------------------------------------------------------------*
//&      Method  init
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXMenuButton::init(const std::string id_string, const int id_tag) {
    return init(id_string, 0, 0, id_tag);
}

//&---------------------------------------------------------------------*
//&      Method  init
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXMenuButton::init(const std::string id_string, const int id_x, const int id_y, const int id_tag) {
    if (!m_init) {
        // Load button background once for all button instances
        if (!m_buttonsSheet.loadFromFile(resourcePath() + "menubutton.png")) {
            return false;
        }
        m_init = true;
    }

    if (id_string != "") {
        // Label provided, set and compute offset from left side for it to be centered
        m_label = id_string;
        m_labelXOffset = GFXFont::GET_CENTER_OFFSET(BUTTON_WIDTH, GFXFont::GET_STRING_OUTPUT_LENGTH(m_label));
        m_font.init(id_string);
    }

    m_tag = id_tag;
    m_isSelected = false;
    
    // Setup sprite for button image when not selected
    m_normalSprite = sf::Sprite(m_buttonsSheet);
    sf::IntRect normalRect;
    normalRect.top = INDEX_NORMAL * BUTTON_HEIGHT;
    normalRect.left = 0;
    normalRect.width = BUTTON_WIDTH;
    normalRect.height = BUTTON_HEIGHT;
    m_normalSprite.setTextureRect(normalRect);
    
    // Setup sprite for button image when it is selected
    m_selectedSprite = sf::Sprite(m_buttonsSheet);
    sf::IntRect selectedRect;
    selectedRect.top = INDEX_SELECTED * BUTTON_HEIGHT;
    selectedRect.left = 0;
    selectedRect.width = BUTTON_WIDTH;
    selectedRect.height = BUTTON_HEIGHT;
    m_selectedSprite.setTextureRect(selectedRect);

    // Set position on screen
    setPosition(id_x, id_y);
    
    return true;
}

//&---------------------------------------------------------------------*
//&      Method  setPosition
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuButton::setPosition(const int id_x, const int id_y) {
    m_normalSprite.setPosition(id_x, id_y);
    m_selectedSprite.setPosition(id_x, id_y);
    if (m_label != "") {
        // Label provided, position it according to pre-computed relative location
        m_font.setPosition(id_x + m_labelXOffset, id_y + LABEL_Y_OFFSET);
    }
}

//&---------------------------------------------------------------------*
//&      Method  isSelected
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXMenuButton::isSelected() {
    return m_isSelected;
}

//&---------------------------------------------------------------------*
//&      Method  setSelected
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuButton::setSelected(bool id_state) {
    m_isSelected = id_state;
}

//&---------------------------------------------------------------------*
//&      Method  reset
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuButton::reset() {
    m_isSelected = false;
}

//&---------------------------------------------------------------------*
//&      Method  draw
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuButton::draw(sf::RenderTarget& id_rTarget, sf::RenderStates id_states) const {
    if (m_isSelected) {
        id_rTarget.draw(m_selectedSprite, id_states);
    }
    else {
        id_rTarget.draw(m_normalSprite, id_states);
    }
    if (m_label != "") {
        id_rTarget.draw(m_font, id_states);
    }
}

//&---------------------------------------------------------------------*
//&      Method  getTag
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const int GFXMenuButton::getTag() {
    return m_tag;
}

//&---------------------------------------------------------------------*
//&      Method  getType
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const GFXMenuButton::TYPE GFXMenuButton::getType() {
    return TYPE::BUTTON;
}

//&---------------------------------------------------------------------*
//&      Method  getHeight
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const int GFXMenuButton::getHeight() {
    return BUTTON_HEIGHT;
}




