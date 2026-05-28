set -eux

CFLAGS="\
-pipe -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os \
-D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700L \
-I/usr/include/freetype2 \
"

test -e drw.o || gcc -c $CFLAGS drw.c

gcc -o dwm $CFLAGS -Wunused-macros -lX11 -lfontconfig -lXft drw.o dwm.c
