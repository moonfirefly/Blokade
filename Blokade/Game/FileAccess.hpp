//***************************************************************************
//
//  FileAccess.hpp
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

#ifndef __Blokade__FileAccess__hpp
#define __Blokade__FileAccess__hpp

#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include "../ResourcePath.hpp"

//&=========================================================================*
//&      Class  FileAccess
//&=========================================================================*
//
//==========================================================================*
class FileAccess {

// =============================
// ======== P U B L I C ========
public:

    struct Data {
        int m_highScore = 0;
        int m_soundVolume = -1;
        int m_musicVolume = -1;
    };

    //&---------------------------------------------------------------------*
    //&      Constructor  FileAccess
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    FileAccess() {}

    //&---------------------------------------------------------------------*
    //&      Destructor  ~FileAccess
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    ~FileAccess() {}

    //&---------------------------------------------------------------------*
    //&      Method  readData
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    Data* readData();

    //&---------------------------------------------------------------------*
    //&      Method  writeData
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool writeData(Data* id_pData);

    //&---------------------------------------------------------------------*
    //&      Method  writeData
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    bool directoryExists(std::string id_path);

// =============================
// ======= P R I V A T E =======
private:

    //&---------------------------------------------------------------------*
    //&      Method  reset
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    void reset();

    //&---------------------------------------------------------------------*
    //&      Method  getSettingsFilePath
    //&---------------------------------------------------------------------*
    //
    //----------------------------------------------------------------------*
    std::string getSettingsFilePath();

    Data m_readData;

};

#endif /* defined(__Blokade__FileAccess__hpp) */
