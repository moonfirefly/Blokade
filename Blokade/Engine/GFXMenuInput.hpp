//***************************************************************************
//
//  GFXMenuInput.hpp
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

#ifndef __Blokade__GFXMenuInput__hpp
#define __Blokade__GFXMenuInput__hpp

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "GFXMenuItem.hpp"
#include "GFXFont.hpp"
#include "GFXBean.hpp"
#include "../ResourcePath.hpp"
#include "../Game/i18n.hpp"

//&=========================================================================*
//&      Class  GFXMenuInput
//&=========================================================================*
//
//==========================================================================*
class GFXMenuInput : public GFXMenuItem {
    
    // =============================
    // ======== P U B L I C ========
public:
    
    //&---------------------------------------------------------------------*
    //&      Constructor  GFXMenuInput
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    GFXMenuInput() {}
    
    //&---------------------------------------------------------------------*
    //&      Destructor  ~GFXMenuInput
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    ~GFXMenuInput() {}
    
    //&---------------------------------------------------------------------*
    //&      Method  init
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool init(const std::string id_label, const int id_tag, const int id_maxChars);
    
    //&---------------------------------------------------------------------*
    //&      Method  init
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool init(const std::string id_label, const int id_x, const int id_y, const int id_tag,
              const int id_maxChars);
    
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
    void update(GFXRuntime* id_pRuntime);
    
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
    void reset(const bool id_clearInputValue);
    
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
    //&      Method  moveCursorRight
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void moveCursorRight();
    
    //&---------------------------------------------------------------------*
    //&      Method  moveCursorLeft
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void moveCursorLeft();
    
    //&---------------------------------------------------------------------*
    //&      Method  getInputValue
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const std::string getInputValue();
    
    //&---------------------------------------------------------------------*
    //&      Method  setInputValue
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setInputValue(const std::string id_value);
    
    //&---------------------------------------------------------------------*
    //&      Method  getInputFinished
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const bool getInputFinished();
    
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
    
    static const int LABEL_X_OFFSET = 50;
    static const int LABEL_Y_OFFSET = 23;
    
    std::string m_input = "";
    int m_cursorLocation = 0;
    
    int m_tag = -1;
    int m_maxChars = 0;
    bool m_inputFinished = false;
    
    static const int CURSOR_BLINK_DELAY = 150;
    int m_cursorBlinkCount = 0;
    bool m_showCursor = false;
    
    int m_x = 0;
    int m_y = 0;
    
    GFXFont m_fontLabel;
    GFXFont m_fontValue;
    GFXFont m_fontCursor;
    
    sf::Sprite m_normalSprite;
    sf::Sprite m_selectedSprite;
    sf::FloatRect m_clickSurfaceRect;
    
    bool m_isSelected;
    
    static const int BUTTON_WIDTH = 650;
    static const int BUTTON_HEIGHT = 120;
    static const int INDEX_NORMAL = 1;
    static const int INDEX_SELECTED = 0;
    
};


#endif /* defined(__Blokade__GFXMenuInput__hpp) */
