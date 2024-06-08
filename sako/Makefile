
TITLE_ID = VITA2DTST
TARGET   = vita2dsample
OBJS     = font.o main.o gMenu.o graphics/chars/bodies/base/legs_idle_24x24.o image.o bullet.o zombie.o image1.o image2.o target.o tileset.o bg.o blocks.o cursor.o menuBG.o icon.o levelcursor.o write_read.o util.o gMenu.o vec.o \
		Nogg/src/util/memory.o \
		Nogg/src/util/float-to-int16.o \
		Nogg/src/util/decode-frame.o \
		Nogg/src/decode/stb_vorbis.o \
		Nogg/src/decode/setup.o \
		Nogg/src/decode/seek.o \
		Nogg/src/decode/packet.o \
		Nogg/src/decode/io.o \
		Nogg/src/decode/decode.o \
		Nogg/src/decode/crc32.o \
		Nogg/src/api/version.o \
		Nogg/src/api/seek-tell.o \
		Nogg/src/api/read-int16.o \
		Nogg/src/api/read-float.o \
		Nogg/src/api/open-file.o \
		Nogg/src/api/open-callbacks.o \
		Nogg/src/api/open-buffer.o \
		Nogg/src/api/info.o \
		Nogg/src/api/close.o \
		Media/WavFile.o \
		Media/FileBuffer.o \
		Media/Audio.o
				
LIBS += -lSceDisplay_stub

LIBS = -lvita2d -lSceDisplay_stub -lSceTouch_stub -lSceGxm_stub \
	-lSceSysmodule_stub -lSceAudio_stub -lSceCtrl_stub -lScePgf_stub -lScePvf_stub \
	-lSceCommonDialog_stub  -lSceAudioIn_stub -lSceAudiodec_stub -ltinyxml2 -lfreetype -lpng -ljpeg -lz  -lc -lSceAppMgr_stub -lsoloud -lvorbis -lvorbisenc -logg -lvorbisfile -lm  -lmad

PREFIX  = arm-vita-eabi
CC      = $(PREFIX)-gcc
CFLAGS  = -Wl,-q -Wall -fno-lto
ASFLAGS = $(CFLAGS)

# Link against the locally-built version of libvita2d if possible
LIBS += -L../libvita2d 
CFLAGS += -I../libvita2d/include -I./Nogg -I./Media

all: $(TARGET).vpk

%.vpk: eboot.bin
	vita-mksfoex -s TITLE_ID=$(TITLE_ID) "$(TARGET)" param.sfo
	vita-pack-vpk -s param.sfo -b eboot.bin $@ \
	--add Sounds/music.wav \

eboot.bin: $(TARGET).velf
	vita-make-fself -s $< $@

%.velf: %.elf
	vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

%.o: %.png
	$(PREFIX)-ld -r -b binary -o $@ $^

clean:
	@rm -rf $(TARGET).vpk $(TARGET).velf $(TARGET).elf $(OBJS) \
		eboot.bin param.sfo

vpksend: $(TARGET).vpk
	curl -T $(TARGET).vpk ftp://$(PSVITAIP):1337/ux0:/
	@echo "Sent."

send: eboot.bin
	curl -T eboot.bin ftp://$(PSVITAIP):1337/ux0:/app/$(TITLE_ID)/
	@echo "Sent."
