//***************************************************************************
//
//  GFXEngine.hpp
//  Blokade
//
//  Created by moonfirefy on 2013-01-11.
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

#ifndef __Blokade_GFXEngine_hpp
#define __Blokade_GFXEngine_hpp

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GFXRuntime.hpp"

//&=========================================================================*
//&      Class  GFXEngine
//&=========================================================================*
//
//==========================================================================*
class GFXEngine {

// =============================
// ======== P U B L I C ========
public:

    //&---------------------------------------------------------------------*
    //&      Constructor  GFXEngine
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    GFXEngine( const int id_winWidth, const int id_winHeight, const std::string id_winTitle);
    
    //&---------------------------------------------------------------------*
    //&      Destructor  ~GFXEngine
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    ~GFXEngine();

    //&---------------------------------------------------------------------*
    //&      Method  init
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
	virtual bool init() { return true; }
    
    //&---------------------------------------------------------------------*
    //&      Method  input
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void input() {}
    
    //&---------------------------------------------------------------------*
    //&      Method  update
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void update() {}
    
    //&---------------------------------------------------------------------*
    //&      Method  render
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void render() {}

    //&---------------------------------------------------------------------*
    //&      Method  run
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool run();

    //&---------------------------------------------------------------------*
    //&      Method  pause
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void pause() {}

    //&---------------------------------------------------------------------*
    //&      Method  resume
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    virtual void resume() {}
    
    //&---------------------------------------------------------------------*
    //&      Method  shutdown
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void shutdown();

// =============================
// ===== P R O T E C T E D =====
protected:

    GFXRuntime m_runtime;

// =============================
// ======= P R I V A T E =======
private:
	
    sf::RenderWindow* m_pWindow;

};

#endif /* defined(__Blokade_GFXEngine_hpp) */
