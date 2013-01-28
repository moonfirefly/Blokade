//***************************************************************************
//
//  SoundMngr.hpp
//  Blokade
//
//  Created by moonfirefy on 2013-01-26.
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

#ifndef __Blokade__SoundMngr__hpp
#define __Blokade__SoundMngr__hpp

#pragma once

#include <SFML/Audio.hpp>
#include "../Engine/GFXBean.hpp"
#include "i18n.hpp"
#include "../ResourcePath.hpp"

//&=========================================================================*
//&      Class  SoundMngr
//&=========================================================================*
//
//==========================================================================*
class SoundMngr {

// =============================
// ======== P U B L I C ========
public:

    enum VOLUME {
        MUTED = 0,
        PERCENT_20,
        PERCENT_40,
        PERCENT_60,
        PERCENT_80,
        PERCENT_100
    };

    enum SOUND {
        NO_SOUND = 0,
        SHAPE_IN_PLACE,
        SHAPE_MOVE,
        SHAPE_ROTATE,
        LINE_BLOCK_DESTROY,
        FOLD_ON_EMPTY_LINES,
        LEVEL_UP,
        DIED
    };

    enum MUSIC {
        NO_MUSIC = 0,
        MAIN_MENU,
        GAME
    };

    //&---------------------------------------------------------------------*
    //&      Constructor  SoundMngr
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    SoundMngr();

    //&---------------------------------------------------------------------*
    //&      Destructor  SoundMngr
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    ~SoundMngr() {};

    //&---------------------------------------------------------------------*
    //&      Method  loadSoundFiles
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void loadSoundFiles();

    //&---------------------------------------------------------------------*
    //&      Method  setSoundVolume
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setSoundVolume(const VOLUME id_volume);

    //&---------------------------------------------------------------------*
    //&      Method  getSoundVolume
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const VOLUME getSoundVolume();

    //&---------------------------------------------------------------------*
    //&      Method  setMusicVolume
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setMusicVolume(const VOLUME id_volume);

    //&---------------------------------------------------------------------*
    //&      Method  getMusicVolume
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const VOLUME getMusicVolume();

    //&---------------------------------------------------------------------*
    //&      Method  playSound
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void playSound(const SOUND id_sound);

    //&---------------------------------------------------------------------*
    //&      Method  playMusic
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void playMusic(const MUSIC id_music);

    //&---------------------------------------------------------------------*
    //&      Method  stopMusic
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void stopMusic(const MUSIC id_music);

    //&---------------------------------------------------------------------*
    //&      Method  pauseMusic
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void pauseMusic(const MUSIC id_music);

    //&---------------------------------------------------------------------*
    //&      Method  intToVolume
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    VOLUME intToVolume(const int id_integer); // 0 to 5


    //&---------------------------------------------------------------------*
    //&      Method  volumeToInt
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const int volumeToInt(const VOLUME id_volume); // 0 to 5

    //&---------------------------------------------------------------------*
    //&      Method  getVolumeBeans
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const std::vector<GFXBean>* getVolumeBeans();

// =============================
// ======= P R I V A T E =======
private:

    //&---------------------------------------------------------------------*
    //&      Method  playSound
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void playSound(sf::Sound* id_pSound);

    //&---------------------------------------------------------------------*
    //&      Method  stopSound
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void stopSound(sf::Sound* id_pSound);

    //&---------------------------------------------------------------------*
    //&      Method  playSoundNoStop
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void playSoundNoStop(sf::Sound* id_pSound);

    static const float LEVEL_UP_BASE_VOLUME;
    static const float DIED_BASE_VOLUME;
    static const float LINE_BLOCK_DESTROY_BASE_VOLUME;
    static const float SHAPE_IN_PLACE_BASE_VOLUME;
    static const float FOLD_BASE_VOLUME;
    static const float FOLD_BASE_PITCH;
    static const float SHAPE_MOVE_BASE_VOLUME;
    static const float SHAPE_ROTATE_BASE_VOLUME;
    static const float SHAPE_ROTATE_BASE_PITCH;
    static const float MENU_MUSIC_BASE_VOLUME;
    static const float GAME_MUSIC_BASE_VOLUME;

    VOLUME m_soundVolume = VOLUME::PERCENT_100;
    VOLUME m_musicVolume = VOLUME::PERCENT_100;

    static const float VOLUME_PERCENT[6];

    sf::Music m_gameMusic;
    sf::Music m_menuMusic;

    sf::SoundBuffer m_soundBufferShapeInPlace;
    sf::Sound m_soundShapeInPlace;
    sf::SoundBuffer m_soundBufferShapeMove;
    sf::Sound m_soundShapeMove;
    sf::SoundBuffer m_soundBufferShapeRotate;
    sf::Sound m_soundShapeRotate;
    sf::SoundBuffer m_soundBufferLineBlockDestroy;
    sf::Sound m_soundLineBlockDestroy;
    sf::SoundBuffer m_soundBufferFold;
    sf::Sound m_soundFold;
    sf::SoundBuffer m_soundBufferLevelUp;
    sf::Sound m_soundLevelUp;
    sf::SoundBuffer m_soundBufferDied;
    sf::Sound m_soundDied;

    std::vector<GFXBean> m_volumeBeans;

};

#endif /* defined(__Blokade__SoundMngr__hpp) */
