//***************************************************************************
//
//  Points.cpp
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

#include "Points.hpp"

//&---------------------------------------------------------------------*
//&      Constructor  Points
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
Points::Points() {
    m_levelBeans.push_back(GFXBean("0",0));
    m_levelBeans.push_back(GFXBean("1",1));
    m_levelBeans.push_back(GFXBean("2",2));
    m_levelBeans.push_back(GFXBean("3",3));
    m_levelBeans.push_back(GFXBean("4",4));
    m_levelBeans.push_back(GFXBean("5",5));
    m_levelBeans.push_back(GFXBean("6",6));
    m_levelBeans.push_back(GFXBean("7",7));
    m_levelBeans.push_back(GFXBean("8",8));
    m_levelBeans.push_back(GFXBean("9",9));
    m_levelBeans.push_back(GFXBean("10",10));
    m_levelBeans.push_back(GFXBean("11",11));
    m_levelBeans.push_back(GFXBean("12",12));
    m_levelBeans.push_back(GFXBean("13",13));
    m_levelBeans.push_back(GFXBean("14",14));
    m_levelBeans.push_back(GFXBean("15",15));
}

//&---------------------------------------------------------------------*
//&      Method  reset
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void Points::reset(const int id_level) {
    m_points = 0;
    m_lines = 0;
    m_blocks = 0;
    m_level = id_level;
    m_lineCountForLevel = 0;
    m_pChars[0] = '\0';
    m_pChars[MAX_DIGITS] = '\0';
}


//&---------------------------------------------------------------------*
//&      Method  setTopScore
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void Points::setTopScore(const int id_topScore) {
    m_topPoints = id_topScore;
}

//&---------------------------------------------------------------------*
//&      Method  getTopScore
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const int Points::getTopScore() {
    return m_topPoints;
}

//&---------------------------------------------------------------------*
//&      Method  setNbDigits
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void Points::setNbDigits(const int id_digits) {
    m_digits = id_digits;
}

//&---------------------------------------------------------------------*
//&      Method  getPoints
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
int Points::getPoints() {
    return m_points;
}

//&---------------------------------------------------------------------*
//&      Method  getPointsAsString
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const std::string Points::getPointsAsString() {
    return getIntAsString(m_points);
}

//&---------------------------------------------------------------------*
//&      Method  getTopPointsAsString
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const std::string Points::getTopPointsAsString() {
    return getIntAsString(m_topPoints);
}

//&---------------------------------------------------------------------*
//&      Method  getLinesAsString
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const std::string Points::getLinesAsString() {
    return getIntAsString(m_lines);
}

//&---------------------------------------------------------------------*
//&      Method  getTopLinesAsString
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const std::string Points::getTopLinesAsString() {
    return getIntAsString(m_topLines);
}

//&---------------------------------------------------------------------*
//&      Method  getBlocksAsString
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const std::string Points::getBlocksAsString() {
    return getIntAsString(m_blocks);
}

//&---------------------------------------------------------------------*
//&      Method  getLevelAsString
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const std::string Points::getLevelAsString() {
    return getIntAsString(m_level);
}

//&---------------------------------------------------------------------*
//&      Method  getLevel
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const int Points::getLevel() {
    return m_level;
}

//&---------------------------------------------------------------------*
//&      Method  getIntAsString
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const std::string Points::getIntAsString(int id_int) {
    for (int i = m_digits; i < m_digits; i++) {
        m_pChars[i] = '0';
    }
    m_pChars[m_digits + 1] = '\0';
    int points = id_int;
    int index = m_digits - 1;
    while (points > 0 || index >= 0) {
        int lastDigit = points % 10;
        m_pChars[index] = 48 + lastDigit;  // 48 is '0' in ascii
        points /= 10;
        index--;
    }
    if (m_noLeadingZeros) {
        for (int i = 0; i < (m_digits - 1); i++) {
            if (m_pChars[i] == '0') {
                m_pChars[i] = ' ';
            }
            else {
                break;
            }
        }
    }
    return m_pChars;
}

//&---------------------------------------------------------------------*
//&      Method  addBlockPlaced
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void Points::addBlockPlaced() {
    m_points += BLOCK_PLACED;
    m_blocks++;
    updateTopScore();
}

//&---------------------------------------------------------------------*
//&      Method  addLineCompleted
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void Points::addLinesCompleted(const int id_lines) {
    int mult = 0;
    switch (id_lines) {
        case 1:
            mult = SCORE_MULTIPLIER_1LINE;
            break;
        case 2:
            mult = SCORE_MULTIPLIER_2LINES;
            break;
        case 3:
            mult = SCORE_MULTIPLIER_3LINES;
            break;
        case 4:
            mult = SCORE_MULTIPLIER_4LINES;
            break;
        default:
            break;
    }
    m_points += (m_level + 1) * mult;
    m_lines += id_lines;
    m_lineCountForLevel += id_lines;
    updateTopScore();
    updateTopLines();
    updateLevel();
}

//&---------------------------------------------------------------------*
//&      Method  addFastDrop
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void Points::addFastDrop() {
    m_points += 2;
    updateTopScore();
}

//&---------------------------------------------------------------------*
//&      Method  addSlowDrop
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void Points::addSlowDrop() {
    m_points++;
    updateTopScore();
}

//&---------------------------------------------------------------------*
//&      Method  setNoLeadingZeros
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void Points::setNoLeadingZeros(bool id_noZeros) {
    m_noLeadingZeros = id_noZeros;
}

//&---------------------------------------------------------------------*
//&      Method  updateTopScore
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void Points::updateTopScore() {
    if (m_points > m_topPoints) {
        m_topPoints = m_points;
    }
}

//&---------------------------------------------------------------------*
//&      Method  updateTopLines
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void Points::updateTopLines() {
    if (m_lines > m_topLines) {
        m_topLines = m_lines;
    }
}

//&---------------------------------------------------------------------*
//&      Method  updateLevel
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void Points::updateLevel() {
    if (m_lineCountForLevel >= LINES_PER_LEVEL) {
        m_level++;
        m_lineCountForLevel -= LINES_PER_LEVEL;
    }
}

//&---------------------------------------------------------------------*
//&      Method  getLevelBeans
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
const std::vector<GFXBean>* Points::getLevelBeans() {
    return &m_levelBeans;
}




