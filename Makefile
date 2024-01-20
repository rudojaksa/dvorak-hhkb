PACKAGE	:= dvorak-hhkb
VERSION	:= 0.2
AUTHOR	:= R.Jaksa 2023 GPLv3
SUBVERS	:= 

CR_="\\033[31m"
CC_="\\033[36m"
CK_="\\033[90m"
CD_="\\033[0m"

# --------------------------------------------------------------------------------------------- CONFIG

# obtain the config string from the "config" file
CONFIG := $(shell cat config | sed 's:\#.*::' | xargs)

# identify the model = the target variant of HHKB
ifneq (,$(findstring Professional,$(CONFIG)))
  MODEL := hhkbp2
else ifneq (,$(findstring Lite,$(CONFIG)))
  MODEL := hhkbl
else # the default
  MODEL := hhkbp2
endif

# identify the range: hhkb vs hhkbkp
# and whether Keypad will be included to the model
ifneq (,$(findstring KP,$(CONFIG)))
  RANGE := hhkbkp
  MODEL := $(MODEL)kp
  DEVICEHEIGHTPOINTS := -dDEVICEHEIGHTPOINTS=600
else
  RANGE := hhkb
  DEVICEHEIGHTPOINTS := -dDEVICEHEIGHTPOINTS=820
endif

# identify the layout
ifneq (,$(findstring CE,$(CONFIG)))
  LAYOUT := dvorakce
else # the default
  LAYOUT := dvorak
endif

# -------------------------------------------------------------------------------------------- TARGETS

# xorg.conf target files (cfg0 are sources)
CFG0 := $(shell find xorg.conf.d -type f | grep -v -F .bkp)
CFG  := $(CFG0:%=/usr/share/X11/%)

# etc target files (etc0 are sources)
ETC0 := $(shell find etc -type f | grep -v -F .bkp)
ETC  := $(ETC0:%=/%)

# xkb files to copy = target files
XKB0 := $(shell find xkb/compat -type f -o -type l | grep -v -F .bkp)
XKB0 += $(shell find xkb/rules  -type f -o -type l | grep -v -F .bkp)
XKB0 += $(shell find xkb/types  -type f -o -type l | grep -v -F .bkp)
XKB0 += xkb/geometry/$(MODEL)
XKB0 += xkb/keycodes/$(MODEL)
XKB0 += xkb/symbols/$(LAYOUT)-$(RANGE)
XKB  := $(XKB0:%=/usr/share/X11/%)

# build dir
XKB1 := $(XKB0:%=build/%)
CFG1 := $(CFG0:%=build/%)
ETC1 := $(ETC0:%=build/%)

# xkb files to install as a direct copy (without compilation)
XKB2 := $(shell echo $(XKB) | xargs -n1 | grep -v keycodes | grep -v symbols | grep -v rules)

# ---------------------------------------------------------------------------------------------- BUILD

all: info $(XKB1) $(CFG1) $(ETC1) doc/hhkb.png

# verbose: the config and target xkb-files
info: infoc # build info
	@echo; echo $(XKB1) $(CFG1) $(ETC1) | xargs -n1 | xargs -iX echo -e "     $(CK_)X$(CD_)"; echo
infoi: infoc # install info
	@echo; echo $(XKB) $(CFG) $(ETC) | xargs -n1 | xargs -iX echo -e "     $(CK_)X$(CD_)"; echo
infoc: # config info
	@echo -e "$(CC_)cfg:$(CD_) \"$(CONFIG)\" => $(LAYOUT)-$(MODEL)"

build/xkb/keycodes build/xkb/symbols build/xkb/rules build/xkb/compat build/xkb/types build/xkb/geometry build/xorg.conf.d build/etc/default:
	@mkdir -p $@

# cpp can be used as well: cpp -nostdinc -C -P $< > $@
#     although, cpp resolves "// \" comment as a continuing line unfortunately
#     although, cpp -P as a side-effect removes all formatting incl. empty lines and all comments
build/xkb/keycodes/%: xkb/keycodes/%.c xkb/keycodes/*.h config Makefile | build/xkb/keycodes
	UTIL/pcpp $< > $@

build/xkb/symbols/%: xkb/symbols/%.c xkb/symbols/*.h config Makefile | build/xkb/symbols
	UTIL/pcpp $< > $@

build/xkb/geometry/%: xkb/geometry/%.c xkb/geometry/*.h config Makefile | build/xkb/geometry
	UTIL/pcpp $< > $@

build/xkb/rules/%: xkb/rules/% config Makefile | build/xkb/rules
	cat $< | sed 's:MODEL:$(MODEL):g' | sed 's:RANGE:$(RANGE):g' | sed 's:LAYOUT:$(LAYOUT):g' > $@

build/xorg.conf.d/%: xorg.conf.d/% config Makefile | build/xorg.conf.d
	cat $< | sed 's:MODEL:$(MODEL):g' | sed 's:RANGE:$(RANGE):g' | sed 's:LAYOUT:$(LAYOUT):g' > $@

build/etc/default/%: etc/default/% config Makefile | build/etc/default
	cat $< | sed 's:"MODEL":"$(MODEL)":g' | sed 's:"RANGE":"$(RANGE)":g' | sed 's:"LAYOUT":"$(LAYOUT)":g' > $@

build/xkb/compat/%: xkb/compat/% Makefile | build/xkb/compat
	cp $< $@

build/xkb/types/%: xkb/types/% Makefile | build/xkb/types
	cp $< $@

# note: figures will be correct only after xkb files are on place
doc/hhkb.png: $(XKB1) Makefile
	@sleep .3
	@printf "$(CK_)"
	setxkbmap -I build/xkb -print -rules dvorak-hhkb -geometry $(MODEL) | xkbcomp -Ibuild/xkb -w 4 -xkm - - | xkbprint -ll 1 -fit -color - $@.ps
	gs -r220 -q -sDEVICE=pnggray -dNOPAUSE -dBATCH -dDEVICEWIDTHPOINTS=1600 $(DEVICEHEIGHTPOINTS) -sOutputFile=$@.png $@.ps
	convert $@.png -resize 2400 $@.2.png
	pngquant -f --strip -Q 50 -o $@.3.png $@.2.png
	zopflipng -y -m --lossy_8bit $@.3.png $@ 2>&1 >/dev/null
#	mv $@.3.png $@
	rm -f $@.png $@.ps $@.*.png
#	feh $@

# -------------------------------------------------------------------------------------------- INSTALL

install: infoi $(XKB) $(CFG) $(ETC)

# commands prefix
prefix = $(shell if test -e $(1); then echo -n "$(CC_)upd:$(CD_)"; else echo -n "$(CR_)new:$(CD_)"; fi)

$(XKB) $(CFG): /usr/share/X11/%: build/%
	@printf "$(call prefix,$@) "
	install -D -m 644 $< $@

$(ETC): /%: build/%
	@printf "$(call prefix,$@) "
	install -D -m 644 $< $@

# only currently configured files are uninstalled by this
uninstall:
	@echo -e "$(CK_)rm -i $(XKB) $(CFG)$(CD_)"
	@-rm -i $(XKB) $(CFG)
	@echo -e "$(CR_)not removed:$(CD_) $(ETC)"

# ----------------------------------------------------------------------------------------------------

clean:
	rm -fr build

mrproper: clean
	rm doc/hhkb.png

include ~/.github/Makefile.git

# --------------------------------------------------------------------------------------- R.Jaksa 2023
