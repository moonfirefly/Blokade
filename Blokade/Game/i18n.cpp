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

#ifdef BLOKADE_LANGUAGE_FR
const unsigned char* i18n::START = (const unsigned char*)"Jouer";
const unsigned char* i18n::OPTIONS = (const unsigned char*)"Options";
const unsigned char* i18n::EXIT = (const unsigned char*)"Sortie";
const unsigned char* i18n::SOUND = (const unsigned char*)"Son";
const unsigned char* i18n::MUSIC = (const unsigned char*)"Musique";
const unsigned char* i18n::BACK = (const unsigned char*)"Retour";
const unsigned char* i18n::LEVEL = (const unsigned char*)"Niveau";
const unsigned char* i18n::LINES = (const unsigned char*)"Lignes";
const unsigned char* i18n::TOP = (const unsigned char*)"Record";
const unsigned char* i18n::SCORE = (const unsigned char*)"Points";
const unsigned char* i18n::NEXT = (const unsigned char*)"Suivant";
const unsigned char* i18n::PAUSE = (const unsigned char*)"*Pause*";
const unsigned char* i18n::GAME_OVER = (const unsigned char*)"TERMIN\xc9";
const unsigned char* i18n::QUIT = (const unsigned char*)"Quitter";
const unsigned char* i18n::RESUME = (const unsigned char*)"Continuer";
const unsigned char* i18n::RESTART = (const unsigned char*)"Rejouer";
const unsigned char* i18n::MUTED = (const unsigned char*)"silence";
#else
const unsigned char* i18n::START = (const unsigned char*)"Start";
const unsigned char* i18n::OPTIONS = (const unsigned char*)"Options";
const unsigned char* i18n::EXIT = (const unsigned char*)"Exit";
const unsigned char* i18n::SOUND = (const unsigned char*)"Sound";
const unsigned char* i18n::MUSIC = (const unsigned char*)"Music";
const unsigned char* i18n::BACK = (const unsigned char*)"Back";
const unsigned char* i18n::LEVEL = (const unsigned char*)"Level";
const unsigned char* i18n::LINES = (const unsigned char*)"Lines";
const unsigned char* i18n::TOP = (const unsigned char*)"Top";
const unsigned char* i18n::SCORE = (const unsigned char*)"Score";
const unsigned char* i18n::NEXT = (const unsigned char*)"Next";
const unsigned char* i18n::PAUSE = (const unsigned char*)"*Pause*";
const unsigned char* i18n::GAME_OVER = (const unsigned char*)"GAME OVER";
const unsigned char* i18n::QUIT = (const unsigned char*)"Quit";
const unsigned char* i18n::RESUME = (const unsigned char*)"Resume";
const unsigned char* i18n::RESTART = (const unsigned char*)"Restart";
const unsigned char* i18n::MUTED = (const unsigned char*)"muted";
#endif
