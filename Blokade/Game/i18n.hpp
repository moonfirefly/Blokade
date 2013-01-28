//***************************************************************************
//
//  i18n.hpp
//  Blokade
//
//  Created by moonfirefy on 2013-01-27.
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

#ifndef __Blokade_i18n_hpp
#define __Blokade_i18n_hpp

#pragma once

//&=========================================================================*
//&      Class  i18n
//&=========================================================================*
//
//==========================================================================*
class i18n {
    
// =============================
// ======== P U B L I C ========
public:
    
    enum LANGUAGE {
        ENGLISH = 0,
        FRENCH,
    };
    
    i18n() {}
    
    ~i18n() {}
    
#ifdef BLOKADE_LANGUAGE_FR
    static const LANGUAGE m_language = LANGUAGE::FRENCH;
#else
    static const LANGUAGE m_language = LANGUAGE::ENGLISH;
#endif

    static const unsigned char* START;
    static const unsigned char* OPTIONS;
    static const unsigned char* EXIT;
    static const unsigned char* SOUND;
    static const unsigned char* MUSIC;
    static const unsigned char* BACK;
    static const unsigned char* LEVEL;
    static const unsigned char* LINES;
    static const unsigned char* TOP;
    static const unsigned char* SCORE;
    static const unsigned char* NEXT;
    static const unsigned char* PAUSE;
    static const unsigned char* GAME_OVER;
    static const unsigned char* QUIT;
    static const unsigned char* RESUME;
    static const unsigned char* RESTART;
    static const unsigned char* MUTED;
    
};

#endif
