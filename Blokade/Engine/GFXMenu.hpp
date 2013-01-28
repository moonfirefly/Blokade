//***************************************************************************
//
//  GFXMenu.hpp
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

#ifndef __Blokade__GFXMenu__hpp
#define __Blokade__GFXMenu__hpp

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "GFXMenuItem.hpp"
#include "GFXRuntime.hpp"
#include "ResourcePath.hpp"

//&=========================================================================*
//&      Class  GFXMenu
//&=========================================================================*
//
//==========================================================================*
class GFXMenu : public sf::Drawable {
    
// =============================
// ======== P U B L I C ========
public:
    
    //&---------------------------------------------------------------------*
    //&      Constructor  GFXMenu
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    GFXMenu() {}
        
    //&---------------------------------------------------------------------*
    //&      Destructor  ~GFXMenu
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    ~GFXMenu() {}
    
    //&---------------------------------------------------------------------*
    //&      Method  addItem
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void addItem(GFXMenuItem* id_pItem);
    
    //&---------------------------------------------------------------------*
    //&      Method  setPosition
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setPosition(const int id_x, const int id_y);
    
    //&---------------------------------------------------------------------*
    //&      Method  getX
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const int getX() const;

    //&---------------------------------------------------------------------*
    //&      Method  getY
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const int getY() const;
    
    //&---------------------------------------------------------------------*
    //&      Method  getSelectedButtonTag
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    GFXMenuItem* getSelectedItem();
    
    //&---------------------------------------------------------------------*
    //&      Method  getPressedButtonTag
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    GFXMenuItem* getPressedItem();

    //&---------------------------------------------------------------------*
    //&      Method  getNewSelectionItem
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    GFXMenuItem* getNewSelectionItem();
    
    //&---------------------------------------------------------------------*
    //&      Method  getNewSelectedValue
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const GFXBean* getNewSelectedValue();

    //&---------------------------------------------------------------------*
    //&      Method  getItemByTag
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    GFXMenuItem* getItemByTag(const int id_tag);
    
    //&---------------------------------------------------------------------*
    //&      Method  selectedButtonByTag
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void selectItemByTag(const int id_tag);
    
    //&---------------------------------------------------------------------*
    //&      Method  selectItemByIndex
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void selectItemByIndex(const int id_index);
    
    //&---------------------------------------------------------------------*
    //&      Method  setTitle
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool setTitle(const char* id_pTitle, const int id_x, const int id_y);

    //&---------------------------------------------------------------------*
    //&      Method  update
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void update(GFXRuntime* id_pRuntime);
    
    //&---------------------------------------------------------------------*
    //&      Method  setLineHeight
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setLineHeight(const int id_height);
        
// =============================
// ======= P R I V A T E =======
private:
    
    //&---------------------------------------------------------------------*
    //&      Method  draw
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void draw(sf::RenderTarget& id_rTarget, sf::RenderStates id_states) const;

    //&---------------------------------------------------------------------*
    //&      Method  identifyNewSelection
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void identifyNewSelection();
    
    sf::Texture m_titleTexture;
    sf::Sprite m_titleSprite;
    bool m_titleSet = false;
    
    int m_pressedItemIndex = -1;
    int m_selectedItemIndex = -1;
    int m_newSelectionIndex = -1;
    const GFXBean* m_newSelectedBean = NULL;
    
    int m_lineHeight = 100;

    bool m_includesSelector = false;
    
    std::vector<GFXMenuItem*> m_items;
    
    const char* m_title = NULL;
    int m_titleX = 0;
    int m_titleY = 0;
    
    int m_x = 0;
    int m_y = 0;
    
};

#endif /* defined(__Blokade__GFXMenu__hpp) */
