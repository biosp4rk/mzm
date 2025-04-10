# Disable built-in rules
.SUFFIXES:

REGION ?= us

ifeq ($(REGION),us)
	TARGET = mzm_us.gba
	BASEROM = mzm_us_baserom.gba
	SHA1FILE = mzm_us.sha1
	GAME_TITLE = ZEROMISSIONE
	GAME_CODE = BMXE
	CPPFLAGS += -DREGION_US
endif

# ifeq ($(REGION),us_beta)
# 	TARGET = mzm_us_beta.gba
# 	BASEROM = mzm_us_beta_baserom.gba
# 	SHA1FILE = mzm_us_beta.sha1
# 	GAME_TITLE = ZEROMISSIONE
# 	GAME_CODE = BMXE
# 	CPPFLAGS += -DREGION_US_BETA
# endif

# ifeq ($(REGION),eu)
# 	TARGET = mzm_eu.gba
# 	BASEROM = mzm_eu_baserom.gba
# 	SHA1FILE = mzm_eu.sha1
# 	GAME_TITLE = ZEROMISSIONP
# 	GAME_CODE = BMXP
# 	CPPFLAGS += -DREGION_EU
# endif

# ifeq ($(REGION),jp)
# 	TARGET = mzm_jp.gba
# 	BASEROM = mzm_jp_baserom.gba
# 	SHA1FILE = mzm_jp.sha1
# 	GAME_TITLE = ZEROMISSIONJ
# 	GAME_CODE = BMXJ
# 	CPPFLAGS += -DREGION_JP
# endif

# ifeq ($(REGION),cn)
# 	TARGET = mzm_cn.gba
# 	BASEROM = mzm_cn_baserom.gba
# 	SHA1FILE = mzm_cn.sha1
# 	GAME_TITLE = ZEROMISSIONC
# 	GAME_CODE = BMXC
# 	CPPFLAGS += -DREGION_CN
# endif

ifeq ($(DEBUG),1)
	CPPFLAGS += -DDEBUG
endif

ELF = $(TARGET:.gba=.elf)
MAP = $(TARGET:.gba=.map)
DUMPS = $(BASEROM:.gba=.dump) $(TARGET:.gba=.dump)
LD_SCRIPT = linker.ld.pp

# ROM header
MAKER_CODE = 01
GAME_REVISION = 00

# Binaries
CPP = cpp
TOOLCHAIN ?= arm-none-eabi-
AS = $(TOOLCHAIN)as
LD = $(TOOLCHAIN)ld
OBJCOPY = $(TOOLCHAIN)objcopy
OBJDUMP = $(TOOLCHAIN)objdump

CC = agbcc

DIFF = diff -u
HOSTCC = cc
MKDIR = mkdir -p
RM = rm -f
SHA1SUM = sha1sum
TAIL = tail

# Tools
GBAFIX = tools/gbafix/gbafix
PYTHON = python3
EXTRACTOR = tools/extractor.py
PREPROC = tools/preproc/preproc

# Flags
ASFLAGS = -mcpu=arm7tdmi
CFLAGS = -Werror -O2 -mthumb-interwork -fhex-asm -f2003-patch
CPPFLAGS += -nostdinc -Iinclude/
PREPROCFLAGS = charmap.txt

# Objects
CSRC = $(wildcard src/**.c) $(wildcard src/**/**.c) $(wildcard src/**/**/**.c) $(wildcard src/**/**/**/**.c)
.PRECIOUS: $(CSRC:.c=.s)
ASMSRC = $(CSRC:.c=.s) $(wildcard asm/*.s) $(wildcard audio/*.s) $(wildcard audio/**/*.s) $(wildcard audio/**/**/*.s)
OBJ = $(ASMSRC:.s=.o) 

# Enable verbose output
ifeq ($(V),1)
	Q =
	MSG = @:
else
	Q = @
	MSG = @echo " "
endif

.PHONY: all
all: $(TARGET)

.PHONY: check
check: all
	$(MSG) SHA1SUM $(SHA1FILE)
	$Q$(SHA1SUM) -c $(SHA1FILE)

.PHONY: dump
dump: $(DUMPS)

.PHONY: diff
diff: $(DUMPS)
	$(MSG) DIFF $^
	$Q$(DIFF) $^

.PHONY: clean
clean:
	$(MSG) RM $(TARGET)
	$Q$(RM) $(TARGET) $(ELF) $(MAP)
	$(MSG) RM \*.dump
	$Q$(RM) $(DUMPS)
	$(MSG) RM \*.o
	$Q$(RM) $(OBJ)
	$(MSG) RM data/*.s
	$Q$(RM) $(DATA)
	$(MSG) RM src/\*\*/\*.s
	$Q$(RM) $(CSRC:.c=.s)
	$(MSG) RM $(GBAFIX)
	$Q$(RM) $(GBAFIX)
	$(MSG) RM data/
	$Q$(RM) -r data
	$(MSG) RM linker.ld.pp
	$Q$(RM) linker.ld.pp

.PHONY: help
help:
	@echo 'Targets:'
	@echo '  all: build the ROM'
	@echo '  check: checksum the ROM'
	@echo '  dump: dump the ROMs'
	@echo '  diff: compare the ROM with the original'
	@echo '  clean: remove the ROM and intermediate files'
	@echo '  help: show this message'
	@echo ''
	@echo 'Flags:'
	@echo '  V=1: enable verbose output'

$(TARGET): $(ELF) $(GBAFIX)
	$(MSG) OBJCOPY $@
	$Q$(OBJCOPY) -O binary --gap-fill 0xff --pad-to 0x08800000 $< $@
	$(MSG) GBAFIX $@
	$Q$(GBAFIX) $@ -t$(GAME_TITLE) -c$(GAME_CODE) -m$(MAKER_CODE) -r$(GAME_REVISION)

$(ELF) $(MAP): $(OBJ) $(LD_SCRIPT)
	$(MSG) LD $@
	$Q$(LD) $(LDFLAGS) -n -T $(LD_SCRIPT) -Map=$(MAP) -o $@

$(LD_SCRIPT): linker.ld
	$(MSG) CPP $@
	$Q$(CPP) $(CPPFLAGS) $< -o $@

%.dump: %.gba
	$(MSG) OBJDUMP $@
	$Q$(OBJDUMP) -D -bbinary -marm7tdmi -Mforce-thumb  $< | $(TAIL) -n+3 >$@
#--stop-address 0x8c71c
%.o: %.s
	$(MSG) AS $@
	$Q$(AS) $(ASFLAGS) $< -o $@

%.s: %.c
	$(MSG) CC $@
	$Q$(PREPROC) $< $(PREPROCFLAGS) | $(CPP) $(CPPFLAGS) | $(CC) -o $@ $(CFLAGS) && printf '\t.align 2, 0 @ dont insert nops\n' >> $@

src/sram/%.s: CFLAGS = -O1 -mthumb-interwork -fhex-asm
src/sram/%.s: src/sram/%.c

src/libgcc/%.s: CFLAGS = -O2 -fhex-asm
src/libgcc/%.s: src/libgcc/%.c

src/sprites_AI/%.s: CFLAGS = -O2 -mthumb-interwork -fhex-asm
src/sprites_AI/%.s: src/sram/%.c

tools/%: tools/%.c
	$(MSG) HOSTCC $@
	$Q$(HOSTCC) $< $(HOSTCFLAGS) $(HOSTCPPFLAGS) -o $@

.PHONY: us us_debug
# us_beta eu eu_debug jp jp_debug cn cn_debug

us:
	$(MAKE) REGION=us
us_debug:
	$(MAKE) REGION=us DEBUG=1
# us_beta:
# 	$(MAKE) REGION=us_beta DEBUG=1

# eu:
# 	$(MAKE) REGION=eu
# eu_debug:
# 	$(MAKE) REGION=eu DEBUG=1

# jp:
# 	$(MAKE) REGION=jp
# jp_debug:
# 	$(MAKE) REGION=jp DEBUG=1

# cn:
# 	$(MAKE) REGION=cn
# cn_debug:
# 	$(MAKE) REGION=cn DEBUG=1
