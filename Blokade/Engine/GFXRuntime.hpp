//***************************************************************************
//
//  GFXRuntime.hpp
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

#ifndef __Blokade__GFXRuntime__hpp
#define __Blokade__GFXRuntime__hpp

#pragma once

#include <SFML/Graphics.hpp>
#include <list>

//&=========================================================================*
//&      Class  GFXRuntime
//&=========================================================================*
//
//==========================================================================*
class GFXRuntime {
    
// =============================
// ======== P U B L I C ========
public:

    enum KEY {
        RETURN = 0,
        ESCAPE,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        SPACE
    };
    
    //&---------------------------------------------------------------------*
    //&      Constructor  GFXRuntime
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    GFXRuntime();

    //&---------------------------------------------------------------------*
    //&      Constructor  GFXRuntime
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    GFXRuntime(sf::RenderWindow& id_rWindow);
    
    //&---------------------------------------------------------------------*
    //&      Destructor  ~GFXRuntime
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    ~GFXRuntime() {}

    //&---------------------------------------------------------------------*
    //&      Method  updateTime
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void update();

    //&---------------------------------------------------------------------*
    //&      Method  getRenderWindow
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    sf::RenderWindow* getWindow();
    
    //&---------------------------------------------------------------------*
    //&      Method  getTime
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const sf::Time getTimeElapsed();
    
    //&---------------------------------------------------------------------*
    //&      Method  isKeyPressedDown
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool isKeyPressed(const KEY id_key);
    
    //&---------------------------------------------------------------------*
    //&      Method  isKeyDown
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool isKeyDown(const KEY id_key);

// =============================
// ======= P R I V A T E =======
private:
    
	sf::RenderWindow* m_pWindow;
    sf::Time m_elapsed;
	sf::Clock m_clock;
        
    enum STATE {
        IS_DOWN = 0,
        WAS_DOWN,
        PRESSED
    };
    
    static const int MAX_KEYS = 7;
    
    bool m_keys[MAX_KEYS][3] = { false, false, false,
                                 false, false, false,
                                 false, false, false,
                                 false, false, false,
                                 false, false, false,
                                 false, false, false,
                                 false, false, false };
    
    std::list<int> m_tmpKeys;

};

#endif /* defined(__Blokade__GFXRuntime__hpp) */
