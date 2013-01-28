//***************************************************************************
//
//  GFXMenu.cpp
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

#include "GFXMenu.hpp"

//&---------------------------------------------------------------------*
//&      Method  addItem
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenu::addItem(GFXMenuItem* id_pItem) {
    m_items.push_back(id_pItem);
    if (id_pItem->getType() == GFXMenuItem::TYPE::VALUE_SELECTOR) {
        m_includesSelector = true;
    }
    // Select first item added to the menu (default selection)
    if (m_items.size() == 1) {
        selectItemByIndex(0);
    }
}

//&---------------------------------------------------------------------*
//&      Method  setPosition
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenu::setPosition(const int id_x, const int id_y) {
    m_x = id_x;
    m_y = id_y;
    int index = 0;
    for (std::vector<GFXMenuItem*>::const_iterator i = m_items.begin(); i != m_items.end(); ++i, index++) {
        int offset = 0;
        if (m_includesSelector && (*i)->getType() == GFXMenuItem::TYPE::BUTTON) {
            offset = (650 - 338) / 2;
        }
        (*i)->setPosition(m_x + offset, m_y + (index * m_lineHeight));
    }
}

//&---------------------------------------------------------------------*
//&      Method  getX
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const int GFXMenu::getX() const {
    return m_x;
}

//&---------------------------------------------------------------------*
//&      Method  getY
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const int GFXMenu::getY() const {
    return m_y;
}

//&---------------------------------------------------------------------*
//&      Method  getSelectedButtonTag
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
GFXMenuItem* GFXMenu::getSelectedItem() {
    if (m_selectedItemIndex >= 0) {
        return m_items.at(m_selectedItemIndex);
    }
    else {
        return NULL;
    }
}

//&---------------------------------------------------------------------*
//&      Method  getPressedButtonTag
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
GFXMenuItem* GFXMenu::getPressedItem() {
    if (m_pressedItemIndex >= 0) {
        return m_items.at(m_pressedItemIndex);
    }
    else {
        return NULL;
    }
}

//&---------------------------------------------------------------------*
//&      Method  getNewSelectionItem
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
GFXMenuItem* GFXMenu::getNewSelectionItem() {
    if (m_newSelectionIndex >= 0) {
        return m_items.at(m_newSelectionIndex);
    }
    else {
        return NULL;
    }
}

//&---------------------------------------------------------------------*
//&      Method  getNewSelectedValue
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const GFXBean* GFXMenu::getNewSelectedValue() {
    return m_newSelectedBean;
}

//&---------------------------------------------------------------------*
//&      Method  getItemByTag
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
GFXMenuItem* GFXMenu::getItemByTag(const int id_tag) {
    for (std::vector<GFXMenuItem*>::const_iterator i = m_items.begin(); i != m_items.end(); ++i) {
        if ((**i).getTag() == id_tag) {
            return (*i);
        }
    }
    return NULL;
}

//&---------------------------------------------------------------------*
//&      Method  selectedButtonByTag
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenu::selectItemByTag(const int id_tag) {
    m_selectedItemIndex = -1;
    int index = 0;
    for (std::vector<GFXMenuItem*>::const_iterator i = m_items.begin(); i != m_items.end(); ++i, index++) {
        if ((**i).getTag() == id_tag) {
            (**i).setSelected(true);
            m_selectedItemIndex = index;
        }
        else {
            (**i).setSelected(false);
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  selectItemByIndex
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenu::selectItemByIndex(const int id_index) {
    m_selectedItemIndex = -1;
    int index = 0;
    for (std::vector<GFXMenuItem*>::const_iterator i = m_items.begin(); i != m_items.end(); ++i, index++) {
        if (index == id_index) {
            (**i).setSelected(true);
            m_selectedItemIndex = index;
        }
        else {
            (**i).setSelected(false);
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  setTitle
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXMenu::setTitle(const char* id_pTitle, const int id_x, const int id_y) {
    if (!m_titleSet) {
        if (!m_titleTexture.loadFromFile(resourcePath() + "menuValueSelectorTitle.png")) {
            return false;
        }
        m_titleSprite = sf::Sprite(m_titleTexture);
        m_titleSet = true;
    }

    m_titleSprite.setPosition(id_x, id_y);    
    m_title = id_pTitle;
    
    return true;
}

//&---------------------------------------------------------------------*
//&      Method  update
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenu::update(GFXRuntime* id_pRuntime) {
    m_pressedItemIndex = -1;
    m_newSelectionIndex = -1;
    m_newSelectedBean = NULL;

    if (m_selectedItemIndex >= 0) {
        if (id_pRuntime->isKeyPressed(GFXRuntime::KEY::DOWN)) {
            if (m_selectedItemIndex < (m_items.size() - 1)) {
                selectItemByIndex(m_selectedItemIndex + 1);
            }
        }
        else if (id_pRuntime->isKeyPressed(GFXRuntime::KEY::UP)) {
            if (m_selectedItemIndex > 0) {
                selectItemByIndex(m_selectedItemIndex - 1);
            }
        }
        else if (id_pRuntime->isKeyPressed(GFXRuntime::KEY::LEFT)) {
            ((GFXMenuItem*) m_items.at(m_selectedItemIndex))->selectPreviousValue();
            identifyNewSelection();
        }
        else if (id_pRuntime->isKeyPressed(GFXRuntime::KEY::RIGHT)) {
            ((GFXMenuItem*) m_items.at(m_selectedItemIndex))->selectNextValue();
            identifyNewSelection();
        }
        else if (id_pRuntime->isKeyPressed(GFXRuntime::KEY::RETURN)) {
            m_pressedItemIndex = m_selectedItemIndex;
        }
    }
    
    for (std::vector<GFXMenuItem*>::const_iterator i = m_items.begin(); i != m_items.end(); ++i) {
        (**i).update(id_pRuntime);
    }
}

//&---------------------------------------------------------------------*
//&      Method  identifyNewSelection
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenu::identifyNewSelection() {
    m_newSelectionIndex = m_selectedItemIndex;
    m_newSelectedBean = ((GFXMenuItem*) m_items.at(m_selectedItemIndex))->getSelectedValue();
}

//&---------------------------------------------------------------------*
//&      Method  draw
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenu::draw(sf::RenderTarget& id_rTarget, sf::RenderStates id_states) const {
    if (m_titleSet) {
        id_rTarget.draw(m_titleSprite, id_states);
    }
    for (std::vector<GFXMenuItem*>::const_iterator i = m_items.begin(); i != m_items.end(); ++i) {
        id_rTarget.draw((**i), id_states);
    }
}

//&---------------------------------------------------------------------*
//&      Method  setLineHeight
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXMenu::setLineHeight(const int id_height) {
    m_lineHeight = id_height;
}

