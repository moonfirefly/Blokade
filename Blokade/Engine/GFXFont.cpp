//***************************************************************************
//
//  GFXFont.cpp
//  Blokade
//
//  Created by moonfirefy on 2013-01-17.
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

#include "GFXFont.hpp"

// Initialize static members
sf::Texture GFXFont::m_fontTexture;
bool GFXFont::m_loaded = false;

//&---------------------------------------------------------------------*
//&      Method  init
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXFont::init(sf::RenderWindow& id_rWindow) {
    m_pWindow = &id_rWindow;
    if (!loadTexture()) {
        return false;
    }
    return true;
}

//&---------------------------------------------------------------------*
//&      Method  init
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXFont::init(const std::string id_string) {
    if (!loadTexture()) {
        return false;
    }
    m_string = id_string;
    m_outputLength = GET_STRING_OUTPUT_LENGTH(id_string);
    return true;
}

//&---------------------------------------------------------------------*
//&      Method  setPosition
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXFont::setPosition(const int id_x, const int id_y) {
    m_x = id_x;
    m_y = id_y;
}

//&---------------------------------------------------------------------*
//&      Method  drawStringAtPos
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXFont::drawStringAtPos(const std::string id_string, const int id_x, const int id_y) {
    drawStringAtPos(id_string, id_x, id_y, *m_pWindow, sf::RenderStates::Default);
}

//&---------------------------------------------------------------------*
//&      Method  drawStringAtPos
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXFont::drawStringAtPos(const std::string id_string, const int id_x, const int id_y, const int id_centerWidth) {
    int offset = GET_CENTER_OFFSET(id_centerWidth, GET_STRING_OUTPUT_LENGTH(id_string));
    drawStringAtPos(id_string, id_x + offset, id_y, *m_pWindow, sf::RenderStates::Default);
}

//&---------------------------------------------------------------------*
//&      Method  drawByteAtPos
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXFont::drawByteAtPos(const unsigned char id_byte, const int id_x, const int id_y,
                            sf::RenderTarget& id_rTarget, sf::RenderStates id_states) const {
    static sf::Sprite fontSprite;
    static bool loaded = false;
        
    if (!loaded) {
        fontSprite = sf::Sprite(m_fontTexture);
    }
    
    int row  = (int)((float) id_byte / CHARS_PER_ROW);
    int column = id_byte % CHARS_PER_ROW;
    
    sf::IntRect rect;
    rect.top = row * CHAR_PIXEL_HEIGHT;
    rect.left = column * CHAR_PIXEL_WIDTH;
    rect.width = CHAR_PIXEL_WIDTH;
    rect.height = CHAR_PIXEL_HEIGHT;
    fontSprite.setTextureRect(rect);
    
    fontSprite.setPosition(id_x, id_y);
    
    if (m_pWindow == NULL) {
        id_rTarget.draw(fontSprite, id_states);
    }
    else {
        m_pWindow->draw(fontSprite);
    }
}

//&---------------------------------------------------------------------*
//&      Method  drawBytesAtPos
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXFont::drawStringAtPos(const std::string id_string, const int id_x, const int id_y,
                                 sf::RenderTarget& id_rTarget, sf::RenderStates id_states) const {
    int offset = 0;
    int line = 0;
    int shift = 0;
    bool lastCharWasSmall = false;
    int length = static_cast<int>(id_string.size());
    for (int i = 0; i < length && i < MAX_CHARS_TO_PRINT; i++) {
        shift = 0;
        unsigned char value = id_string[i];
        switch (value) {
            case TAB:
                offset += 3;
                break;
            case CARRIAGE_RETURN:
                line++;
                offset = -1;
                break;
            default:
                if (lastCharWasSmall) {
                    shift = 5;
                }
                else if (value == I) {
                    shift = 2;
                }
                if (value != SPACE) {
                    drawByteAtPos(value,
                                  id_x + (offset * (CHAR_PIXEL_WIDTH - SPACING)) - shift,
                                  id_y + (line * CHAR_PIXEL_HEIGHT),
                                  id_rTarget,
                                  id_states);
                }
                break;
        }
        if (value == I) {
            lastCharWasSmall = true;
        }
        else {
            lastCharWasSmall = false;
        }
        offset++;
    }
}

//&---------------------------------------------------------------------*
//&      Method  getCharsOutputLength
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const int GFXFont::GET_STRING_OUTPUT_LENGTH(const std::string id_string) {
    int offset = 0;
    int shift = 0;
    bool lastCharWasSmall = false;
    std::list<int> linesLen;
    int length = static_cast<int>(id_string.size());
    for (int i = 0; i < length && i < MAX_CHARS_TO_PRINT; i++) {
        shift = 0;
        unsigned char value = id_string[i];
        switch (value) {
            case TAB:
                offset += 3 * (CHAR_PIXEL_WIDTH - SPACING - shift);
                break;
            case CARRIAGE_RETURN:
                linesLen.push_back(offset);
                offset = 0;
                break;
            default:
                if (lastCharWasSmall) {
                    shift = 5;
                }
                else if (value == I) {
                    shift = 2;
                }
                break;
        }
        if (value == I) {
            lastCharWasSmall = true;
        }
        else {
            lastCharWasSmall = false;
        }
        offset += CHAR_PIXEL_WIDTH - SPACING - shift;
    }
    for (std::list<int>::const_iterator i = linesLen.begin(); i != linesLen.end(); ++i) {
        if ((*i) > offset) {
            offset = *i;
        }
    }
    return offset;
}

//&---------------------------------------------------------------------*
//&      Method  getCharsOutputLength
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const int GFXFont::getCharsOutputLength() {
    return m_outputLength;
}

//&---------------------------------------------------------------------*
//&      Method  GET_CENTER_OFFSET
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const int GFXFont::GET_CENTER_OFFSET(const int id_containerWidth, const int id_widthToCenter) {
    return (id_containerWidth - id_widthToCenter) / 2;
}

//&---------------------------------------------------------------------*
//&      Method  loadTexture
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXFont::loadTexture() {
    if (!m_loaded) {
        if (!m_fontTexture.loadFromFile(resourcePath() + "fontAnonymousAscii.png")) {
            return false;
        }
    }
    return true;
}

//&---------------------------------------------------------------------*
//&      Method  draw
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXFont::draw(sf::RenderTarget& id_rTarget, sf::RenderStates id_states) const {
    if (m_string != "") {
        drawStringAtPos(m_string, m_x, m_y, id_rTarget, id_states);
    }
}

