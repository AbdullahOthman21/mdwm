#!/bin/sh

CFLAGS="\
-pipe -std=c99 -Wall -Wno-deprecated-declarations -Wunused-macros -Os \
-D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700L \
-I/usr/include/freetype2 \
"

if [ ! -e drw.o ]; then
	gcc -c $CFLAGS drw.c
fi

gcc -c $CFLAGS mdwm.c
gcc -lX11 -lfontconfig -lXft mdwm.o drw.o -o mdwm && mv mdwm bin/
rm -f mdwm.o

if [ "$1" = install ]; then
	mv bin/mdwm /usr/local/bin/
fi
