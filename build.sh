CFLAGS="\
-pipe -std=c99 -Wall -Wno-deprecated-declarations -Wunused-macros -Os \
-D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700L \
-I/usr/include/freetype2 \
"

test -e drw.o || gcc -c $CFLAGS drw.c

gcc -c $CFLAGS dwm.c
gcc -lX11 -lfontconfig -lXft dwm.o drw.o -o dwm
rm dwm.o
mv dwm bin/
