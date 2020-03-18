# Particle Simultation

This is a small project that uses the SDL 2 library to display a window with particles that move around in different patterns. It is based on the example project from John Purcell's [Cave of Programming C++ Begineer Course](https://courses.caveofprogramming.com/p/c-beginners)

## Requirements

In order to successfully compile and run this project, you will need to have the SDL 2 libraries on your system.

### For Linux

Install the libsdl2-2.0-0 and libsdl2-dev libraries.

### For Windows

MinGW with g++ compiler should be installed on your system.

Download the latest _SDL2-devel-2.x.x-mingw_ from [SDL's official page](https://www.libsdl.org/index.php) and uncompress on an easy access directory (such as C:\SDL, for example). 

From the folder named with your desired architecture, copy the _bin_ folder's content onto your MinGW's _bin_ folder, and the _include_ folder's contents onto MinGW's _include_

## Compilation

Compile on Linux with **g++ \*.cpp \`sdl2-config --cflags --libs\`**

Compile on Windows (using MinGW's g++ compiler and assuming SDL root is at C:\\) with **g++ \*.cpp -IC:\\SDL\\include -LC:\\SDL\\i686-w64-mingw32\\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2**

## Execution

Run on a CLI with program arguments: mode number, anything (optional), anything (optional)

Running with no optional arguments it will just display the patterns, with one it will disable clear screen, and with two it will enable box blur

Modes are:

- 1: Flower pattern
- 2: Spiral
- 3: Rectangular explosion
- 4: Circular explosion
- 5: Circular implosion

For example: **./a.out 5 x x**

![Screenshot of one of the animations, with an implemented effect of box blur](https://jcalvarezj.github.io/img/Particles.png)
