TARGET = Wagman
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
FLASHER_CONFIGS = /etc/avrdude.conf
FLASH_BOARD = $(FLASHER) -l flash_avr.log -C$(FLASHER_CONFIGS) -v -p$(TYPE) -c$(BOOT_LOADER_TYPE) -P$(PORT) -b$(FLASHER_BAUD_RATE) -D -Uflash:w:$(BIN_DIR)/$(TARGET).ino.hex:i
LINKPORT = $(PORT)
SERIALBAUD = 115200
BIN_DIR = ./bin
CFLAGS  = --verbose-build --verify

clean:
	rm -rf $(BUILD_DIR)/*
	rm -f *~


program:
	$(PRE_FLASH_COMMAND)
	$(FLASH_BOARD)

