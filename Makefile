# TODO: Write a tool to generate this Makefile (or stop being stubborn and use cmake, lmao)

PROJNAME := Chip8Emulator
BINDIR := bin
BUILDDIR := build
SRCDIR := src
INCDIR := include

INCPATH := $(INCDIR)

CC := clang++
CFLAGS := -Wall -std=c++17 -I$(INCPATH)
LDFLAGS := -lSDL2

BIN := $(BINDIR)/$(PROJNAME)

OBJ := $(BUILDDIR)/main.o
OBJ += $(BUILDDIR)/Chip8_System.o
OBJ += $(BUILDDIR)/Chip8_Keypad.o
OBJ += $(BUILDDIR)/Chip8_RegisterFile.o
OBJ += $(BUILDDIR)/Chip8_Memory.o
OBJ += $(BUILDDIR)/Chip8_MemoryRegion.o
OBJ += $(BUILDDIR)/Chip8_SystemReserved.o
OBJ += $(BUILDDIR)/Chip8_Cartridge.o
OBJ += $(BUILDDIR)/Chip8_Framebuffer.o
OBJ += $(BUILDDIR)/Multimedia_Video.o
OBJ += $(BUILDDIR)/Multimedia_Audio.o
OBJ += $(BUILDDIR)/Multimedia_Input.o
OBJ += $(BUILDDIR)/Multimedia_utils.o


all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_System.o: $(SRCDIR)/Chip8_System.cpp $(INCDIR)/Chip8_System.hpp $(INCDIR)/Chip8_RegisterFile.hpp $(INCDIR)/Chip8_Memory.hpp $(INCDIR)/Chip8_SystemReserved.hpp $(INCDIR)/Chip8_Cartridge.hpp $(INCDIR)/Chip8_Framebuffer.hpp $(INCDIR)/Multimedia_Video.hpp $(INCDIR)/Chip8_config.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_Keypad.o: $(SRCDIR)/Chip8_Keypad.cpp $(INCDIR)/Chip8_Keypad.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_RegisterFile.o: $(SRCDIR)/Chip8_RegisterFile.cpp $(INCDIR)/Chip8_RegisterFile.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_Memory.o: $(SRCDIR)/Chip8_Memory.cpp $(INCDIR)/Chip8_Memory.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_MemoryRegion.o: $(SRCDIR)/Chip8_MemoryRegion.cpp $(INCDIR)/Chip8_MemoryRegion.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_SystemReserved.o: $(SRCDIR)/Chip8_SystemReserved.cpp $(INCDIR)/Chip8_SystemReserved.hpp $(INCDIR)/Chip8_MemoryRegion.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_Cartridge.o: $(SRCDIR)/Chip8_Cartridge.cpp $(INCDIR)/Chip8_Cartridge.hpp $(INCDIR)/Chip8_MemoryRegion.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Chip8_Framebuffer.o: $(SRCDIR)/Chip8_Framebuffer.cpp $(INCDIR)/Chip8_Framebuffer.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Multimedia_Video.o: $(SRCDIR)/Multimedia_Video.cpp $(INCDIR)/Multimedia_Video.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Multimedia_Audio.o: $(SRCDIR)/Multimedia_Audio.cpp $(INCDIR)/Multimedia_Audio.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Multimedia_Input.o: $(SRCDIR)/Multimedia_Input.cpp $(INCDIR)/Multimedia_Input.hpp $(INCDIR)/Input_config.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILDDIR)/Multimedia_utils.o: $(SRCDIR)/Multimedia_utils.cpp $(INCDIR)/Multimedia_utils.hpp $(INCDIR)/Multimedia_config.hpp Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) -o $@ $<


.PHONY: clean
clean:
	rm -rf $(BIN)
	rm -rf $(OBJ)
	@if [ -e $(BINDIR) ]; then rmdir $(BINDIR); fi
	@if [ -e $(BUILDDIR) ]; then rmdir $(BUILDDIR); fi

.PHONY: clean-build
clean-build: clean all

.PHONY: run
run:
	@./$(BIN)
