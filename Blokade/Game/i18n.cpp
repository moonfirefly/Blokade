//***************************************************************************
//
//  i18n.cpp
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

#include "i18n.hpp"

// Characters over 128 ascii code, this ensures cross-platform
// compatibility and avoids automatic UTF16 in Xcode
// (wouldn't be required if Windows was the only target OS)
const std::string i18n::ASCII_EACUTE = "\xe9";            // 233  é
const std::string i18n::ASCII_UEACUTE = "\xc9";           // 201  É
const std::string i18n::ASCII_TAB = "\x09";               // 9    TAB
const std::string i18n::ASCII_CARRIAGE_RETURN = "\x0d";   // 13   CR
const std::string i18n::ASCII_BLOCK = "\x1c";             // 28   (block)

#ifdef BLOKADE_LANGUAGE_FR
const std::string i18n::START = "Jouer";
const std::string i18n::OPTIONS = "Options";
const std::string i18n::EXIT = "Sortie";
const std::string i18n::SOUND = "Son";
const std::string i18n::MUSIC = "Musique";
const std::string i18n::BACK = "Retour";
const std::string i18n::LEVEL = "Niveau";
const std::string i18n::LINES = "Lignes";
const std::string i18n::TOP = "Record";
const std::string i18n::SCORE = "Points";
const std::string i18n::SCORES = "Records";
const std::string i18n::NEXT = "Suivant";
const std::string i18n::PAUSE = "*Pause*";
const std::string i18n::GAME_OVER = "TERMIN" + i18n::ASCII_UEACUTE;
const std::string i18n::QUIT = "Quitter";
const std::string i18n::RESUME = "Continuer";
const std::string i18n::RESTART = "Rejouer";
const std::string i18n::MUTED = "silence";
const std::string i18n::NAME = "Nom";
const std::string i18n::NEW_SCORE = "Nouveau record!";
const std::string i18n::TOP_SCORES = "* Top points *";
const std::string i18n::TOP_LINES = "* Top lignes *";
#else
const std::string i18n::START = "Start";
const std::string i18n::OPTIONS = "Options";
const std::string i18n::EXIT = "Exit";
const std::string i18n::SOUND = "Sound";
const std::string i18n::MUSIC = "Music";
const std::string i18n::BACK = "Back";
const std::string i18n::LEVEL = "Level";
const std::string i18n::LINES = "Lines";
const std::string i18n::TOP = "Top";
const std::string i18n::SCORE = "Score";
const std::string i18n::SCORES = "Scores";
const std::string i18n::NEXT = "Next";
const std::string i18n::PAUSE = "*Pause*";
const std::string i18n::GAME_OVER = "GAME OVER";
const std::string i18n::QUIT = "Quit";
const std::string i18n::RESUME = "Resume";
const std::string i18n::RESTART = "Restart";
const std::string i18n::MUTED = "muted";
const std::string i18n::NAME = "Name";
const std::string i18n::NEW_SCORE = "New record!";
const std::string i18n::TOP_SCORES = "* Top Scores *";
const std::string i18n::TOP_LINES = "* Top Lines *";
#endif


