# E2DE (Ego 2D Engine)

This is a simple 2D game engine that I am making at the moment because I have wanted to do it for quite a while

The engine is not supposed to compete against other engines like Unity, Godot, or GDevelop, it is only supposed to be something I use for small 2D games, but lets see how long that stays true

---

[What is E2DE](#what-is-this-exactly)

[How do I try it](#instalation-and-setup)

[Engine Features](#features)

[Libraries in use](#libraries)

---

## What is this exactly?

E2DE is a simple game engine I am writing in C++ to learn more complex C++ topics and to get a bigger project on github. But it is also because I love a challenge and for the last year i have been making small games in frameworks like SDL2 Raylib and SFML.

Now they are all awesome and good frameworks, some easier than others. But I want a "higher level" framework that can do more with less code, that is why I am developing E2DE. But I do have plans on making it a full on engine in the future once I am comfortable with the featureset of the engine.

---

## Instalation and setup

E2DE is not even close to being ready for use yet, but if you really want to try it you can always clone the repo and run it just like I do at the moment

#### WINDOWS

If you are on windows, then you will have to figure out how to link to SDL2 your self, as I have been working on the linux part first

#### LINUX

Start by installing premake, on arch based distros its as simple as ```sudo pacman -S premake```

you can check if it is installed correctly by running ```premake5 --version```

1. git clone https://github.com/JJoeDev/E2DE.git

2. Work your way to E2DE/E2DE/Vendor/SDL2/Linux and create a directory called "build"

3. cd into SDL2-2.28.4 and run ```cmake . -B ../build```

4. now you can go back to ../build and run the ```make``` command like this: make

5. That should be everything, to check if it is running you can go back to ../../../../../ and run ./build-d.sh to build the engine library file

6. After building the engine library file go to E2DE and run: ```premake5 gmake2``` and after that run ```make -C build/```

7. Now you should be able to run the demo "game" by ```./bin/Debug/Demo```

---

### Features
| Features | STATUS |
| - | - |
| Window Creation | WORKING |
| Basic inputs | BASIC SUPPORT (Keyboard only) |
| Rendering | W.I.P |

---

### Libraries
| Libraries |
| - |
| SDL2 (for window and input) |


