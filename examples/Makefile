
#DEBUG ?= 1

$(eval CC_ARCH = $(shell $(CROSS)$(CC) -dumpmachine | sed -e 's/-.*//' -e 's/i[4-9]86/i386/' -e 's/armv[3-6]t\?e\?[lb]/arm/' -e 's/parisc64/parisc/'))

DIETPREFIX?=../bin-$(CC_ARCH)/

CC = $(DIETPREFIX)diet $(CROSS)gcc
CFLAGS += -pipe -Os
ifeq ($(DEBUG),1)
CFLAGS += -g
else
CFLAGS += -s
endif
LDFLAGS += -Os -static

CFLAGS += -ffunction-sections -fdata-sections
LDFLAGS += -Wl,--gc-sections
CFLAGS += -fomit-frame-pointer
CFLAGS += -fno-unwind-tables -fno-asynchronous-unwind-tables
CFLAGS += -fno-math-errno
CFLAGS += -fno-unroll-loops
CFLAGS += -fmerge-all-constants
CFLAGS += -fno-ident
CFLAGS += -fshort-double -fsingle-precision-constant
#CFLAGS += -ffast-math
LDFLAGS += -Wl,-z,norelro

CFLAGS += -falign-functions=1

LDFLAGS += -flto


EXAMPLES=sln helloworld pi tiny

all: $(EXAMPLES)

%: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@
ifneq ($(DEBUG),1)
	$(CROSS)strip --strip-all $@
	$(DIETPREFIX)elftrunc $@ $@~ && mv $@~ $@
endif

%: %.o
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
ifneq ($(DEBUG),1)
	$(CROSS)strip --strip-all $@
	$(DIETPREFIX)elftrunc $@ $@~ && mv $@~ $@
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) -f $(EXAMPLES)
