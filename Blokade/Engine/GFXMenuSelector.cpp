//***************************************************************************
//
//  GFXMenuSelector.cpp
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

#include "GFXMenuSelector.hpp"

// Initialize static members
bool GFXMenuSelector::m_init = false;
sf::Texture GFXMenuSelector::m_buttonsSheet;

//&---------------------------------------------------------------------*
//&      Method  init
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXMenuSelector::init(const char* id_pLabel, const int id_tag, const std::vector<GFXBean>* it_pValues) {
    return init(id_pLabel, 0, 0, id_tag, it_pValues);
}

//&---------------------------------------------------------------------*
//&      Method  init
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXMenuSelector::init(const unsigned char* id_pLabel, const int id_tag, const std::vector<GFXBean>* it_pValues) {
    return init((char*)id_pLabel, 0, 0, id_tag, it_pValues);
}

//&---------------------------------------------------------------------*
//&      Method  init
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXMenuSelector::init(const char* id_pLabel, const int id_x, const int id_y,
                           const int id_tag, const std::vector<GFXBean>* it_pValues) {
    if (!m_init) {
        // Load button background once for all button instances
        if (!m_buttonsSheet.loadFromFile(resourcePath() + "menuValueSelector.png")) {
            return false;
        }
        m_init = true;
    }

    if (id_pLabel != NULL) {
        // Label provided, set and compute offset from left side for it to be centered
        m_fontLabel.init(id_pLabel);
    }

    m_pValues = it_pValues;
    m_tag = id_tag;
    m_isSelected = false;

    if ((*it_pValues).size() > 0) {
        setSelectedIndex(0);
    }

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
void GFXMenuSelector::setPosition(const int id_x, const int id_y) {
    m_normalSprite.setPosition(id_x, id_y);
    m_selectedSprite.setPosition(id_x, id_y);
    m_x = id_x;
    m_y = id_y;
    m_fontLabel.setPosition(id_x + LABEL_X_OFFSET, id_y + LABEL_Y_OFFSET);
    m_fontValue.setPosition(id_x + BUTTON_WIDTH - LABEL_X_OFFSET - m_fontValue.getCharsOutputLength(),
                            id_y + LABEL_Y_OFFSET);
}

//&---------------------------------------------------------------------*
//&      Method  isSelected
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXMenuSelector::isSelected() {
    return m_isSelected;
}

//&---------------------------------------------------------------------*
//&      Method  setSelected
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuSelector::setSelected(bool id_state) {
    m_isSelected = id_state;
}

//&---------------------------------------------------------------------*
//&      Method  reset
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuSelector::reset() {
    m_isSelected = false;
}

//&---------------------------------------------------------------------*
//&      Method  draw
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuSelector::draw(sf::RenderTarget& id_rTarget, sf::RenderStates id_states) const {
    if (m_isSelected) {
        id_rTarget.draw(m_selectedSprite, id_states);
    }
    else {
        id_rTarget.draw(m_normalSprite, id_states);
    }
    id_rTarget.draw(m_fontLabel);
    id_rTarget.draw(m_fontValue);
}

//&---------------------------------------------------------------------*
//&      Method  getTag
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const int GFXMenuSelector::getTag() {
    return m_tag;
}

//&---------------------------------------------------------------------*
//&      Method  getType
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const GFXMenuItem::TYPE GFXMenuSelector::getType() {
    return GFXMenuItem::TYPE::VALUE_SELECTOR;
}

//&---------------------------------------------------------------------*
//&      Method  selectNextValue
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuSelector::selectNextValue() {
    if ((m_selectedValueIndex + 1) < static_cast<int>(m_pValues->size())) {
        setSelectedIndex(m_selectedValueIndex + 1);
    }
    else {
        setSelectedIndex(0);
    }
}

//&---------------------------------------------------------------------*
//&      Method  selectPreviousValue
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuSelector::selectPreviousValue() {
    if ((m_selectedValueIndex - 1) >= 0) {
        setSelectedIndex(m_selectedValueIndex - 1);
    }
    else {
        setSelectedIndex((int)m_pValues->size() - 1);
    }
}

//&---------------------------------------------------------------------*
//&      Method  getSelectedValue
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const GFXBean* GFXMenuSelector::getSelectedValue() {
    return &(m_pValues->at(m_selectedValueIndex));
}

//&---------------------------------------------------------------------*
//&      Method  setSelectedValue
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuSelector::setSelectedValue(const GFXBean* id_pValue) {
    m_selectedValueIndex = 0;
    int index = 0;
    for (std::vector<GFXBean>::const_iterator i = m_pValues->begin(); i != m_pValues->end(); ++i, index++) {
        if ((*i) == (*id_pValue)) {
            setSelectedIndex(index);
            break;
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  setSelectedIndex
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuSelector::setSelectedIndex(const int id_index) {
    if (id_index >= 0 && id_index < static_cast<int>(m_pValues->size())) {
        m_selectedValueIndex = id_index;
        m_fontValue.init((m_pValues->at(id_index)).getLabel());
        m_fontValue.setPosition(m_x + BUTTON_WIDTH - LABEL_X_OFFSET - m_fontValue.getCharsOutputLength(),
                                m_y + LABEL_Y_OFFSET);
    }
}

