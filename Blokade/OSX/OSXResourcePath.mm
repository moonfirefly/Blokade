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
#include "OSXResourcePath.hpp"
#import <Foundation/Foundation.h>

////////////////////////////////////////////////////////////
std::string resourcePath(void)
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    
	std::string rpath;
	NSBundle* bundle = [NSBundle mainBundle];
    
	if (bundle == nil) {
#ifdef DEBUG
		NSLog(@"bundle is nil... thus no resources path can be found.");
#endif
	} else {
		NSString* path = [bundle resourcePath];
		rpath = [path UTF8String] + std::string("/");
	}
    
    [pool drain];
    
    return rpath;
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
