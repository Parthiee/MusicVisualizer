#!/bin/sh

# CFLAGS="-Wall -Wextra `pkg-config --cflags raylib`"
# LIBS="`pkg-config --libs --cflags raylib` -lglfw -lm -ldl -lpthread"

# gcc  $CFLAGS main.c -o main $LIBS

gcc -o main main.c -lraylib -lm -lpthread -ldl -lrt -lX11
