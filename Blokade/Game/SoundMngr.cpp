//***************************************************************************
//
//  SoundMngr.cpp
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

#include "SoundMngr.hpp"

// Initialize static members
const float SoundMngr::LEVEL_UP_BASE_VOLUME = 75.0f;
const float SoundMngr::DIED_BASE_VOLUME = 100.0f;
const float SoundMngr::LINE_BLOCK_DESTROY_BASE_VOLUME = 70.0f;
const float SoundMngr::SHAPE_IN_PLACE_BASE_VOLUME = 65.0f;
const float SoundMngr::FOLD_BASE_VOLUME = 100.0f;
const float SoundMngr::FOLD_BASE_PITCH = 0.6f;
const float SoundMngr::SHAPE_MOVE_BASE_VOLUME = 100.0f;
const float SoundMngr::SHAPE_ROTATE_BASE_VOLUME = 100.0f;
const float SoundMngr::SHAPE_ROTATE_BASE_PITCH = 0.7f;
const float SoundMngr::MENU_MUSIC_BASE_VOLUME = 55.0f;
const float SoundMngr::GAME_MUSIC_BASE_VOLUME = 55.0f;
const float SoundMngr::VOLUME_PERCENT[] = { 0.0f, 0.2f, 0.4f, 0.6f, 0.8f, 1.0f };

//&---------------------------------------------------------------------*
//&      Constructor  SoundMngr
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
SoundMngr::SoundMngr() {
    // Setup volume beans for menu selector
    m_volumeBeans.push_back(GFXBean(i18n::MUTED,0));
    m_volumeBeans.push_back(GFXBean("\x1c    ",1));
    m_volumeBeans.push_back(GFXBean("\x1c\x1c   ",2));
    m_volumeBeans.push_back(GFXBean("\x1c\x1c\x1c  ",3));
    m_volumeBeans.push_back(GFXBean("\x1c\x1c\x1c\x1c ",4));
    m_volumeBeans.push_back(GFXBean("\x1c\x1c\x1c\x1c\x1c",5));
}

//&---------------------------------------------------------------------*
//&      Method  loadSoundFiles
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void SoundMngr::loadSoundFiles() {
    // Load sounds
    m_soundBufferLevelUp.loadFromFile(resourcePath() + "levelUp.wav");
    m_soundLevelUp.setBuffer(m_soundBufferLevelUp);
    
    m_soundBufferDied.loadFromFile(resourcePath() + "died.wav");
    m_soundDied.setBuffer(m_soundBufferDied);
    
    m_soundBufferLineBlockDestroy.loadFromFile(resourcePath() + "lineBlockDestroy.wav");
    m_soundLineBlockDestroy.setBuffer(m_soundBufferLineBlockDestroy);
    
    m_soundBufferShapeInPlace.loadFromFile(resourcePath() + "shapeInPlace.wav");
    m_soundShapeInPlace.setBuffer(m_soundBufferShapeInPlace);
    
    m_soundBufferFold.loadFromFile(resourcePath() + "shapeInPlace.wav");
    m_soundFold.setBuffer(m_soundBufferFold);
    m_soundFold.setPitch(FOLD_BASE_PITCH);
    
    m_soundBufferShapeMove.loadFromFile(resourcePath() + "shapeMove.wav");
    m_soundShapeMove.setBuffer(m_soundBufferShapeMove);
    
    m_soundBufferShapeRotate.loadFromFile(resourcePath() + "shapeMove.wav");
    m_soundShapeRotate.setBuffer(m_soundBufferShapeRotate);
    m_soundShapeRotate.setPitch(SHAPE_ROTATE_BASE_PITCH);
    
    // Load music
    m_gameMusic.openFromFile(resourcePath() + "evolution_sphere.ogg");
    m_gameMusic.setLoop(true);
    
    m_menuMusic.openFromFile(resourcePath() + "aquatic_life.ogg");
    m_menuMusic.setLoop(true);

    setSoundVolume(VOLUME::PERCENT_100);
    setMusicVolume(VOLUME::PERCENT_100);
}

//&---------------------------------------------------------------------*
//&      Method  setSoundVolume
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void SoundMngr::setSoundVolume(const VOLUME id_volume) {
    m_soundVolume = id_volume;
    m_soundLevelUp.setVolume(LEVEL_UP_BASE_VOLUME * VOLUME_PERCENT[id_volume]);
    m_soundDied.setVolume(DIED_BASE_VOLUME * VOLUME_PERCENT[id_volume]);
    m_soundLineBlockDestroy.setVolume(LINE_BLOCK_DESTROY_BASE_VOLUME * VOLUME_PERCENT[id_volume]);
    m_soundShapeInPlace.setVolume(SHAPE_IN_PLACE_BASE_VOLUME * VOLUME_PERCENT[id_volume]);
    m_soundFold.setVolume(FOLD_BASE_VOLUME * VOLUME_PERCENT[id_volume]);
    m_soundShapeMove.setVolume(SHAPE_MOVE_BASE_VOLUME * VOLUME_PERCENT[id_volume]);
    m_soundShapeRotate.setVolume(SHAPE_ROTATE_BASE_VOLUME * VOLUME_PERCENT[id_volume]);
}

//&---------------------------------------------------------------------*
//&      Method  getSoundVolume
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const SoundMngr::VOLUME SoundMngr::getSoundVolume() {
    return m_soundVolume;
}

//&---------------------------------------------------------------------*
//&      Method  setMusicVolume
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void SoundMngr::setMusicVolume(const VOLUME id_volume) {
    m_musicVolume = id_volume;
    m_menuMusic.setVolume((int)(MENU_MUSIC_BASE_VOLUME * VOLUME_PERCENT[id_volume]));
    m_gameMusic.setVolume((int)(GAME_MUSIC_BASE_VOLUME * VOLUME_PERCENT[id_volume]));
}

//&---------------------------------------------------------------------*
//&      Method  getMusicVolume
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const SoundMngr::VOLUME SoundMngr::getMusicVolume() {
    return m_musicVolume;
}

//&---------------------------------------------------------------------*
//&      Method  playSound
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void SoundMngr::playSound(const SOUND id_sound) {
    if (m_soundVolume == VOLUME::MUTED) {
        return;
    }
    switch (id_sound) {            
        case SOUND::SHAPE_IN_PLACE:
            playSound(&m_soundShapeInPlace);
            break;
        case SOUND::SHAPE_MOVE:
            playSound(&m_soundShapeMove);
            break;
        case SOUND::SHAPE_ROTATE:
            playSound(&m_soundShapeRotate);
            break;
        case SOUND::LINE_BLOCK_DESTROY:
            playSoundNoStop(&m_soundLineBlockDestroy);
            break;
        case SOUND::FOLD_ON_EMPTY_LINES:
            playSound(&m_soundFold);
            break;
        case SOUND::LEVEL_UP:
            playSound(&m_soundLevelUp);
            break;
        case SOUND::DIED:
            playSound(&m_soundDied);
            break;
        default:
            break;
    }
}

//&---------------------------------------------------------------------*
//&      Method  playMusic
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void SoundMngr::playMusic(const MUSIC id_music) {
    //note: don't check for muted volume here, this is a loop
    switch (id_music) {
        // stop current music before start the other
        case MUSIC::MAIN_MENU:
            m_gameMusic.stop();
            m_menuMusic.play();
            break;
        case MUSIC::GAME:
            m_menuMusic.stop();
            m_gameMusic.play();
            break;
        default:
            break;
    };
}

//&---------------------------------------------------------------------*
//&      Method  stopMusic
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void SoundMngr::stopMusic(const MUSIC id_music) {
    switch (id_music) {
        case MUSIC::MAIN_MENU:
            m_menuMusic.stop();
            break;
        case MUSIC::GAME:
            m_gameMusic.stop();
            break;
        default:
            break;
    };
}

//&---------------------------------------------------------------------*
//&      Method  pauseMusic
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void SoundMngr::pauseMusic(const MUSIC id_music) {
    switch (id_music) {
        case MUSIC::MAIN_MENU:
            m_menuMusic.pause();
            break;
        case MUSIC::GAME:
            m_gameMusic.pause();
            break;
        default:
            break;
    };
}

//&---------------------------------------------------------------------*
//&      Method  playSound
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void SoundMngr::playSound(sf::Sound* id_pSound) {
    id_pSound->stop();
    id_pSound->play();
}

//&---------------------------------------------------------------------*
//&      Method  stopSound
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void SoundMngr::stopSound(sf::Sound* id_pSound) {
    id_pSound->stop();
}

//&---------------------------------------------------------------------*
//&      Method  playSoundNoStop
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void SoundMngr::playSoundNoStop(sf::Sound* id_pSound) {
    id_pSound->play();
}


//&---------------------------------------------------------------------*
//&      Method  intToVolume
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
SoundMngr::VOLUME SoundMngr::intToVolume(const int id_integer) {
    switch (id_integer) {
        case 0:
            return VOLUME::MUTED;
            break;
        case 1:
            return VOLUME::PERCENT_20;
            break;
        case 2:
            return VOLUME::PERCENT_40;
            break;
        case 3:
            return VOLUME::PERCENT_60;
            break;
        case 4:
            return VOLUME::PERCENT_80;
            break;
        case 5:
            return VOLUME::PERCENT_100;
            break;
        default:
            return VOLUME::MUTED;
            break;
    }
}

//&---------------------------------------------------------------------*
//&      Method  volumeToInt
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const int SoundMngr::volumeToInt(const VOLUME id_volume) {
    return (int) id_volume;
}

//&---------------------------------------------------------------------*
//&      Method  getVolumeBeans
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const std::vector<GFXBean>* SoundMngr::getVolumeBeans() {
    return &m_volumeBeans;
}


