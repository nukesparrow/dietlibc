#!/bin/sh

ARGS="$@"

#MAKEFLAGS=-j12

MIN_FEATURES="-WANT_DYNAMIC -WANT_SSP -WANT_STACKGAP -WANT_TLS"
#MIN_FEATURES="$MIN_FEATURES -WANT_THREAD_SAFE"
#MIN_FEATURES="$MIN_FEATURES -WANT_FREAD_OPTIMIZATION"
#MIN_FEATURES="$MIN_FEATURES -WANT_FASTER_STRING_ROUTINES"
#MIN_FEATURES="$MIN_FEATURES -WANT_LINKER_WARNINGS"
#MIN_FEATURES="$MIN_FEATURES -WANT_HIGH_PRECISION_MATH"
#MIN_FEATURES="$MIN_FEATURES -WANT_VALGRIND_SUPPORT"
#MIN_FEATURES="$MIN_FEATURES -WANT_GNU_STARTUP_BLOAT"

[ "$FEATURES" = "" ] && FEATURES="$MIN_FEATURES"
[ "$CC" = "" ] && CC=cc

src=../
arch=`$CC -dumpmachine | sed -e 's/-.*//' -e 's/i[4-9]86/i386/' -e 's/armv[3-6]t\?e\?[lb]/arm/' -e 's/parisc64/parisc/'`
prefix2=_min

echo Arch: $arch

CFLAGS="$CFLAGS -ffunction-sections -fdata-sections"
CFLAGS="$CFLAGS -fomit-frame-pointer"
CFLAGS="$CFLAGS -fno-unwind-tables -fno-asynchronous-unwind-tables"
CFLAGS="$CFLAGS -fno-math-errno"
CFLAGS="$CFLAGS -fno-unroll-loops"
CFLAGS="$CFLAGS -fmerge-all-constants"
CFLAGS="$CFLAGS -fno-ident"
CFLAGS="$CFLAGS -fshort-double -fsingle-precision-constant"
CFLAGS="$CFLAGS -ffast-math"
CFLAGS="$CFLAGS -falign-functions=1"

make $MAKEFLAGS -C "$src" clean all prefix2="$prefix2" CC="$CC" FEATURES="$FEATURES" EXTRACFLAGS="$CFLAGS" $ARGS || exit 1
#make $MAKEFLAGS -C "$src" install prefix2="$prefix2" CC="$CC"
