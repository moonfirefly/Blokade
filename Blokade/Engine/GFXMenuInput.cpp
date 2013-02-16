//***************************************************************************
//
//  GFXMenuInput.cpp
//  Blokade
//
//  Created by moonfirefy on 2013-02-02.
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

#include "GFXMenuInput.hpp"

// Initialize static members
bool GFXMenuInput::m_init = false;
sf::Texture GFXMenuInput::m_buttonsSheet;

//&---------------------------------------------------------------------*
//&      Method  init
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXMenuInput::init(const std::string id_label, const int id_tag, const int id_maxChars) {
    return init(id_label, 0, 0, id_tag, id_maxChars);
}

//&---------------------------------------------------------------------*
//&      Method  init
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXMenuInput::init(const std::string id_label, const int id_x, const int id_y, const int id_tag,
                        const int id_maxChars) {
    if (!m_init) {
        // Load button background once for all button instances
        if (!m_buttonsSheet.loadFromFile(resourcePath() + "menuValueSelector.png")) {
            return false;
        }
        m_init = true;
    }
    
    if (id_label != "") {
        // Label provided, set and compute offset from left side for it to be centered
        m_fontLabel.init(id_label);
    }
    
    m_fontCursor.init(i18n::ASCII_BLOCK);
    
    m_maxChars = id_maxChars;
    m_cursorLocation = 0;
    m_tag = id_tag;
    m_isSelected = false;

    setInputValue("");
    
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
void GFXMenuInput::setPosition(const int id_x, const int id_y) {
    m_normalSprite.setPosition(id_x, id_y);
    m_selectedSprite.setPosition(id_x, id_y);
    m_x = id_x;
    m_y = id_y;
    m_fontLabel.setPosition(id_x + LABEL_X_OFFSET, id_y + LABEL_Y_OFFSET);
    m_fontValue.setPosition(id_x + BUTTON_WIDTH - LABEL_X_OFFSET - m_fontValue.getCharsOutputLength(),
                            id_y + LABEL_Y_OFFSET);
    m_fontCursor.setPosition(id_x + BUTTON_WIDTH - LABEL_X_OFFSET - m_fontCursor.getCharsOutputLength(),
                            id_y + LABEL_Y_OFFSET);
}

//&---------------------------------------------------------------------*
//&      Method  update
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuInput::update(GFXRuntime* id_pRuntime) {
    if (!isSelected()) {
        return;
    }
    
    m_cursorBlinkCount += id_pRuntime->getTimeElapsed().asMilliseconds();
    if (m_cursorBlinkCount > CURSOR_BLINK_DELAY) {
        m_showCursor = !m_showCursor;
        m_cursorBlinkCount = 0;
    }
    
    if (id_pRuntime->getKeyPressed() == sf::Keyboard::Key::Return) {
        m_inputFinished = true;
    }
    else {
        if (id_pRuntime->getKeyPressed() == sf::Keyboard::Key::Delete ||
            id_pRuntime->getKeyPressed() == sf::Keyboard::Key::BackSpace) {
            if (m_input.size() > 0) {
                setInputValue(m_input.substr(0, m_input.size() - 1));
            }
        }
        else if (id_pRuntime->getCharTyped()) {
            if (id_pRuntime->getCharTyped() == 32 && m_input == "") {
                // do not insert space when no characters have been typed yet
            }
            else {
                m_input.append(1,id_pRuntime->getCharTyped());
                setInputValue(m_input);
            }
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  isSelected
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXMenuInput::isSelected() {
    return m_isSelected;
}

//&---------------------------------------------------------------------*
//&      Method  setSelected
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuInput::setSelected(bool id_state) {
    m_isSelected = id_state;
}

//&---------------------------------------------------------------------*
//&      Method  reset
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuInput::reset(const bool id_clearInputValue) {
    if (id_clearInputValue) {
        setInputValue("");
    }
    m_inputFinished = false;
    m_cursorBlinkCount = 0;
}

//&---------------------------------------------------------------------*
//&      Method  getTag
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const int GFXMenuInput::getTag() {
    return m_tag;
}

//&---------------------------------------------------------------------*
//&      Method  getType
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const GFXMenuItem::TYPE GFXMenuInput::getType() {
    return GFXMenuItem::TYPE::INPUT;
}

//&---------------------------------------------------------------------*
//&      Method  moveCursorRight
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuInput::moveCursorRight() {
}

//&---------------------------------------------------------------------*
//&      Method  moveCursorLeft
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuInput::moveCursorLeft() {
}

//&---------------------------------------------------------------------*
//&      Method  getInputValue
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const std::string GFXMenuInput::getInputValue() {
    return m_input;
}

//&---------------------------------------------------------------------*
//&      Method  setInputValue
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuInput::setInputValue(const std::string id_value) {
    if (id_value.size() <= m_maxChars) {
        m_input = id_value;
    }
    else {
        m_input = id_value.substr(0, m_maxChars);
    }
    m_fontValue.init(m_input);
    m_fontValue.setPosition(m_x + BUTTON_WIDTH - LABEL_X_OFFSET -
                                m_fontValue.getCharsOutputLength() - GFXFont::CHAR_PIXEL_WIDTH,
                            m_y + LABEL_Y_OFFSET);
}

//&---------------------------------------------------------------------*
//&      Method  getInputFinished
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const bool GFXMenuInput::getInputFinished() {
    return m_inputFinished;
}

//&---------------------------------------------------------------------*
//&      Method  draw
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenuInput::draw(sf::RenderTarget& id_rTarget, sf::RenderStates id_states) const {
    if (m_isSelected) {
        id_rTarget.draw(m_selectedSprite, id_states);
    }
    else {
        id_rTarget.draw(m_normalSprite, id_states);
    }
    id_rTarget.draw(m_fontLabel);
    if (m_showCursor) {
        id_rTarget.draw(m_fontCursor);
    }
    id_rTarget.draw(m_fontValue);
}


