PROJNAME := Chip8Emulator
BINDIR := bin
BUILDDIR := build
SRCDIR := src
INCDIR := include

INCPATH := $(INCDIR)

CC := clang++
CFLAGS := -Wall -std=c++17 -I$(INCPATH)
LDFLAGS :=

BIN := $(BINDIR)/$(PROJNAME)

OBJ := $(BUILDDIR)/main.o
OBJ += $(BUILDDIR)/AudioEngine.o
OBJ += $(BUILDDIR)/Chip8_Keypad.o
OBJ += $(BUILDDIR)/Chip8_Memory.o
OBJ += $(BUILDDIR)/Chip8_MemoryRegion_Cartridge.o
OBJ += $(BUILDDIR)/Chip8_MemoryRegion_Framebuffer.o
OBJ += $(BUILDDIR)/Chip8_MemoryRegion.o
OBJ += $(BUILDDIR)/Chip8_MemoryRegion_System.o
OBJ += $(BUILDDIR)/Chip8_RegisterFile.o
OBJ += $(BUILDDIR)/Chip8_System.o
OBJ += $(BUILDDIR)/InputEngine.o
OBJ += $(BUILDDIR)/VideoEngine.o


all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/AudioEngine.o: $(SRCDIR)/AudioEngine.cpp $(INCDIR)/AudioEngine.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_Keypad.o: $(SRCDIR)/Chip8_Keypad.cpp $(INCDIR)/Chip8_Keypad.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_Memory.o: $(SRCDIR)/Chip8_Memory.cpp $(INCDIR)/Chip8_Memory.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_MemoryRegion_Cartridge.o: $(SRCDIR)/Chip8_MemoryRegion_Cartridge.cpp $(INCDIR)/Chip8_MemoryRegion_Cartridge.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_MemoryRegion_Framebuffer.o: $(SRCDIR)/Chip8_MemoryRegion_Framebuffer.cpp $(INCDIR)/Chip8_MemoryRegion_Framebuffer.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_MemoryRegion.o: $(SRCDIR)/Chip8_MemoryRegion.cpp $(INCDIR)/Chip8_MemoryRegion.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_MemoryRegion_System.o: $(SRCDIR)/Chip8_MemoryRegion_System.cpp $(INCDIR)/Chip8_MemoryRegion_System.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_RegisterFile.o: $(SRCDIR)/Chip8_RegisterFile.cpp $(INCDIR)/Chip8_RegisterFile.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_System.o: $(SRCDIR)/Chip8_System.cpp $(INCDIR)/Chip8_System.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/InputEngine.o: $(SRCDIR)/InputEngine.cpp $(INCDIR)/InputEngine.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/VideoEngine.o: $(SRCDIR)/VideoEngine.cpp $(INCDIR)/VideoEngine.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<


.PHONY: clean
clean:
	rm -rf $(BIN)
	rm -rf $(OBJ)
	@if [ -e $(BINDIR) ]; then rmdir $(BINDIR); fi
	@if [ -e $(BUILDDIR) ]; then rmdir $(BUILDDIR); fi

.PHONY: run
run:
	@./$(BIN)
