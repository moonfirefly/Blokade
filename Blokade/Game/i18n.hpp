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

#include <string>

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
    
    // Characters over 128 ascii code and control characters, this ensures
    // cross-platform compatibility and avoids automatic UTF16 in Xcode.
    // (wouldn't be required if Windows was the only target OS)
    static const std::string ASCII_EACUTE;
    static const std::string ASCII_TAB;
    static const std::string ASCII_CARRIAGE_RETURN;
    static const std::string ASCII_UEACUTE;
    static const std::string ASCII_BLOCK;

    i18n() {}
    
    ~i18n() {}
    
#ifdef BLOKADE_LANGUAGE_FR
    static const LANGUAGE m_language = LANGUAGE::FRENCH;
#else
    static const LANGUAGE m_language = LANGUAGE::ENGLISH;
#endif

    static const std::string START;
    static const std::string OPTIONS;
    static const std::string EXIT;
    static const std::string SOUND;
    static const std::string MUSIC;
    static const std::string BACK;
    static const std::string LEVEL;
    static const std::string LINES;
    static const std::string TOP;
    static const std::string SCORE;
    static const std::string NEXT;
    static const std::string PAUSE;
    static const std::string GAME_OVER;
    static const std::string QUIT;
    static const std::string RESUME;
    static const std::string RESTART;
    static const std::string MUTED;
    
};

#endif


