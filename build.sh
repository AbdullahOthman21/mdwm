CFLAGS="\
-pipe -std=c99 -Wall -Wno-deprecated-declarations -Wunused-macros -Os \
-D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700L \
-I/usr/include/freetype2 \
"

test -f drw.o || gcc -c $CFLAGS drw.c

gcc -o dwm $CFLAGS -lX11 -lfontconfig -lXft drw.o dwm.c
