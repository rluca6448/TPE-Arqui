include ../Makefile.inc

MODULE=0000-sampleCodeModule.bin
SOURCES=$(wildcard [^_]*.c)
SOURCES_ASM = $(wildcard *.asm)
OBJECTS = $(SOURCES:.c=.o) $(SOURCES_ASM:.asm=.o)

all: $(MODULE)

$(MODULE): $(OBJECTS) _loader.o
	$(GCC) $(GCCFLAGS) -T sampleCodeModule.ld _loader.o $(OBJECTS) -o ../$(MODULE)
	$(GCC) $(GCCFLAGS) -I./include -T sampleCodeModule.ld -Wl,--oformat=elf64-x86-64 _loader.c $(OBJECTS) -o ../0000-sampleCodeModule.elf

_loader.o: _loader.c
	$(GCC) $(GCCFLAGS) -c _loader.c -o _loader.o

%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

%.o: %.c
	$(GCC) $(GCCFLAGS) -c $< -o $@

clean:
	rm -rf *.o

.PHONY: all clean print
