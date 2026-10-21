AS := nasm
ASF := -f elf64 -F DWARF -g -Wall
LD := ld
LDF := -g
TARGET := p
v ?=

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(LD) $(LDF) $< -o $@
ifdef v
	cp $@ p$(v)
endif

$(TARGET).o: $(TARGET).asm
	$(AS) $(ASF) $< -o $@
ifdef v
	cp $< p$(v).asm
endif

clean:
		rm -rf *.o

