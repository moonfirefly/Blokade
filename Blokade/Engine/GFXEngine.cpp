//***************************************************************************
//
//  GFXEngine.cpp
//  Blokade
//
//  Created by moonfirefy on 2013-01-13.
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

#include "GFXEngine.hpp"

//&---------------------------------------------------------------------*
//&      Constructor  GFXEngine
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
GFXEngine::GFXEngine( const int id_winWidth, const int id_winHeight, const std::string id_winTitle) {
    m_pWindow = new sf::RenderWindow(sf::VideoMode(id_winWidth, id_winHeight, 32), id_winTitle, sf::Style::Close);
    m_pWindow->setKeyRepeatEnabled(false);
    m_pWindow->setVerticalSyncEnabled(true);
    
    m_runtime = GFXRuntime(*m_pWindow);
    
    srand( (unsigned)time(NULL) );
}

//&---------------------------------------------------------------------*
//&      Destructor  ~GFXEngine
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
GFXEngine::~GFXEngine() {
    delete m_pWindow;
}

//&---------------------------------------------------------------------*
//&      Method  run
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool GFXEngine::run() {
    sf::Event event;
    
    if(!init()) {
        return false;
    }
    
    while(m_pWindow->isOpen()) {
        m_runtime.update();
        while(m_pWindow->pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:
                    shutdown();
                    break;
                default:
                    break;
            }
        }
        input();
        update();
        render();
        m_pWindow->display();
    }
    
    return true;
}

//&---------------------------------------------------------------------*
//&      Method  shutdown
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void GFXEngine::shutdown() {
    m_pWindow->close();
}



