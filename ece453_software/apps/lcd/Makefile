FILENAME=test_slideshow
CC=arm-linux-gnueabihf-gcc
IDIR =../include
CFLAGS=-I$(IDIR) `pkg-config --cflags mpv`
LFLAGS=`pkg-config --libs mpv`
LIBS=
ODIR=../obj

DRV_FILES  := $(wildcard ../drivers/*.c)
DOBJ_FILES := $(patsubst ../drivers/%.c,../obj/%.o,$(DRV_FILES))

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(FILENAME).o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(FILENAME): $(DOBJ_FILES) $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: ../drivers/%.c
	$(CC) -c -o $@ $< $(CFLAGS)


print-%  : ; @echo $* = $($*)

.PHONY: clean

clean:
	rm -f $(FILENAME) $(ODIR)/*.o *~ core $(INCDIR)/*~ 
