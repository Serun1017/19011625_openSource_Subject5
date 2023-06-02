# THE SEEKER
### THE SEEKER v.1.0 IS NOW PRE-RELEASED!

The Seeker is JRPG style ASCII art game run in console.

## Game Demo Video.

[![Video Label](https://img.youtube.com/vi/g0UUar3ZoRY/0.jpg)](https://www.youtube.com/watch?v=g0UUar3ZoRY)

## Contributing

The project is an open-source project, written in C.

If you want to contribute, first, you must download _**FMOD Engine**_, which is use for Sound System.

The latest version of FMOD Engine is not allowed. You must download _**FMOD Engine 2.01.05 windows version**_ [here](https://www.fmod.com/download#fmodengine).

### IDE

It is recommended to use Visual Studio 2022 IDE.

## Building

This project is only avaliable for window system. The other OS has not been tested.

First, you must download FMOD Engine 2.01.05 window version [here](https://www.fmod.com/download#fmodengine).

The latest version of FMOD Engine has changes in function usage, causing source code to not function properly when used.

### IDE Setting

If you use Visual Studio 2022 IDE, you must set the directory of FMOD.

1. Project -> Property -> V/C++ directories -> Include Directories : Add the path to the "inc" folder of the FMOD Engine.

      `C:\Program Files (x86)\FMOD SoundSystem\FMOD Studio API Windows\api\core\inc;`

2. Project -> Property -> Linker -> General Property Page -> Additional Library Directories : Add the path to the "lib\x86" folder of the FMOD Engine.


      `C:\Program Files (x86)\FMOD SoundSystem\FMOD Studio API Windows\api\core\lib\x86`

    You must use x86. not x64. 

3. Project -> Property -> Linker -> Input Property Page -> Additional Dependencies : Add "fmod_vc.lib".

    `fmod_vc.lib`

Now you can use FMOD Engine to the project.

Set the Debug mode x86. If you use x64 to build this project, it could have compile error.

Releas mode is same as Debug mode.

## Feature Requests

Post feature requests and feedback [here](https://github.com/Serun1017/19011625_openSource_Subject5/issues).

## Downloads

Download the latest realeased version [here](https://github.com/Serun1017/19011625_openSource_Subject5/releases/tag/release_v.1.0)!

If you want to play it, you must download release version of _**The_Seeker.zip**_.

Unzip the zip file and run _**TheSeeker_1.exe**_ as Administrator.

If you do not run it as Administrator, the game screen could appears broken.
