<blockquote><pre>
===================================================================
                         Blokade v0.9.3 
===================================================================

                   Copyright 2013 moonfirefy

Introduction 
------------

Small game in progress, made with SFML 2.0 in C++ using Xcode. This 
is my first game with SFML and it's going well, easy library to work 
with. The game is obviously another falling blocks clone but I wanted 
to design a simple game that I could actually finish.

I wrote the code and made the graphics except the <a href="http://www.ms-studio.com/FontSales/anonymous.html">font</a>. I generated 
the sound effects with <a href="http://www.bfxr.net/">Bfxr</a>. Both background tunes are free loops I 
got from <a href="http://www.joshuahardin.com/free_music_loops.php">Joshua Hardin</a>.

Open the project in Xcode 4.5.2 and up with Quartz and SFML 2.0 installed 
and the game should compile and run right away. 

The Code::Blocks project is also provided so you can compile on Windows.
Install the one bundled with MinGW and link with library MinGW TDM GCC 4.7.1 32bit
found on <a href="http://sfml.my-gate.net/nightly/">SFML nightly builds</a> for best results.

Linux Code::Blocks project created and tested on Ubuntu 12.10. You can
link with the <a href="http://www.sfml-dev.org/download.php">official SMFL build</a> for Linux but you might need to install
older libraries to get it to compile. The sound seems a little off
on Ubuntu but it might be the vm.

Video
-----

See the game running <a href="https://vimeo.com/57818102">here</a>.

Binaries
--------

<a href="https://www.dropbox.com/sh/xsywbqqtoe223zd/Z2tWZZ1g_-">Download</a> and play the pre-compiled game on OSX or Windows.
Aussi disponible en français.

Requirements
------------

OSX

    Requires to install Quartz (OSX 10.6 and later):
    <a href="http://xquartz.macosforge.org/">http://xquartz.macosforge.org/</a>

    Use the Blokade OSX installer for easy and fast install of 
    the game along with the SFML2 framework.
    
    Otherwise, if you download the zip then you have to 
    install SFML 2.0 libraries for Mac OSX (use the installer): 
    <a href="http://www.sfml-dev.org/download.php">http://www.sfml-dev.org/download.php</a>
    
    You probably need OSX 10.8.2 to run it as well.

Windows

    The windows build was with compiled with the necessary libraries
    so no extra download required.

    Props to <a href="https://github.com/eXpl0it3r">eXpl0it3r</a> for the port :)

Linux

	Soon..

Controls
--------

No mouse support, only keyboard input at this time.

  * Menus

    Navigate options in menus with arrow up/down. Hit right/left 
    arrows to change selected value (volume, level). Press return 
    key to select menu options. Escape key closes a menu or goes 
    back one menu behind.

  * Gameplay

    Left/right... Move sideways
    Up........... Rotate
    Down......... Faster drop
    Space........ Drop all the way down instantly

Other
-----

Top 5 high scores, top 5 high lines and volume settings are saved 
in the home directory. Save is silently disabled if the first 
save attempt fails.

License
-------

Licensed under the Apache License, Version 2.0 (the "License"); you 
may not use this file except in compliance with the License. You may 
obtain a copy of the License at

<a href="http://www.apache.org/licenses/LICENSE-2.0">http://www.apache.org/licenses/LICENSE-2.0</a>

Unless required by applicable law or agreed to in writing, software 
distributed under the License is distributed on an "AS IS" BASIS, 
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
See the License for the specific language governing permissions and 
limitations under the License.
</pre></blockquote>
