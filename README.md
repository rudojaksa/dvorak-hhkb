# Xkb setup for Dvorak HHKB + KP

[X keyboard extension](https://en.wikipedia.org/wiki/X_keyboard_extension "Xkb") /
[Happy Hacking KeyBoard](https://en.wikipedia.org/wiki/Happy_Hacking_Keyboard "HHKB") /
[Dvorak keyboard layout](https://en.wikipedia.org/wiki/Dvorak_keyboard_layout "Dvorak") /
[numeric KeyPad](https://en.wikipedia.org/wiki/Numeric_keypad "KP")

<p>
<a href=doc/hhkbp2kp.png>
<img src=doc/hhkbp2kp.png>
</a>
</p>

Similar to: `setxkbmap -rules evdev -layout dvorak -option altwin:meta_win -model hhk`

 * with a custom Alt/Meta setup
 * with a custom Central-Europe ISO-Level3 extensions (or optionaly without)
 * minimal setup, without any code for other keyboards or layouts

This setup is for 001001 DIP switch setup (HHKB Professional 2) - default with just the backspace activated.

Contains:

 * Xkb setup `/usr/share/X11/xkb/{keycodes,symbols,geometry,rules,...}/{hhkbkp,hhkbp2kp,...}`
 * Xorg config `/usr/share/X11/xorg.conf.d/90-xkbrj.conf`
 * corresponding console keyboard config `/etc/default/keyboard`

### Reasoning

 * Xkb intsead of xmodmap: xmodmap is limited to the current running session, so it requires re-run after every keyboard reconnection, like after every [KVM switch](https://en.wikipedia.org/wiki/KVM_switch) event.
 * Dvorak instead of qwerty: another layout is like a foreign language for fingers.
 * HHKB <!--(Apple M0110)--> instead of big keyboard, with arrow keys under the hand.

### Installation

Xkb keyboard setup requires access to system-wide places `/usr/share/X11` and
`/etc/default/keyboard`, thus the real user-only configuration (homedir based)
is not possible.

 1. Run the `sudo make install` to copy supplied configuration files to required directories:  
    `/usr/share/X11/xkb`  
    `/usr/share/X11/xorg.conf.d`  
    `/etc/default/keyboard`  
 2. Manually add `setxkbmap -rules hhkb-dvorak` to your `.xinitrc` or session startup script, if needed.
 3. Call `setxkbmap -rules dvorak-hhkb` or reboot the computer to activate the setup.

### Hacking

Changes to the configuration can make your keyboard not working, you will need
a remote acces to fix it back!  
Some debug commands:

```
xkbcomp $DISPLAY -
setxkbmap -print -verbose 10
cat /usr/share/X11/xkb/keycodes/evdev | grep = # keycodes numbers
xev -event keyboard
```

```
setxkbmap -print | xkbcomp -w 4 -xkm - - | xkbprint -ll 1 -fit -color - /tmp/kbd.ps; gv -swap -scale=2 /tmp/kbd.ps &
setxkbmap -print -rules dvorak-hhkb | xkbcomp -xkm - - | xkbprint -color - /tmp/kbd.ps; gv -swap -scale=3 /tmp/kbd.ps &
```

### Links

Documentation:  
&nbsp;&nbsp; https://www.x.org/releases/X11R7.7/doc/kbproto/xkbproto.html  
&nbsp;&nbsp; https://github.com/xkbcommon/libxkbcommon/blob/master/doc/keymap-format-text-v1.md  
&nbsp;&nbsp; https://wiki.archlinux.org/title/X_keyboard_extension  
&nbsp;&nbsp; https://github.com/barsv/ivan-pascal-xkb  
&nbsp;&nbsp; https://hhkb.io/layout  
Code:  
&nbsp;&nbsp; https://github.com/xkbcommon/libxkbcommon  
&nbsp;&nbsp; https://gitlab.freedesktop.org/xkeyboard-config/xkeyboard-config  
&nbsp;&nbsp; https://gitlab.freedesktop.org/xorg/app/xkbcomp  
&nbsp;&nbsp; https://gitlab.freedesktop.org/xorg/app/xkbprint  
&nbsp;&nbsp; https://gitlab.freedesktop.org/xorg/app/xkbutils  

<br><div align=right><i>R.Jaksa 2023</i></div>
