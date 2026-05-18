set -eux

CFLAGS="\
-pipe -std=c99 -pedantic -Wall -Wno-deprecated-declarations -O0 \
-D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700L -DVERSION=\"6.8\" \
-I/usr/include/freetype2 \
"

#test -f drw.o || gcc -c $CFLAGS drw.c

gcc -o dwm $CFLAGS -Wunused-macros -lX11 -lfontconfig -lXft drw.c dwm.c
