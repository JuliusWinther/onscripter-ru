ONScripter-RU-W
(Winther's Variation)
=============

[![Build Status](https://travis-ci.com/umineko-project/onscripter-ru.svg?branch=master)](https://travis-ci.com/umineko-project/onscripter-ru)

This is a variation of the visual novel engine empowering [Umineko Project port](https://umineko-project.org) of Umineko no Naku Koro ni from PlayStation 3. Albeit the engine being one of the most powerful publicly available engines for creating visual novels, it contains numerous hacks specific to it's needs, lacks API documentation, and may not be suitable for your needs.

For the list of available platforms and compilation instructions please proceed to [Compilation.md](https://github.com/umineko-project/onscripter-ru/blob/master/Resources/Docs/Compilation.md) document.

## Fork Details
This is the engine empowring the [Umineko Concerto](https://discord.gg/DQaBb3RFh7) mod for Umineko Project.
Various modifications made to the original engine:

* Added the ability to pause and resume the playback of videos using the commands pausevideo and resumevideo.
* Added a new formatting rule to adjust the vertical margin of each line of text (similar to line spacing).
* Added the capability to dynamically obtain the length of a scrollable sprite through getspritesize.
* Added support for a greater number of fonts than the original.
* Integrated compatibility with Discord thanks to the permission and support of [m3t4f1v3](https://github.com/m3t4f1v3).
* Added the ability to include images in addition to text associated with each item in a tree read from a scrollable sprite.

#### Credits
- Ogapee
- "Uncle" Mion Sonozaki
- Umineko Project
- All third-party library authors
