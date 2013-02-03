//***************************************************************************
//
//  GFXRuntime.cpp
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

#include "GFXRuntime.hpp"

//&---------------------------------------------------------------------*
//&      Constructor  GFXRuntime
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
GFXRuntime::GFXRuntime(sf::RenderWindow& id_rWindow) {
    m_pWindow = &id_rWindow;
    m_clock.restart();
}

//&---------------------------------------------------------------------*
//&      Method  reset
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXRuntime::reset() {
    m_charTyped = 0;
    m_keyPressed = sf::Keyboard::Key::KeyCount;
}

//&---------------------------------------------------------------------*
//&      Method  setCharTyped
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXRuntime::setCharTyped(const sf::Uint32 id_ascii) {
    m_charTyped = (id_ascii >= 32 && id_ascii < 128) ? id_ascii : 0;
}

//&---------------------------------------------------------------------*
//&      Method  getCharTyped
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const char GFXRuntime::getCharTyped() {
    return static_cast<char>(m_charTyped);
}

//&---------------------------------------------------------------------*
//&      Method  updateTime
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXRuntime::update() {
    // Time
    m_elapsed = m_clock.restart();

    // Keyboard input
    for (int i = 0; i < MAX_KEYS; i++) {
        m_keys[i][STATE::IS_DOWN] = false;
        m_keys[i][STATE::PRESSED] = false;
    }
    
    m_tmpKeys.clear();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_tmpKeys.push_back(KEY::DOWN);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_tmpKeys.push_back(KEY::UP);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_tmpKeys.push_back(KEY::LEFT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_tmpKeys.push_back(KEY::RIGHT);
    }
/*    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        m_tmpKeys.push_back(KEY::RETURN);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        m_tmpKeys.push_back(KEY::ESCAPE);
    }*/
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        m_tmpKeys.push_back(KEY::SPACE);
    }
    
    for (std::list<int>::iterator i = m_tmpKeys.begin(); i != m_tmpKeys.end(); ++i) {
        m_keys[(*i)][STATE::IS_DOWN] = true;
        if (!m_keys[(*i)][STATE::WAS_DOWN]) {
            m_keys[(*i)][STATE::PRESSED] = true;
        }
    }

    for (int i = 0; i < MAX_KEYS; i++) {
        m_keys[i][STATE::WAS_DOWN] = m_keys[i][STATE::IS_DOWN];
    }
}

//&---------------------------------------------------------------------*
//&      Method  getRenderWindow
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
sf::RenderWindow* GFXRuntime::getWindow() {
    return m_pWindow;
}

//&---------------------------------------------------------------------*
//&      Method  getTime
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const sf::Time GFXRuntime::getTimeElapsed() {
    return m_elapsed;
}

//&---------------------------------------------------------------------*
//&      Method  isKeyPressed
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXRuntime::isKeyPressed(const KEY id_key) {
    return m_keys[id_key][STATE::PRESSED];
}

//&---------------------------------------------------------------------*
//&      Method  isKeyDown
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXRuntime::isKeyDown(const KEY id_key) {
    return m_keys[id_key][STATE::IS_DOWN];
}

//&---------------------------------------------------------------------*
//&      Method  setKeyPressed
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXRuntime::setKeyPressed(const sf::Keyboard::Key id_key) {
    m_keyPressed = id_key;
}

//&---------------------------------------------------------------------*
//&      Method  getKeyPressed
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const sf::Keyboard::Key GFXRuntime::getKeyPressed() {
    return m_keyPressed;
}

//&---------------------------------------------------------------------*
//&      Method  isKeyPressed
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXRuntime::isKeyPressed() {
    return (m_keyPressed != sf::Keyboard::Key::KeyCount) ? true : false;
}


