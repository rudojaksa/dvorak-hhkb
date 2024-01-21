// plain Dvorak for HHKB, main block

key.type = "TWO_LEVEL";

key <ESC>  { [Escape], type= "ONE_LEVEL" };
key <AE01> { [1,exclam] };
key <AE02> { [2,at] };
key <AE03> { [3,numbersign] };
key <AE04> { [4,dollar] };
key <AE05> { [5,percent] };
key <AE06> { [6,asciicircum] };
key <AE07> { [7,ampersand ] };
key <AE08> { [8,asterisk ] };
key <AE09> { [9,parenleft] };
key <AE10> { [0,parenright] };
key <AE11> { [bracketleft,braceleft] };
key <AE12> { [bracketright,braceright] };
key <BKSL> { [backslash,bar] };
key <TLDE> { [grave,asciitilde] };

key <TAB>  { [Tab], type= "ONE_LEVEL" };
key <AD01> { [apostrophe,quotedbl] };
key <AD02> { [comma,less]};
key <AD03> { [period,greater]};
key <AD04> { [p,P] };
key <AD05> { [y,Y]};
key <AD06> { [f,F] };
key <AD07> { [g,G] };
key <AD08> { [c,C] };
key <AD09> { [r,R] };
key <AD10> { [l,L] };
key <AD11> { [slash,question] };
key <AD12> { [equal,plus] };
key <BKSP> { [BackSpace,BackSpace] };

key <LCTL> { [Control_L], type= "ONE_LEVEL" };
key <AC01> { [a,A] };
key <AC02> { [o,O] };
key <AC03> { [e,E] };
key <AC04> { [u,U] };
key <AC05> { [i,I] };
key <AC06> { [d,D] };
key <AC07> { [h,H] };
key <AC08> { [t,T] };
key <AC09> { [n,N] };
key <AC10> { [s,S] };
key <AC11> { [minus,underscore] };
key <RTRN> { [Return], type= "ONE_LEVEL" };

key <LFSH> { [Shift_L], type= "ONE_LEVEL" };
key <AB01> { [semicolon,colon] };
key <AB02> { [q,Q] };
key <AB03> { [j,J] };
key <AB04> { [k,K] };
key <AB05> { [x,X] };
key <AB06> { [b,B] };
key <AB07> { [m,M] };
key <AB08> { [w,W] };
key <AB09> { [v,V] };
key <AB10> { [z,Z] };
key <RTSH> { [Shift_R], type= "ONE_LEVEL" };

key.type = "ONE_LEVEL";

key <LALT> { [Alt_L] };  //  64/64
key <MUHE> { [Meta_L] }; // 102/102
key <LWIN> { [Meta_L] }; // 133/133
key <SPCE> { [space] };
key <HENK> { [Alt_R] };  // 100/136
key <RWIN> { [Alt_R] };  // 134/134
key <RALT> { [Meta_R] }; // 108/108

/// R.Jaksa 2023
