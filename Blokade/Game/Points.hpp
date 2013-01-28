//***************************************************************************
//
//  Points.hpp
//  Blokade
//
//  Created by moonfirefy on 2013-01-18.
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

#ifndef __Blokade_Points_hpp
#define __Blokade_Points_hpp

#pragma once

#include <math.h>
#include <vector>
#include "GFXBean.hpp"

//&=========================================================================*
//&      Class  Points
//&=========================================================================*
//
//==========================================================================*
class Points {
    
// =============================
// ======== P U B L I C ========
public:
    
    //&---------------------------------------------------------------------*
    //&      Constructor  Points
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    Points();
    
    //&---------------------------------------------------------------------*
    //&      Destructor  ~Points
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    ~Points() {}
    
    //&---------------------------------------------------------------------*
    //&      Method  reset
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void reset(const int id_level);
        
    //&---------------------------------------------------------------------*
    //&      Method  setTopScore
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setTopScore(const int id_topScore);
    
    //&---------------------------------------------------------------------*
    //&      Method  getTopScore
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const int getTopScore();
    
    //&---------------------------------------------------------------------*
    //&      Method  setNbDigits
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setNbDigits(const int id_digits);
    
    //&---------------------------------------------------------------------*
    //&      Method  getPoints
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    int getPoints();
    
    //&---------------------------------------------------------------------*
    //&      Method  getPointsAsChars
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    char* getPointsAsChars();
    
    //&---------------------------------------------------------------------*
    //&      Method  getTopPointsAsChars
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    char* getTopPointsAsChars();
    
    //&---------------------------------------------------------------------*
    //&      Method  getLinesAsChars
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    char* getLinesAsChars();
    
    //&---------------------------------------------------------------------*
    //&      Method  getTopLinesAsChars
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    char* getTopLinesAsChars();
    
    //&---------------------------------------------------------------------*
    //&      Method  getBlocksAsChars
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    char* getBlocksAsChars();
    
    //&---------------------------------------------------------------------*
    //&      Method  getLevelAsChars
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    char* getLevelAsChars();
    
    //&---------------------------------------------------------------------*
    //&      Method  getLevel
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const int getLevel();

    //&---------------------------------------------------------------------*
    //&      Method  addBlockPlaced
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void addBlockPlaced();
    
    //&---------------------------------------------------------------------*
    //&      Method  addLinesCompleted
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void addLinesCompleted(const int id_lines);
    
    //&---------------------------------------------------------------------*
    //&      Method  addFastDrop
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void addFastDrop();
    
    //&---------------------------------------------------------------------*
    //&      Method  addSlowDrop
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void addSlowDrop();
    
    //&---------------------------------------------------------------------*
    //&      Method  setNoLeadingZeros
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void setNoLeadingZeros(bool id_noZeros);
    
    //&---------------------------------------------------------------------*
    //&      Method  getLevelBeans
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    const std::vector<GFXBean>* getLevelBeans();
    
// =============================
// ======= P R I V A T E =======
private:
    
    //&---------------------------------------------------------------------*
    //&      Method  getIntAsChars
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    char* getIntAsChars(int id_int);

    //&---------------------------------------------------------------------*
    //&      Method  updateTopScore
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void updateTopScore();
    
    //&---------------------------------------------------------------------*
    //&      Method  updateTopLines
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void updateTopLines();
    
    //&---------------------------------------------------------------------*
    //&      Method  updateLevel
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void updateLevel();

    static const int BLOCK_PLACED = 15;
    static const int MAX_DIGITS = 15;

    static const int SCORE_MULTIPLIER_1LINE = 40;
    static const int SCORE_MULTIPLIER_2LINES = 100;
    static const int SCORE_MULTIPLIER_3LINES = 300;
    static const int SCORE_MULTIPLIER_4LINES = 1200;
    static const int LINES_PER_LEVEL = 10;
    
    int m_lineCountForLevel = 0;
    int m_points = 0;
    int m_topPoints = 0;
    int m_digits = 9;
    int m_lines = 0;
    int m_blocks = 0;
    int m_topLines = 0;
    int m_level = 0;
    
    char m_pChars[MAX_DIGITS + 1];
    bool m_noLeadingZeros = false;
    
    std::vector<GFXBean> m_levelBeans;
    
};

#endif /* defined(__Blokade_Points_hpp) */
