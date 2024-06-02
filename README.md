# Xkb setup for Dvorak HHKB + KP

[X keyboard extension](https://en.wikipedia.org/wiki/X_keyboard_extension "Xkb") /
[Happy Hacking KeyBoard](https://en.wikipedia.org/wiki/Happy_Hacking_Keyboard "HHKB") /
[Dvorak keyboard layout](https://en.wikipedia.org/wiki/Dvorak_keyboard_layout "Dvorak") /
[numeric KeyPad](https://en.wikipedia.org/wiki/Numeric_keypad "KP")

<p>
<a href=doc/hhkb.png>
<img src=doc/hhkb.png>
</a>
</p>

Similar to: `setxkbmap -rules evdev -layout dvorak -option altwin:meta_win -model hhk`, but:

 * with a custom Alt/Meta setup (commented and modifiable)
 * with custom Central-Europe ISO-Level3 extensions (install-option to disable them, modifiable too)
 * minimal final xkb setup code, without any code for other keyboards or layouts
 * commented output code with a simple structure, easy to further customize
 * output installed and assembled from a set of source files by a Makefile

HHKB Professional 2 (PD-KB400) DIP switch "001001" setup:
```
0 0 1 0 0 1
| | | | | +--> Wake Up enable
| | | +-+----> Alt-Muhenkan-Henenkan-Alt
| | +--------> Backspace (not Delete)
+-+----------> HHKB
```

HHKB Lite (KB9975) DIP switch "1000" setup:

```
  +-+-+-----> Alt-Muhenkan-Henenkan-Alt
1 0 0 0
1 1 0 0
| +-+-+-----> Alt-Windows-Windows-Alt + FnTab CapsLock
+-----------> Backspace (not Delete)
```

Original HHKB (PD-KB02) switch "3" setup:
```
position 3 -> Backspace Muhenkan
```

Output:

 * Xkb setup `/usr/share/X11/xkb/{keycodes,symbols,geometry,rules,...}/{hhkbkp,hhkbp2kp,...}`
 * Xorg config `/usr/share/X11/xorg.conf.d/90-xkbrj.conf`
 * corresponding console keyboard config `/etc/default/keyboard`

### Reasoning

 * Xkb instead of xmodmap: xmodmap is limited to the current running session, so it requires a re-run after every keyboard reconnection, for instance after every [KVM switch](https://en.wikipedia.org/wiki/KVM_switch) event.
 * Dvorak instead of qwerty: another layout is like a foreign language for fingers.
 * HHKB <!--(Apple M0110)--> instead of a big keyboard, with arrow keys under the hand.

### Installation

Xkb keyboard setup requires access to system-wide places `/usr/share/X11` and
`/etc/default/keyboard`, thus the real user-only configuration (homedir based)
is not possible.

 1. edit the `config` file to select the HHKB model and the keypad presence
 2. run `make` to create `build/xkb` files and a `doc/hhkb.png` visual 
 3. Run the `sudo make install` to copy the created configuration files to the required directories:  
    `/usr/share/X11/xkb` &larr; new files will be installed here  
    `/usr/share/X11/xorg.conf.d` &larr; new file will be installed here  
    `/etc/default/keyboard` &larr; this will be overwritten  
 4. Manually add `setxkbmap -rules dvorak-hhkb` to your `.xinitrc` or session startup script if needed.
 5. Reboot the computer to activate the setup, or call:

```
setxkbmap -rules dvorak-hhkb
```

### Hacking

Changes to the configuration **can make your keyboard not working,** you will
need remote access to fix it back!

The xkb configuration files are assembled in the `build` directory from sources
in the `xkb` directory by a simplified cpp preprocessor which handles include
directives and keeps comments.

To debug modifiers map:
``` sh
xkbcomp $DISPLAY - | grep modifier_map
xmodmap -pm
```

To debug rules:
``` sh
setxkbmap -print -verbose 10
```

To debug keycodes/symbols:
``` sh
xev -event keyboard
xinput --test-xi2
xkbcli interactive-x11
cat /usr/share/X11/xkb/keycodes/evdev | grep = # keycodes numbers
xmodmap -pke
xmodmap -pk
xkbcomp $DISPLAY -
```

To sample the current setup, edit it and apply it back:
``` sh
xkbcomp $DISPLAY output.xkb
edit output.xkb
xkbcomp output.xkb $DISPLAY
```

To check the geometry:
``` sh
setxkbmap -print | xkbcomp -w 4 -xkm - - | xkbprint -ll 1 -fit -color - /tmp/kbd.ps; gv -swap -scale=2 /tmp/kbd.ps &
setxkbmap -print -rules dvorak-hhkb | xkbcomp -xkm - - | xkbprint -color - /tmp/kbd.ps; gv -swap -scale=3 /tmp/kbd.ps &
```

To debug indicators:
``` sh
xkbvleds
xkbwatch
```

### Links

Documentation:  
&nbsp;&nbsp; https://www.x.org/releases/X11R7.7/doc/kbproto/xkbproto.html  
&nbsp;&nbsp; https://github.com/xkbcommon/libxkbcommon/blob/master/doc/keymap-format-text-v1.md  
&nbsp;&nbsp; https://wiki.archlinux.org/title/X_keyboard_extension  
&nbsp;&nbsp; https://github.com/barsv/ivan-pascal-xkb  
&nbsp;&nbsp; https://hhkb.io/layout  
Code:  
&nbsp;&nbsp; https://gitlab.freedesktop.org/xkeyboard-config/xkeyboard-config  
&nbsp;&nbsp; https://gitlab.freedesktop.org/xorg/app/setxkbmap  
&nbsp;&nbsp; https://gitlab.freedesktop.org/xorg/app/xkbcomp  
&nbsp;&nbsp; https://gitlab.freedesktop.org/xorg/app/xkbprint  
&nbsp;&nbsp; https://gitlab.freedesktop.org/xorg/app/xkbutils &larr; xkbvleds, xkbwatch  
&nbsp;&nbsp; https://gitlab.freedesktop.org/xorg/app/xev  
&nbsp;&nbsp; https://gitlab.freedesktop.org/xorg/app/xmodmap  
&nbsp;&nbsp; https://github.com/xkbcommon/libxkbcommon &larr; xkbcli  
&nbsp;&nbsp; https://salsa.debian.org/installer-team/console-setup &larr; ckbcomp  

<br><div align=right><i>R.Jaksa 2023,2024</i></div>
