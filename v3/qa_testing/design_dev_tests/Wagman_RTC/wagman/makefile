ARD_HOME = /home/rajesh/WaggleGIT/arduino-1.6.7
TARGET = wagman
PACKAGE = arduino
ARCH = avr
BOARD = micro
TYPE = m32u4
FLASHER_BAUD_RATE = 57600
PORT = /dev/waggle_sysmon
BOARD_FLASH = $(PACKAGE):$(ARCH):$(BOARD)
BOOT_LOADER_TYPE = avr109
PRE_FLASH_COMMAND = stty -F $(PORT) 1200 hupcl; sleep 5
FLASHER = avrdude
FLASH_BOARD = $(FLASHER) -v -p$(TYPE) -c$(BOOT_LOADER_TYPE) -P$(PORT) -b$(FLASHER_BAUD_RATE) -D -Uflash:w:$(BIN_DIR)/$(TARGET).ino.hex:i
BUILD_COMPLETE = mv $(BUILD_DIR)/$(TARGET).ino.hex $(BIN_DIR)/
LINKPORT = $(PORT)
SERIALBAUD = 115200
BOOT_LOADER = $(FLASHER) -C$(FLASHER_CONFIGS) -v -patmega32u4 -cstk500v2 -Pusb -Uflash:w:$(ARD_HOME)/hardware/arduino/avr/bootloaders/caterina/Caterina-Micro.hex:i -Ulock:w:0x2F:m
CC = $(ARD_HOME)/arduino
BUILD_DIR = ./build
BIN_DIR = ./bin
CFLAGS  = --verbose-build --verify

all: clean
	./timeset.sh
	make $(TARGET)
	mv $(BIN_DIR)/$(TARGET).ino.hex $(BIN_DIR)/$(TARGET)_RTC_set.ino.hex
	echo "" > rtc_conf.cpp
	make clean
	make $(TARGET)
	mv $(BIN_DIR)/$(TARGET).ino.hex $(BIN_DIR)/$(TARGET)_test.ino.hex
	make clean

$(TARGET): $(TARGET).ino
	$(CC) --board $(BOARD_FLASH) $(CFLAGS) --pref build.path=$(BUILD_DIR) $(TARGET).ino
	$(BUILD_COMPLETE)

clean:
	rm -rf $(BUILD_DIR)/*
	rm -f *~

reset:
	$(PRE_FLASH_COMMAND)

initialize: clean
	./timeset.sh
	make $(TARGET)
	$(PRE_FLASH_COMMAND)
	$(FLASH_BOARD)
	mv $(BIN_DIR)/$(TARGET).ino.hex $(BIN_DIR)/$(TARGET)_RTC_set.ino.hex
	echo "" > rtc_conf.cpp
	make clean
	make $(TARGET)
	sleep 10
	$(PRE_FLASH_COMMAND)
	$(FLASH_BOARD)
	mv $(BIN_DIR)/$(TARGET).ino.hex $(BIN_DIR)/$(TARGET)_test.ino.hex
	make clean

program:
	$(PRE_FLASH_COMMAND)
	$(FLASHER) -l flash_avr.log -C$(FLASHER_CONFIGS) -v -p$(TYPE) -c$(BOOT_LOADER_TYPE) -P$(PORT) -b$(FLASHER_BAUD_RATE) -D -Uflash:w:$(BIN_DIR)/$(TARGET)_RTC_set.ino.hex:i
	sleep 8
	$(PRE_FLASH_COMMAND)
	$(FLASHER) -l flash_avr.log -C$(FLASHER_CONFIGS) -v -p$(TYPE) -c$(BOOT_LOADER_TYPE) -P$(PORT) -b$(FLASHER_BAUD_RATE) -D -Uflash:w:$(BIN_DIR)/$(TARGET)_test.ino.hex:i
	sleep 3

connect:
	sleep 3
	screen $(LINKPORT) $(SERIALBAUD)

test:
	$(PRE_FLASH_COMMAND)
	sleep 8
	screen $(LINKPORT) $(SERIALBAUD)
