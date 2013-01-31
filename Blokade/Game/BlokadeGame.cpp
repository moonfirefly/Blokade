//***************************************************************************
//
//  BlokadeGame.cpp
//  Blokade
//
//  Created by moonfirefy on 2013-01-12.
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

#include "BlokadeGame.hpp"

//&---------------------------------------------------------------------*
//&      Constructor  BlokadeGame
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
BlokadeGame::BlokadeGame() : GFXEngine(1024, 768, "Blokade") {
    m_runtime.getWindow()->setFramerateLimit(60);
    m_runtime.getWindow()->clear();
    m_runtime.getWindow()->display();
    m_runtime.getWindow()->setMouseCursorVisible(false);
}

//&---------------------------------------------------------------------*
//&      Method  init
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool BlokadeGame::init() {    
    // Load images
    if (!m_menuBackgrndTexture.loadFromFile(resourcePath() + "backgrnd.png")) {
        return false;
    }
    m_menuBackgrndSprite = sf::Sprite(m_menuBackgrndTexture);

    if (!m_gameBackgrndTexture.loadFromFile(resourcePath() + "game.png")) {
        return false;
    }
    m_gameBackgrndSprite = sf::Sprite(m_gameBackgrndTexture);

    if (!m_blocksTexture.loadFromFile(resourcePath() + "blocks.png")) {
        return false;
    }
    m_blocksSprite = sf::Sprite(m_blocksTexture);
    
    // Initialize font print
    if (!m_font.init(*(m_runtime.getWindow()))) {
        return false;
    }    
    
    // Main menu
    m_mainMenuStart.init(i18n::START, BUTTON::START);
    m_mainMenuOptions.init(i18n::OPTIONS, BUTTON::OPTIONS);
    m_mainMenuExit.init(i18n::EXIT, BUTTON::EXIT);
    m_mainMenu.addItem(&m_mainMenuStart);
    m_mainMenu.addItem(&m_mainMenuOptions);
    m_mainMenu.addItem(&m_mainMenuExit);
    m_mainMenu.setPosition((1024 - 338) / 2, 290);
    
    m_optionsMenuVolumeSound.init(i18n::SOUND, BUTTON::SOUND, m_soundMngr.getVolumeBeans());
    m_optionsMenuVolumeSound.setSelectedIndex(5); // full volume
    m_optionsMenuVolumeMusic.init(i18n::MUSIC, BUTTON::MUSIC, m_soundMngr.getVolumeBeans());
    m_optionsMenuVolumeMusic.setSelectedIndex(5); // full volume
    m_optionsMenuBack.init(i18n::BACK, BUTTON::BACK);
    m_optionsMenu.addItem(&m_optionsMenuVolumeSound);
    m_optionsMenu.addItem(&m_optionsMenuVolumeMusic);
    m_optionsMenu.addItem(&m_optionsMenuBack);
    m_optionsMenu.setPosition((1024 - 650) / 2, 290);

    m_levelMenuLevel.init(i18n::LEVEL, BUTTON::LEVEL, m_points.getLevelBeans());
    m_levelMenuLevel.setSelectedIndex(0); // level 0
    m_levelMenuBack.init(i18n::BACK, BUTTON::BACK);
    m_levelMenu.addItem(&m_levelMenuLevel);
    m_levelMenu.addItem(&m_levelMenuBack);
    m_levelMenu.setPosition((1024 - 650) / 2, 340);

    // In-game Pause menu
    m_gameMenuPauseResume.init(i18n::RESUME, BUTTON::RESUME);
    m_gameMenuPauseOptions.init(i18n::OPTIONS, BUTTON::OPTIONS);
    m_gameMenuPauseRestart.init(i18n::RESTART, BUTTON::RESTART);
    m_gameMenuPauseQuit.init(i18n::QUIT, BUTTON::QUIT);
    m_gameMenuPause.addItem(&m_gameMenuPauseResume);
    m_gameMenuPause.addItem(&m_gameMenuPauseOptions);
    m_gameMenuPause.addItem(&m_gameMenuPauseRestart);
    m_gameMenuPause.addItem(&m_gameMenuPauseQuit);
    m_gameMenuPause.setPosition((1024 - 338) / 2, 240);
    
    // In-game Game Over menu
    m_gameMenuOverRestart.init(i18n::RESTART, BUTTON::RESTART);
    m_gameMenuOverQuit.init(i18n::QUIT, BUTTON::QUIT);
    m_gameMenuOver.addItem(&m_gameMenuOverRestart);
    m_gameMenuOver.addItem(&m_gameMenuOverQuit);
    m_gameMenuOver.setPosition((1024 - 338) / 2, 310);

    // Initialize score output
    m_points.setNbDigits(7);
    m_points.setNoLeadingZeros(true);
    
    // Load sound effects and music
    m_soundMngr.loadSoundFiles();
    
    // Start fresh in main menu
    loadSettings();
    reset();
    
    // Start playing menu music right away
    m_soundMngr.playMusic(SoundMngr::MUSIC::MAIN_MENU);
    
    return true;
}

//&---------------------------------------------------------------------*
//&      Method  loadSettings
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::loadSettings() {
    m_settings = m_fileAccess.readData(); // returns defaults if read fails
    m_soundMngr.setSoundVolume(m_soundMngr.intToVolume(m_settings->m_soundVolume));
    m_optionsMenuVolumeSound.setSelectedIndex(m_settings->m_soundVolume);
    m_soundMngr.setMusicVolume(m_soundMngr.intToVolume(m_settings->m_musicVolume));
    m_optionsMenuVolumeMusic.setSelectedIndex(m_settings->m_musicVolume);
    m_points.setTopScore(m_settings->m_highScore);
}

//&---------------------------------------------------------------------*
//&      Method  saveSettings
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::saveSettings(const bool id_saveTopScore) {
    int topScore = m_settings->m_highScore;
    if (id_saveTopScore) {
        topScore = m_points.getTopScore();
    }
    // don't try save to save again if it failed the first time
    if (m_settingsSaveSuccess && (m_settings->m_highScore != topScore ||
            m_settings->m_musicVolume != m_soundMngr.getMusicVolume() ||
            m_settings->m_soundVolume != m_soundMngr.getSoundVolume())) {
        m_settings->m_highScore = topScore;
        m_settings->m_musicVolume = m_soundMngr.getMusicVolume();
        m_settings->m_soundVolume = m_soundMngr.getSoundVolume();
        m_settingsSaveSuccess = m_fileAccess.writeData(m_settings);
    }
}

//&---------------------------------------------------------------------*
//&      Method  reset
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::reset() {
    m_isPaused = false;
    m_gamestate = GAME_STATE::MAIN_MENU;
    m_gameSubState = GAME_SUB_STATE::NORMAL;
    m_mainMenu.selectItemByTag(BUTTON::START);
    m_soundMngr.playMusic(SoundMngr::MUSIC::MAIN_MENU);
    m_points.setTopScore(m_settings->m_highScore);
}

//&---------------------------------------------------------------------*
//&      Method  input
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::input() {
    switch (m_gamestate) {
        case GAME_STATE::MAIN_MENU:
            if (m_runtime.isKeyPressed(GFXRuntime::KEY::ESCAPE)) {
                switch (m_gameSubState) {
                    case GAME_SUB_STATE::NORMAL:
                        shutdown();
                        break;
                    case GAME_SUB_STATE::OPTIONS_MENU:
                        saveSettings(false);
                        m_gameSubState = GAME_SUB_STATE::NORMAL;
                        break;
                    case GAME_SUB_STATE::LEVEL_MENU:
                        m_gameSubState = GAME_SUB_STATE::NORMAL;
                        break;
                    default:
                        break;
                }
            }
            break;
            
        case GAME_STATE::GAME:
            resetGameInput();
            switch (m_gameSubState) {
                case GAME_SUB_STATE::NORMAL:
                    if (m_isPaused) {
                        if (m_runtime.isKeyPressed(GFXRuntime::KEY::ESCAPE)) {
                            resume();
                        }
                    }
                    else {
                        updateGameInput();
                    }
                    break;
                case GAME_SUB_STATE::OPTIONS_MENU:
                    if (m_runtime.isKeyPressed(GFXRuntime::KEY::ESCAPE)) {
                        saveSettings(false);
                        m_gameSubState = GAME_SUB_STATE::NORMAL;
                    }
                    break;
                default:
                    break;
            }
            break;
            
        default:
            break;
    }
}

//&---------------------------------------------------------------------*
//&      Method  resetGameInput
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::resetGameInput() {
    m_moveLeft = false;
    m_moveRight = false;
    m_rotate = false;
    m_speedUp = false;
    m_dropShapeAllTheWayDown = false;
}

//&---------------------------------------------------------------------*
//&      Method  updateGameInput
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::updateGameInput() {
    if (m_runtime.isKeyPressed(GFXRuntime::KEY::ESCAPE)) {
        pause();
    }
    else {
        // Check Left and Right arrow input
        if (m_runtime.isKeyDown(GFXRuntime::KEY::LEFT)) {
            m_moveLeft = true;
        }
        else if (m_runtime.isKeyDown(GFXRuntime::KEY::RIGHT)) {
            m_moveRight = true;
        }
        
        // Shape move throttle (don't move shape too fast sideways)
        if (m_moveLeft || m_moveRight) {
            if (m_keyMoveTime > 0) {
                if (m_keyMoveTime < m_keyMoveTimeMax) {
                    m_moveLeft = false;
                    m_moveRight = false;
                }
                else {
                    m_keyMoveTime = 0;
                }
            }
            m_keyMoveTime += m_runtime.getTimeElapsed().asMilliseconds();
        }
        else {
            m_keyMoveTime = 0;
        }
        
        // Up (rotate shape)
        if (m_runtime.isKeyPressed(GFXRuntime::KEY::UP)) {
            m_rotate = true;
        }
        
        // Down (fast shape drop)
        if (m_runtime.isKeyDown(GFXRuntime::KEY::DOWN)) {
            m_speedUp = true;
            if (m_runtime.isKeyPressed(GFXRuntime::KEY::DOWN)) {
                m_shapeFallTime = m_shapeFallTimeMaxSlow; // drop shape now by one line
            }
        }
        
        // Drop shape all the way down, skip fall time
        if (m_runtime.isKeyPressed(GFXRuntime::KEY::SPACE)) {
            m_dropShapeAllTheWayDown = true;
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  update
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::update() {
    switch (m_gamestate) {
        case GAME_STATE::MAIN_MENU:
            switch (m_gameSubState) {
                case GAME_SUB_STATE::NORMAL:
                    updateMainMenu();
                    break;
                case GAME_SUB_STATE::OPTIONS_MENU:
                    updateOptionsMenu();
                    break;
                case GAME_SUB_STATE::LEVEL_MENU:
                    updateLevelsMenu();
                    break;
                default:
                    break;
            }
            break;
            
        case GAME_STATE::GAME:
            copyFixedToBuffer();
            switch (m_gameSubState) {
                case GAME_SUB_STATE::NORMAL:
                    if (m_isPaused) {
                        updatePauseMenu();
                    }
                    else {
                        updateLevel(true);
                        if (m_dropShapeAllTheWayDown) {
                            dropShapeRightDown();
                        }
                        else {
                            updateShapeDropSpeed();
                            updateSidewaysMove();
                            updateRotate();
                            updateShapeFallByOneLine();
                        }
                    }
                    break;
                case GAME_SUB_STATE::REMOVING_LINES:
                    updateRemovingCompletedLines();
                    break;
                case GAME_SUB_STATE::DEAD:
                    updateGameOverMenu();
                    break;
                case GAME_SUB_STATE::OPTIONS_MENU:
                    updateOptionsMenu();
                    break;
                default:
                    break;
            }
            break;

        default:
            break;
    }
}

//&---------------------------------------------------------------------*
//&      Method  dropShapeRightDown
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::dropShapeRightDown() {
    m_shapeFallTime = m_shapeFallTimeMax;
    while (!updateShapeFallByOneLine()) {
        copyFixedToBuffer();
        m_shapeFallTime = m_shapeFallTimeMax;
    };
}

//&---------------------------------------------------------------------*
//&      Method  updateOptionsMenu
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::updateOptionsMenu() {
    m_optionsMenu.update(&m_runtime);
    if (m_optionsMenu.getPressedItem() != NULL) {
        switch ((*m_optionsMenu.getPressedItem()).getTag()) {
            case BUTTON::BACK:
                saveSettings(false);
                switch (m_gamestate) {
                    case GAME_STATE::MAIN_MENU:
                        m_gameSubState = GAME_SUB_STATE::NORMAL;
                        break;
                    case GAME_STATE::GAME:
                        m_gameSubState = GAME_SUB_STATE::NORMAL;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    else if (m_optionsMenu.getNewSelectionItem() != NULL) {
        switch ((*m_optionsMenu.getNewSelectionItem()).getTag()) {
            case BUTTON::SOUND:
                m_soundMngr.setSoundVolume(m_soundMngr.intToVolume(m_optionsMenu.getNewSelectedValue()->getValue()));
                m_soundMngr.playSound(SoundMngr::SOUND::SHAPE_MOVE); // play test sound for user to see if volume is ok
                break;
            case BUTTON::MUSIC:
                m_soundMngr.setMusicVolume(m_soundMngr.intToVolume(m_optionsMenu.getNewSelectedValue()->getValue()));
                break;
            default:
                break;
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  updateLevelsMenu
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::updateLevelsMenu() {
    m_levelMenu.update(&m_runtime);
    if (m_levelMenu.getPressedItem() != NULL) {
        switch ((*m_levelMenu.getPressedItem()).getTag()) {
            case BUTTON::LEVEL:
                newGame();
                break;
            case BUTTON::BACK:
                m_gameSubState = GAME_SUB_STATE::NORMAL;
                break;
            default:
                break;
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  updateGameOverMenu
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::updateGameOverMenu() {
    m_gameMenuOver.update(&m_runtime);
    if (m_gameMenuOver.getPressedItem() != NULL) {
        switch ((*m_gameMenuOver.getPressedItem()).getTag()) {
            case BUTTON::RESTART:
                newGame();
                break;
            case BUTTON::QUIT:
                reset();
                break;
            default:
                break;
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  updateRemovingCompletedLines
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::updateRemovingCompletedLines() {
    m_removeLineTime += m_runtime.getTimeElapsed().asMilliseconds();
    if (m_removeLineTime >= m_removeLineTimeMax) {
        // Time to remove another block on all completed lines, starting from the right
        for (std::list<int>::iterator i = m_completeLines.begin(); i != m_completeLines.end(); ++i) {
            m_gridLayoutBuffer[(*i)][m_removeLineXIndex] = BLOCK_TYPE::EMPTY;
        }
        copyBufferToFixed();
        m_soundMngr.playSound(SoundMngr::SOUND::LINE_BLOCK_DESTROY);
        m_removeLineXIndex--;
        if (m_removeLineXIndex < 0) {
            // All blocks removed, lines are all empty now, fold empty lines
            m_points.addLinesCompleted((int)m_completeLines.size());
            foldEmptyLines();
            startNewShape();
            m_soundMngr.playSound(SoundMngr::SOUND::FOLD_ON_EMPTY_LINES);
        }
        m_removeLineTime = 0;
    }
}

//&---------------------------------------------------------------------*
//&      Method  updatePauseMenu
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::updatePauseMenu() {
    m_gameMenuPause.update(&m_runtime);
    if (m_gameMenuPause.getPressedItem() != NULL) {
        switch ((*m_gameMenuPause.getPressedItem()).getTag()) {
            case BUTTON::RESUME:
                resume();
                break;
            case BUTTON::OPTIONS:
                m_gameSubState = GAME_SUB_STATE::OPTIONS_MENU;
                m_optionsMenu.selectItemByTag(BUTTON::SOUND);
                break;
            case BUTTON::RESTART:
                newGame();
                break;
            case BUTTON::QUIT:
                reset();
                break;
            default:
                break;
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  updateShapeFallByOneLine
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool BlokadeGame::updateShapeFallByOneLine() {
    bool blockPlaced = false;
    m_shapeFallTime += m_runtime.getTimeElapsed().asMilliseconds();
    if (m_shapeFallTime >= m_shapeFallTimeMax) {
        // Time to drop down by one line
        if (isMoveValid(m_shapeGridX, m_shapeGridY + 1, m_currentShapeRotation)) {
            // Empty spaces below, drop by one line
            m_shapeGridY++;
            plotShapeToBuffer();
        }
        else {
            // At least one block below, stop shape fall
            blockPlaced = true;
            plotShapeToBuffer();
            copyBufferToFixed();
            m_points.addBlockPlaced();
            m_soundMngr.playSound(SoundMngr::SOUND::SHAPE_IN_PLACE);
            if (m_shapeFallTime < m_shapeFallTimeMaxSlow) {
                m_points.addFastDrop();
            }
            else {
                m_points.addSlowDrop();
            }
            if (!isLineComplete()) {
                // No lines completed by this shape, make a new one fall from the top
                startNewShape();
                if (!isMoveValid(m_shapeGridX, m_shapeGridY, m_currentShapeRotation)) {
                    // Not enough space for the new shape, game is over
                    plotShapeToBuffer();
                    copyBufferToFixed();
                    die();
                }
            }
        }
        m_shapeFallTime = 0;
    }
    else {
        // Not time to drop yet, just plot the shape 
        plotShapeToBuffer();
    }
    return blockPlaced;
}

//&---------------------------------------------------------------------*
//&      Method  updateRotate
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::updateRotate() {
    if (m_rotate) {
        int nextShapeOrientation = ((m_currentShapeRotation + 1) > SHAPE_ROTATION_MAX) ? 0 : m_currentShapeRotation + 1;
        if (isMoveValid(m_shapeGridX, m_shapeGridY, nextShapeOrientation)) {
            // No block is preventing the rotation, do it
            m_currentShapeRotation = nextShapeOrientation;
            m_soundMngr.playSound(SoundMngr::SOUND::SHAPE_ROTATE);
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  updateSidewaysMove
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::updateSidewaysMove() {
    if (m_moveLeft) {
        if (isMoveValid(m_shapeGridX - 1, m_shapeGridY, m_currentShapeRotation)) {
            // No block prevents move shape to the left, do it
            m_shapeGridX--;
            m_soundMngr.playSound(SoundMngr::SOUND::SHAPE_MOVE);
        }
    }
    else if (m_moveRight) {
        if (isMoveValid(m_shapeGridX + 1, m_shapeGridY, m_currentShapeRotation)) {
            // No block prevents move shape to the right, do it
            m_shapeGridX++;
            m_soundMngr.playSound(SoundMngr::SOUND::SHAPE_MOVE);
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  updateShapeDropSpeed
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::updateShapeDropSpeed() {
    // Update fall speed according to whether the player presses down or not
    m_shapeFallTimeMax = (m_speedUp) ? m_shapeFallTimeMaxFast : m_shapeFallTimeMaxSlow;
}

//&---------------------------------------------------------------------*
//&      Method  updateLevel
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::updateLevel(const bool id_playSound) {
    if (m_previousLevel != m_points.getLevel()) {
        // New level reached, drop shapes faster
        // Normal speed
        if (m_shapeFallTimeMaxSlow >= 250) {
            m_shapeFallTimeMaxSlow -= 75;
        }
        // Fast speed (holding arrow down)
        if (m_shapeFallTimeMaxFast >= 30) {
            m_shapeFallTimeMaxFast -= 8;
        }
        if (id_playSound) {
            m_soundMngr.playSound(SoundMngr::SOUND::LEVEL_UP);
        }
    }
    m_previousLevel = m_points.getLevel();
}

//&---------------------------------------------------------------------*
//&      Method  updateMainMenu
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::updateMainMenu() {
    m_mainMenu.update(&m_runtime);
    if (m_mainMenu.getPressedItem() != NULL) {
        switch ((*m_mainMenu.getPressedItem()).getTag()) {
            case BUTTON::START:
                m_gameSubState = GAME_SUB_STATE::LEVEL_MENU;
                m_levelMenu.selectItemByTag(BUTTON::LEVEL);
                break;
            case BUTTON::OPTIONS:
                m_gameSubState = GAME_SUB_STATE::OPTIONS_MENU;
                m_optionsMenu.selectItemByTag(BUTTON::SOUND);
                break;
            case BUTTON::EXIT:
                shutdown();
                break;
            default:
                break;
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  checkLinesComplete
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool BlokadeGame::isLineComplete() {
    m_completeLines.clear();
    
    // Identify all complete lines
    for(int h = 0; h < GRID_HEIGHT; h++) {
        bool complete = true;
        for(int w = 0; w < GRID_WIDTH; w++) {
            if (m_gridLayoutFixed[h][w] == 0) {
                complete = false;
            }
        }
        if (complete) {
            m_completeLines.push_back(h);
        }
    }
    
    bool result = false;
    
    if (m_completeLines.size() > 0) {
        // At least one line is complete, initiate line removal state
        result = true;
        m_gameSubState = GAME_SUB_STATE::REMOVING_LINES;
        m_removeLineTime = m_removeLineTimeMax;
        m_removeLineXIndex = GRID_WIDTH - 1;
    }

    return result;
}

//&---------------------------------------------------------------------*
//&      Method  isMoveValid
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool BlokadeGame::isMoveValid(int id_x, int id_y, int id_rotation) {
    for(int h = 0; h < 4; h++) {
        for(int w = 0; w < 4; w++) {
            if (SHAPES[(m_currentShape * 16) + (id_rotation * 4) + h][w] > 0) {
                int gridY = id_y + h;
                int gridX = id_x + w;

                // Block outside the grid?
                if (gridX >= GRID_WIDTH || gridX < 0) {
                    return false;
                }
                if (gridY >= GRID_HEIGHT || gridY < 0) {
                    return false;
                }
                
                // Already a block there?
                if (m_gridLayoutFixed[gridY][gridX] > 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

//&---------------------------------------------------------------------*
//&      Method  plotShapeToBuffer
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::plotShapeToBuffer() {
    if (m_currentShape >= 0) {
        for(int h = 0; h < 4; h++) {
            for(int w = 0; w < 4; w++) {
                if (SHAPES[(m_currentShape * 16) + (m_currentShapeRotation * 4) + h][w] > 0) {
                    m_gridLayoutBuffer[m_shapeGridY + h][m_shapeGridX + w] = m_currentShape + 1;
                }
            }
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  foldEmptyLines
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::foldEmptyLines() {
    // Clear destination grid
    for(int h = 0; h < GRID_HEIGHT; h++) {
        for(int w = 0; w < GRID_WIDTH; w++) {
            m_gridLayoutFixed[h][w] = BLOCK_TYPE::EMPTY;
        }
    }
    
    int fixedY = GRID_HEIGHT - 1;
    bool empty;
    
    // Go through current grid where lines have been removed, from bottom
    // up, move non-empty lines in destination grid, stack them up (fold)
    for(int h = (GRID_HEIGHT - 1); h >= 0; h--) {
        empty = false;
        
        // Check each space of this line to see if it is empty
        for (std::list<int>::iterator i = m_completeLines.begin(); i != m_completeLines.end(); ++i) {
            if ((*i) == h) {
                empty = true;
                break;
            }
        }
        
        // It is empty, don't transfer it
        if (empty) {
            continue;
        }

        // This line is not empty, transfer it on top of the last one
        for(int w = 0; w < GRID_WIDTH; w++) {
            m_gridLayoutFixed[fixedY][w] = m_gridLayoutBuffer[h][w];
        }
        fixedY--;
    }
}

//&---------------------------------------------------------------------*
//&      Method  copyBufferToFixed
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::copyBufferToFixed() {
    for(int h = 0; h < GRID_HEIGHT; h++) {
        for(int w = 0; w < GRID_WIDTH; w++) {
            m_gridLayoutFixed[h][w] = m_gridLayoutBuffer[h][w];
        }
    }    
}

//&---------------------------------------------------------------------*
//&      Method  copyFixedToBuffer
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::copyFixedToBuffer() {
    for(int h = 0; h < GRID_HEIGHT; h++) {
        for(int w = 0; w < GRID_WIDTH; w++) {
            m_gridLayoutBuffer[h][w] = m_gridLayoutFixed[h][w];
        }
    }    
}

//&---------------------------------------------------------------------*
//&      Method  startNewShape
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::startNewShape() {
    m_gameSubState = GAME_SUB_STATE::NORMAL;
    
    // Take next shape if available
    if (m_nextShape >= 0) {
        m_currentShape = m_nextShape;
    }
    else {
        m_currentShape = rand() % 7;  // 0 to 6
    }
    
    // Calculate next shape
    m_nextShape = rand() % 7;  // 0 to 6
    
    m_currentShapeRotation = 0;
    m_shapeGridY = 0;
    m_shapeGridX = 4;
    m_shapeFallTime = 0;
    m_shapeFallTimeMax = m_shapeFallTimeMaxSlow; // trigger new shape to show now
}

//&---------------------------------------------------------------------*
//&      Method  newGame
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::newGame() {
    m_gamestate = GAME_STATE::GAME;
    m_gameSubState = GAME_SUB_STATE::NORMAL;

    // Clear grids
    for(int h = 0; h < GRID_HEIGHT; h++) {
        for(int w = 0; w < GRID_WIDTH; w++) {
            m_gridLayoutFixed[h][w] = BLOCK_TYPE::EMPTY;
            m_gridLayoutBuffer[h][w] = BLOCK_TYPE::EMPTY;
        }
    }

    m_nextShape = -1;
    m_isPaused = false;
    m_shapeFallTimeMaxSlow = FALL_TIME_SLOW_LVL0;
    m_shapeFallTimeMaxFast = FALL_TIME_FAST_LVL0;
    
    startNewShape();
    
    m_points.reset(m_levelMenuLevel.getSelectedValue()->getValue());
    m_points.setTopScore(m_settings->m_highScore);
    
    for (int i = 0; i <= m_points.getLevel(); i++) {
        m_previousLevel = 0;
        updateLevel(false);
    }
    
    m_soundMngr.playMusic(SoundMngr::MUSIC::GAME);
}

//&---------------------------------------------------------------------*
//&      Method  die
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::die() {
    m_gameSubState = GAME_SUB_STATE::DEAD; 
    m_soundMngr.playSound(SoundMngr::SOUND::DIED);
    m_gameMenuOver.selectItemByTag(BUTTON::RESTART);
    saveSettings(true);
}

//&---------------------------------------------------------------------*
//&      Method  drawNextShape
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::drawNextShape() {
    if (m_nextShape >= 0) {
        for(int h = 0; h < 4; h++) {
            for(int w = 0; w < 4; w++) {
                if (SHAPES[(m_nextShape * 16) + (0 * 4) + h][w] > 0) {
                    int x = 800, y = 515;
                    
                    sf::IntRect rect;
                    rect.top = 0;
                    rect.left = m_nextShape * GRID_BLOCK_SIZE;
                    rect.width = GRID_BLOCK_SIZE;
                    rect.height = GRID_BLOCK_SIZE;
                    m_blocksSprite.setTextureRect(rect);

                    switch (m_nextShape) {
                        case 0:
                            y += 14;
                            break;
                        case 1:
                            y += 28;
                            x += 14;
                            break;
                        case 2:
                            y += 28;
                            break;
                        case 3:
                            y += 0;
                            x += 14;
                            break;
                        case 4:
                            y += 28;
                            x += 14;
                            break;
                        case 5:
                            y += 16;
                            x += 32;
                            break;
                        case 6:
                            x += 14;
                            break;
                        default:
                            break;
                    }
                    m_blocksSprite.setPosition(x + (w * GRID_BLOCK_SIZE), y + (h * GRID_BLOCK_SIZE));
                    m_runtime.getWindow()->draw(m_blocksSprite);
                }
            }
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  render
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::render() {
    switch (m_gamestate) {
        case GAME_STATE::MAIN_MENU:
            switch (m_gameSubState) {
                case GAME_SUB_STATE::NORMAL:
                    renderMainMenu();
                    break;
                case GAME_SUB_STATE::OPTIONS_MENU:
                    renderOptionsMenu();
                    break;
                case GAME_SUB_STATE::LEVEL_MENU:
                    renderLevelsMenu();
                    break;
                default:
                    break;
            }
            break;
        case GAME_STATE::GAME:
            renderGame();
            break;
        default:
            break;
    }

}

//&---------------------------------------------------------------------*
//&      Method  renderGame
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::renderGame() {
    m_runtime.getWindow()->draw(m_gameBackgrndSprite);
    
    // Go through each space in the grid
    for(int h = 0; h < GRID_HEIGHT; h++) {
        for(int w = 0; w < GRID_WIDTH; w++) {
            int left = -1;
            if (m_isPaused) {
                // Game is paused, fill up the grid with blocks so that the player
                // doesn't see the grid and take time to think for his next move (haha:)
                left = (BLOCK_TYPE::EIGHT - 1)  * GRID_BLOCK_SIZE;  // b&w
            }
            else {
                if (m_gridLayoutBuffer[h][w] != BLOCK_TYPE::EMPTY) {
                    // Space is not empty, render according to block type
                    left = (m_gridLayoutBuffer[h][w] - 1) * GRID_BLOCK_SIZE;
                }
            }
            if (left >= 0) {
                sf::IntRect rect;
                rect.top = 0;
                rect.left = left;
                rect.width = GRID_BLOCK_SIZE;
                rect.height = GRID_BLOCK_SIZE;
                m_blocksSprite.setTextureRect(rect);
                m_blocksSprite.setPosition(GRID_LEFT + (w * GRID_BLOCK_SIZE), GRID_TOP + (h * GRID_BLOCK_SIZE));
                m_runtime.getWindow()->draw(m_blocksSprite);
            }
        }
    }
    
    // Display game score
    m_font.drawStringAtPos(i18n::LINES, 38, 59, GAME_LABEL_CENTER_WIDTH);
    m_font.drawStringAtPos(m_points.getLinesAsString(), 58, 135);
    m_font.drawStringAtPos(i18n::LEVEL, 38, 235, GAME_LABEL_CENTER_WIDTH);
    m_font.drawStringAtPos(m_points.getLevelAsString(), 58, 310);
    m_font.drawStringAtPos(i18n::TOP, 726, 59, GAME_LABEL_CENTER_WIDTH);
    m_font.drawStringAtPos(m_points.getTopPointsAsString(), 742, 135);
    m_font.drawStringAtPos(i18n::SCORE, 726, 235, GAME_LABEL_CENTER_WIDTH);
    m_font.drawStringAtPos(m_points.getPointsAsString(), 742, 310);
    m_font.drawStringAtPos(i18n::NEXT, 726, 413, GAME_LABEL_CENTER_WIDTH);
    
    // Display next shape
    drawNextShape();

    // Display in-game menu (pause or game over)
    if (m_isPaused) {
        m_font.drawStringAtPos(i18n::PAUSE, 375, 20, 280);
        switch (m_gameSubState) {
            case GAME_SUB_STATE::NORMAL:
                m_runtime.getWindow()->draw(m_gameMenuPause);
                break;
            case GAME_SUB_STATE::OPTIONS_MENU:
                m_runtime.getWindow()->draw(m_optionsMenu);
                break;                
            default:
                break;
        }
    }
    else {
        switch (m_gameSubState) {
            case DEAD:
                m_font.drawStringAtPos(i18n::GAME_OVER, 375, 20, 280);
                m_runtime.getWindow()->draw(m_gameMenuOver);
                break;
            default:
                break;
        }
    }
}

//&---------------------------------------------------------------------*
//&      Method  renderMainMenu
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::renderMainMenu() {
    m_runtime.getWindow()->draw(m_menuBackgrndSprite);
    m_runtime.getWindow()->draw(m_mainMenu);
}

//&---------------------------------------------------------------------*
//&      Method  renderOptionsMenu
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::renderOptionsMenu() {
    m_runtime.getWindow()->draw(m_menuBackgrndSprite);
    m_runtime.getWindow()->draw(m_optionsMenu);
}

//&---------------------------------------------------------------------*
//&      Method  renderOptionsMenu
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::renderLevelsMenu() {
    m_runtime.getWindow()->draw(m_menuBackgrndSprite);
    m_runtime.getWindow()->draw(m_levelMenu);
}

//&---------------------------------------------------------------------*
//&      Method  pause
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::pause() {
    m_isPaused = true;
    m_soundMngr.pauseMusic(SoundMngr::MUSIC::GAME);
    m_gameMenuPause.selectItemByTag(BUTTON::RESUME);
}

//&---------------------------------------------------------------------*
//&      Method  resume
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::resume() {
    m_isPaused = false;
    m_soundMngr.playMusic(SoundMngr::MUSIC::GAME);
}

//&---------------------------------------------------------------------*
//&      Method  shutdown
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void BlokadeGame::shutdown() {
    GFXEngine::shutdown();
}


