# Particle Simultation

This is a small project that uses the SDL library to display a window with particles that move around

Compile on Linux with **g++ \*.cpp \`sdl2-config --cflags --libs\`**
Compile on Windows (using MinGW's g++ compiler and assuming SDL root is at C:\\) with **g++ \*.cpp -IC:\\SDL\\include -LC:\\SDL\\i686-w64-mingw32\\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2**
