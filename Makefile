PACKAGE	:= dvorak-hhkb
VERSION	:= 0.1
AUTHORS	:= R.Jaksa 2023 GPLv3

XKB0	:= $(shell find xkb -type f -o -type l | grep -v -F .bkp)
XKB	:= $(XKB0:%=/usr/share/X11/%)

CFG0	:= $(shell find xorg.conf.d -type f | grep -v -F .bkp)
CFG	:= $(CFG0:%=/usr/share/X11/%)

ETC0	:= $(shell find etc -type f | grep -v -F .bkp)
ETC	:= $(ETC0:%=/%)

all: doc/hhkbp2kp.png

# requires manual install first
doc/hhkbp2kp.png: xkb/geometry/hhkbp2kp Makefile
	setxkbmap -print -rules dvorak-hhkb -geometry hhkbp2kp | xkbcomp -w 4 -xkm - - | xkbprint -ll 1 -fit -color - $@.ps
	gs -r220 -q -sDEVICE=pnggray -dNOPAUSE -dBATCH -dDEVICEWIDTHPOINTS=1600 -dDEVICEHEIGHTPOINTS=600 -sOutputFile=$@.png $@.ps
	convert $@.png -resize 2400 $@.2.png
	pngquant -f --strip -Q 50 -o $@.3.png $@.2.png
	zopflipng -y -m --lossy_8bit $@.3.png $@ 2>&1 >/dev/null
	rm -f $@.*.png
	rm -f $@.png $@.ps

info:
	@echo $(XKB) $(CFG) $(ETC) | xargs -n 1

install: install-xkb $(CFG) $(ETC)
	@echo ---------------------
	@l -b -nh $(XKB0) $(CFG0) $(ETC0)
	@echo ---------------------
	@l -b -nh -a $(XKB) $(CFG) $(ETC)

install-xkb: $(XKB)

$(XKB) $(CFG): /usr/share/X11/%: %
	install -D -m 644 $* $@

$(ETC): /%: %
	install -D -m 644 $* $@

include ~/.github/Makefile.git
