# E2DE (Ego 2D Engine)

This is a simple 2D game engine that I am making at the moment because I have wanted to do it for quite a while

The engine is not supposed to compete against other engines like Unity, Godot, or GDevelop, it is only supposed to be something I use for small 2D games, but lets see how long that stays true

---

[What is E2DE](#what-is-this-exactly)

[Development code](#latest-development-build)

[How do I try it](#instalation-and-setup)

[Engine Features](#features)

[Libraries in use](#libraries)

---

## What is this exactly?

E2DE is a simple game engine I am writing in C++ to learn more complex C++ topics and to get a bigger project on github. But it is also because I love a challenge and for the last year i have been making small games in frameworks like SDL2 Raylib and SFML.

Now they are all awesome and good frameworks, some easier than others. But I want a "higher level" framework that can do more with less code, that is why I am developing E2DE. But I do have plans on making it a full on engine in the future once I am comfortable with the featureset of the engine.

---

## Latest development build

If you for some reason would like to take a look at the what I am activly working on, you can take a loot at the dev branch. It is where I will push test code or just unfinished code.

## Instalation and setup

E2DE is not even close to being ready for use yet, but if you really want to try it you can always clone the repo and run it just like I do at the moment

#### WINDOWS

If you are on windows, then you will have to figure out how to link to SDL2 your self, as I have been working on the linux part first

#### LINUX

Start out by installing premake5. In arch based distros it's as simple as running ```sudo pacman -S premake``` and on fedora based distros its ```sudo dnf install premake```

You can check if premake is installed by running ```premake5 --version```

You should also have both cmake and make installed, but I won't go over that here

---

1. Start by cloning either master or dev version of the engine using either ```git clone --recursive https://github.com/JJoeDev/E2DE.git``` and get the dev by adding ```-b dev``` to the end

2. You have to build SDL2 yourself for now, so go ahead and make your way to the Vendor directory in the engine code at ```E2DE/E2DE/Vendor``` and add a build directory
after making the build directory you can run ```cmake /SDL2 -B /build``` once cmake is done you are free to run ```make -C build```

3. Perfect, now SDL2 should have build correctly. You can now go back to the global E2DE directory (The first one) and run the testrun shell script to build the engine, demo, and run the demo. 
```./testrun-d.sh```

---

### Features
| Features | STATUS | Branch |
| - | - | - |
| Window Creation | WORKING | main |
| Basic inputs | BASIC SUPPORT (Keyboard only) | main |
| Rendering | W.I.P | dev |

---

### Libraries
| Libraries | Branch |
| - | - |
| [SDL2](https://www.libsdl.org/) | main |
| [EnTT](https://github.com/skypjack/entt) | N/A |