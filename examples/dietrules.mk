
DIET ?= diet
DIET_CC ?= $(DIET) $(CC)
DIET_CFLAGS ?= $(CFLAGS)
DIET_LDLIBS ?= $(LDLIBS)

.SUFFIXES: .diet .diet.o

%.diet: %.c
	$(DIET_CC) $(DIET_CFLAGS) $(DIET_LDFLAGS) $^ $(DIET_LDLIBS) -o $@

%.diet: %.diet.o
	$(DIET_CC) $(DIET_LDFLAGS) $(DIET_LDFLAGS) $^ $(DIET_LDLIBS) -o $@

%.diet.o: %.c
	$(DIET_CC) $(DIET_CFLAGS) -c $^ -o $@
