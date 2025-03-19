CC      = /opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j
BINS    = trex.gb
SRCS    = globals.c rand.c text.c trex.c \
          game/cacti.c game/cactus_sprite.c game/game.c game/scoreboard.c game/trex_init.c game/trex_sprite.c \
          game_over/game_over.c \
          menu/logo_sprite.c menu/menu.c \
          sprites/alphabet.c sprites/numbers.c \
          bkg/bkg.c bkg/floor_map.c bkg/floor_tiles.c
OBJS    = $(SRCS:.c=.o)

all: $(BINS)

$(BINS): $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $< -o $@

compile.bat: Makefile
	@echo "REM Automatically generated from Makefile" > compile.bat
	@make -sn | sed y/\\//\\\\/ | grep -v make >> compile.bat

clean:
	rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm *.noi
	rm -rf game/*.o game_over/*.o menu/*.o sprites/*.o
	rm -rf game/*.asm game_over/*.asm menu/*.asm sprites/*.asm
	rm -rf game/*.lst game_over/*.lst menu/*.lst sprites/*.lst
	rm -rf game/*.sym game_over/*.sym menu/*.sym sprites/*.sym

