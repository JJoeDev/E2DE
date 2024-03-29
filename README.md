# E2DE (Ego 2D Engine)

E2DE aka Ego 2D Engine is a simple 2D game engine/Framework I am developing for myself to use and challenge myself. For a more in depth indtroduction, take a read [here](#what-is-this-exactly)


## Notice

**I made some dumb decitions when making this project and I am too lazy to figure out what needs to be done to fix the current state of E2DE. I have learned a lot and I will be making a new and hopefully better version**

---

[What is E2DE](#what-is-this-exactly)

[License](#license)

[Development code](#latest-development-build)

[How do I try it](#instalation-and-setup)

- [Windows](#windows)

- [Linux](#linux)

[Engine Features](#features)

[My tasks](#working-on)

[Libraries in use](#libraries)

---

## What is this exactly?

E2DE is a simple 2D game engine/Framework I am developing using C++. The purpose for this project is to simple have something for myself to keep developing on, and keep me ingaged.

I know this game engine is not geing to challenge the big onse like GDevelop, Godot, or Unreal Engine, but that is also not really the goal.

This is again simply to keep me learning more complex C++ topics and how to structure and manage a large project. It is also just really fun to be able to tell people I made my own game engine. I do however aim to add more and more to the engine, and maybe even try to add 3D by using OpenGL with SDL2.

---

## Latest development build

### DISCLAIMER

If you are considering on trying out the dev branch just be warned that it might not work. I try to only push code that does compile, but at times I will have to also push some code that I am activly working on. 

[Here is where you can get the latest dev build](https://github.com/jJoeDev/e2de/tree/dev)

## Instalation and setup

**E2DE is still in its early stages and is not even close to be an ideal choice for a game engine. You are welcome to give it a try, but be warned, it is missing a lot of features.**

#### WINDOWS

Sorry to dissapoint, but I have been prioritizing the Linux version as I myself am a linux user, I have not been taking the time to figure out how you install premake on Windows or how I am supposed to compile the engine on Windows. But in some point in the future I will be adding Windows support

#### LINUX

**REQUIREMENTS**

You need to have cmake, make, and premake installed.

Premake5 can be installed on arch based distros using ``sudo pacman -S premake`` and on fedora based distros its ``sudo dnf install premake``

You can check if premake is installed by running ``premake5 --version``

---

1. Start by cloning either master or dev version of the engine using either<br> ``git clone --recursive https://github.com/JJoeDev/E2DE.git`` and get the dev by adding ``-b dev`` to the end

2. You have to build SDL2 yourself for now, so go ahead and make your way to the Vendor directory in the engine code at ``E2DE/E2DE/Vendor`` and add a build directory
after making the build directory you can run<br> ``cmake /SDL2 -B /build`` once cmake is done you are free to run ``make -C build``

3. Perfect, now SDL2 should have build correctly. You can now go back to the global E2DE directory (The first one) and run the testrun shell script to build the engine, demo, and run the demo. 
``./testrun-d.sh``

---

### Features
| Features | STATUS | Branch | Message |
| - | - | - | - |
| Window Creation | WORKING | main | I wanted to use BGFX, but I could not get it to work with premake, so its pure SDL now |
| Basic inputs | BASIC SUPPORT (Keyboard only) | main | It works for now, but I need mouse input at some point |
| ECS | WORKING | main | Should be stable enough for now |
| Scenes | W.I.P | main | They exist, but need more work |
| Rendering | W.I.P | main | They can only render a rect with a color for now |

---

### Libraries
| Libraries | Branch |
| - | - |
| [SDL2](https://www.libsdl.org/) | main |
| [EnTT](https://github.com/skypjack/entt) | dev |


### Working on
| Task | Status | Branch | Message |
| - | - | - | - |
| Sprite loading | Working on | dev | I am working on this now so I can get it working asap |
| Better event system | For the future | N/A | The current event system works for now |
| Sprite layers | For the future | N/A | I will probably be working on this when sprites are working |
| Better scene system | For the future | N/A | Sprites are sadly far too important for now |
| Particle system | For the future | N/A | I really want to make this asap |
| Camera system | For the future | N/A | This is not that important for me yet, but at some point I will probably make this |

### License

[This project](LICENSE) uses GPL3 (GNU GENERAL PUBLIC LICENSE Version 3) 
