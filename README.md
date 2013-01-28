Blokade v0.9.2
==============

Copyright 2013 moonfirefy

Introduction
============

Small game in progress, made with SFML 2.0 in C++ using Xcode. 
This is my first game with SFML and it's going well, easy library 
to work with. The game is obviously another falling blocks clone 
but I wanted to design a simple game that I could actually finish.

I wrote the code and made the graphics except the font. I generated 
the sound effects with Bfxr. Both background tunes are free loops 
I got from Joshua Hardin.

Only works on OSX for now but I would like to port to Windows and 
Linux to get more people to play it.

Open the project in Xcode 4.5.2 with Quartz and SFML 2.0 installed
and the game should compile and run right away. 

Video
=====

See the game running: 
https://vimeo.com/57818102

Binaries
========

Requires to install Quartz (OSX 10.6 and later):
http://xquartz.macosforge.org/

and SFML 2.0 libraries for Mac OSX (use the installer):
http://www.sfml-dev.org/download.php

Download and play the pre-compiled game:
https://www.dropbox.com/sh/xsywbqqtoe223zd/Z2tWZZ1g_-

English version under directory EN.

Version française disponible sous le répertoire FR.

Controls
========

No mouse support, only keyboard input at this time.

Menus
=====

Navigate options in menus with arrow up/down. Hit right/left 
arrows to change selected value (volume, level). Press return
key to select menu options. Escape key closes a menu or goes
back one menu behind.

Gameplay
========

Left/right: move sideways

Up: rotate

Down: faster drop

Space: drop all the way down instantly

Other
=====

High score and volume settings are saved in the home directory.
Save is silently disabled if the first save attempt fails.

License
=======

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.