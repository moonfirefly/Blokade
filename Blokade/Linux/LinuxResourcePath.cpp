////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2012 Marco Antognini (antognini.marco@gmail.com),
//                         Laurent Gomila (laurent.gom@gmail.com),
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////----- File modified from original to provide getHomePath function (moonfirefly)
////----- File also renamed to OSXResourcePath (moonfirefly)

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "LinuxResourcePath.hpp"

////////////////////////////////////////////////////////////
std::string resourcePath(void)
{
    char path[1024];
    ssize_t len = ::readlink("/proc/self/exe", path, sizeof(path)-1);
    if (len != -1) {
        path[len] = '\0';
        std::string str(path);
	    str = str.substr(0, str.rfind('/') + 1);
        return str;
    }
    else {
        return std::string("");
    }
}

////////////////////////////////////////////////////////////
std::string getHomePath() {
    struct passwd* pwd = getpwuid(getuid());
    if (pwd && pwd->pw_dir != NULL) {
        std::string path(pwd->pw_dir);
        return path;
    }
    else {
        std::string empty = "";
        return empty;
    }
}
