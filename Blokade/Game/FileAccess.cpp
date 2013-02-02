//***************************************************************************
//
//  FileAccess.cpp
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

#include "FileAccess.hpp"

//&---------------------------------------------------------------------*
//&      Method  readData
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
FileAccess::Data* FileAccess::readData() {
    reset();
    std::string filePath = getSettingsFilePath();
    if (filePath != "") {
        std::ifstream file (filePath.c_str(), std::ios::in | std::ios::binary);
        if (file.is_open()) {
            file.read((char*)&m_readData, sizeof(m_readData));
            if (file.bad()) {
                reset();
            }
            file.close();
        }
    }
    return &m_readData;
}

//&---------------------------------------------------------------------*
//&      Method  getSettingsFilePath
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
std::string FileAccess::getSettingsFilePath() {
    std::string filePath = "";
    std::string homePath = getHomePath();
    if (homePath != "") {
        std::string moonPath = homePath + "/.moonfireflyGames";
        if (directoryExists(moonPath)) {
            filePath = moonPath + "/blokade.dat";
        }
        else {
			#if defined( BLOKADE_PLATFORM_OSX )
				if (mkdir(moonPath.c_str(), S_IRWXU | S_IRWXG) == 0) {
					filePath = moonPath + "/blokade.dat";
				}
            #elif defined( BLOKADE_PLATFORM_WINDOWS )
				if (CreateDirectory(moonPath.c_str(), NULL) ||
					ERROR_ALREADY_EXISTS == GetLastError()) {
					filePath = moonPath + "/blockade.dat";
				}
            #elif defined( BLOKADE_PLATFORM_LINUX )
				if (mkdir(moonPath.c_str(), S_IRWXU | S_IRWXG) == 0) {
					filePath = moonPath + "/blokade.dat";
				}
            #endif
        }
    }
    return filePath;
}

//&---------------------------------------------------------------------*
//&      Method  writeData
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool FileAccess::directoryExists(std::string id_path) {
    struct stat st;
    if (stat(id_path.c_str(), &st) == 0) {
        return true;
    }
    else {
        return false;
    }
}

//&---------------------------------------------------------------------*
//&      Method  writeData
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
bool FileAccess::writeData(Data* id_pData) {
    bool result = false;
    std::string filePath = getSettingsFilePath();
    if (filePath != "") {
        std::ofstream file (filePath.c_str(), std::ios::binary);
        if (file.is_open()) {
            file.write((char*)id_pData, sizeof(*id_pData));
            if (!file.bad()) {
                result = true;
            }
            file.close();
        }
    }
    return result;
}

//&---------------------------------------------------------------------*
//&      Method  reset
//&---------------------------------------------------------------------*
//
//----------------------------------------------------------------------*
void FileAccess::reset() {
    m_readData.m_highScore = 0;
    m_readData.m_musicVolume = 5; // max volume
    m_readData.m_soundVolume = 5;
}
