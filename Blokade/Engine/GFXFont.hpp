//***************************************************************************
//
//  GFXFont.hpp
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

#ifndef __Blokade__GFXFont__hpp
#define __Blokade__GFXFont__hpp

#include <math.h>
#include <list>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

//&=========================================================================*
//&      Class  GFXFont
//&=========================================================================*
//
//==========================================================================*
class GFXFont : public sf::Drawable {
    
// =============================
// ======== P U B L I C ========
public:
    
    //&---------------------------------------------------------------------*
    //&      Constructor  GFXFont
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    GFXFont() {}
    
    //&---------------------------------------------------------------------*
    //&      Destructor  ~GFXFont
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    ~GFXFont() {}
    
    //&---------------------------------------------------------------------*
    //&      Method  init
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool init(sf::RenderWindow& id_rWindow);
    
    //&---------------------------------------------------------------------*
    //&      Method  init
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool init(const char* id_pChar);
 
    //&---------------------------------------------------------------------*
    //&      Method  setPosition
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setPosition(const int id_x, const int id_y);
    
    //&---------------------------------------------------------------------*
    //&      Method  drawCharAtPos
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void drawCharAtPos(const char id_char, const int id_x, const int id_y) const;
    
    //&---------------------------------------------------------------------*
    //&      Method  drawCharsAtPos
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void drawCharsAtPos(const char* id_pChar, const int id_x, const int id_y) const;
    
    //&---------------------------------------------------------------------*
    //&      Method  drawBytesAtPos
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void drawBytesAtPos(const unsigned char* id_pBytes, const int id_x, const int id_y) const;
    
    //&---------------------------------------------------------------------*
    //&      Method  drawBytesAtPos
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void drawBytesAtPos(const unsigned char* id_pBytes, const int id_x, const int id_y, const int id_centerWidth) const;
    
    //&---------------------------------------------------------------------*
    //&      Method  GET_CHARS_OUTPUT_LENGTH
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    static const int GET_CHARS_OUTPUT_LENGTH(const char* id_pChar);
    
    //&---------------------------------------------------------------------*
    //&      Method  GET_CHARS_OUTPUT_LENGTH
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    static const int GET_BYTES_OUTPUT_LENGTH(const unsigned char* id_pBytes);

    //&---------------------------------------------------------------------*
    //&      Method  GET_CENTER_OFFSET
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    static const int GET_CENTER_OFFSET(const int id_containerWidth, const int id_widthToCenter);

    //&---------------------------------------------------------------------*
    //&      Method  getCharsOutputLength
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const int getCharsOutputLength();
    
// =============================
// ======= P R I V A T E =======
private:
    
    //&---------------------------------------------------------------------*
    //&      Method  drawCharAtPos
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void drawCharAtPos(const char id_char, const int id_x, const int id_y,
                       sf::RenderTarget& id_rTarget, sf::RenderStates id_states) const;

    //&---------------------------------------------------------------------*
    //&      Method  drawCharAtPos
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void drawByteAtPos(const unsigned char id_byte, const int id_x, const int id_y,
                       sf::RenderTarget& id_rTarget, sf::RenderStates id_states) const;

    //&---------------------------------------------------------------------*
    //&      Method  drawCharsAtPos
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void drawCharsAtPos(const char* id_pChar, const int id_x, const int id_y,
                        sf::RenderTarget& id_rTarget, sf::RenderStates id_states) const;
    
    //&---------------------------------------------------------------------*
    //&      Method  drawBytesAtPos
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void drawBytesAtPos(const unsigned char* id_pBytes, const int id_x, const int id_y,
                        sf::RenderTarget& id_rTarget, sf::RenderStates id_states) const;

    //&---------------------------------------------------------------------*
    //&      Method  loadTexture
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool loadTexture();
    
    //&---------------------------------------------------------------------*
    //&      Method  draw
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void draw(sf::RenderTarget& id_rTarget, sf::RenderStates id_states) const;
    
	sf::RenderWindow* m_pWindow = NULL;

    const char* m_pStr = NULL;
    int m_x = 0;
    int m_y = 0;
    
    int m_outputLength = 0;
    
    static sf::Texture m_fontTexture;
    static bool m_loaded;
    
    static const int CHAR_PIXEL_HEIGHT = 65;
    static const int CHAR_PIXEL_WIDTH = 36;
    static const int CHARS_PER_ROW = 16;
    static const int CHARS_PER_COLUMN = 16;
    static const int SPACING = 4;
    
    static const int MAX_CHARS_TO_PRINT = 1000;

    static const char TAB = 0x09;
    static const char LINE_FEED = 0x0A;
    static const char CARRIAGE_RETURN = 0x0D;
    static const char SPACE = 0x20;

};

#endif /* defined(__Blokade__GFXFont__hpp) */
