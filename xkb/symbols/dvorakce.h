// CE extended Dvorak for HHKB, main block

key.type = "FOUR_LEVEL";

key <ESC>  { [Escape], type="ONE_LEVEL" };
key <AE01> { [1,exclam,onesuperior] };
key <AE02> { [2,at,twosuperior,onehalf] };
key <AE03> { [3,numbersign,threesuperior,onethird] };
key <AE04> { [4,dollar,foursuperior,EuroSign] };
key <AE05> { [5,percent,fivesuperior,U2030] };
key <AE06> { [6,asciicircum,sixsuperior] };
key <AE07> { [7,ampersand,sevensuperior] };
key <AE08> { [8,asterisk,eightsuperior,infinity] };
key <AE09> { [9,parenleft,ninesuperior] };
key <AE10> { [0,parenright,zerosuperior,degree] };
key <AE11> { [bracketleft,braceleft] };
key <AE12> { [bracketright,braceright] };
key <BKSL> { [backslash,bar] };
key <TLDE> { [grave,asciitilde,dead_grave,dead_tilde], type="FOUR_LEVEL" };

key <TAB>  { [Tab], type="ONE_LEVEL" };
key <AD01> { [apostrophe,quotedbl,dead_acute,dead_doubleacute] };
key <AD02> { [comma,less,dead_caron,dead_abovering] };
key <AD03> { [period,greater,dead_circumflex,dead_macron] };
key <AD04> { [p,P,Greek_pi] };
key <AD05> { [y,Y,yacute,Yacute]};
key <AD06> { [f,F], type="TWO_LEVEL" };
key <AD07> { [g,G], type="TWO_LEVEL" };
key <AD08> { [c,C,ccaron,Ccaron] };
key <AD09> { [r,R,rcaron,Rcaron] };
key <AD10> { [l,L,lcaron,Lcaron] };
key <AD11> { [slash,question,ellipsis] };
key <AD12> { [equal,plus,notequal,plusminus] };
key <BKSP> { [BackSpace], type="ONE_LEVEL" };

key <LCTL> { [Control_L], type="ONE_LEVEL" };
key <AC01> { [a,A,aacute,Aacute] };
key <AC02> { [o,O,oacute,Oacute] };
key <AC03> { [e,E,eacute,Eacute] };
key <AC04> { [u,U,uacute,Uacute] };
key <AC05> { [i,I,iacute,Iacute] };
key <AC06> { [d,D,dcaron,Dcaron] };
key <AC07> { [h,H], type="TWO_LEVEL" };
key <AC08> { [t,T,tcaron,Tcaron] };
key <AC09> { [n,N,ncaron,Ncaron] };
key <AC10> { [s,S,scaron,Scaron] };
key <AC11> { [minus,underscore,endash,emdash] };
key <RTRN> { [Return], type="ONE_LEVEL" };

key <LFSH> { [Shift_L], type="ONE_LEVEL" };
key <AB01> { [semicolon,colon,dead_diaeresis,dead_abovedot] };
key <AB02> { [q,Q], type="TWO_LEVEL" };
key <AB03> { [j,J], type="TWO_LEVEL" };
key <AB04> { [k,K], type="TWO_LEVEL" };
key <AB05> { [x,X,multiply,U22C5] };
key <AB06> { [b,B,enfilledcircbullet,U25E6] };
key <AB07> { [m,M,mu] };
key <AB08> { [w,W], type="TWO_LEVEL" };
key <AB09> { [v,V], type="TWO_LEVEL" };
key <AB10> { [z,Z,zcaron,Zcaron] };
key <RTSH> { [Shift_R], type="ONE_LEVEL" };

key.type = "ONE_LEVEL";

key <LALT> { [Alt_L] };  //  64/64
key <MUHE> { [Meta_L] }; // 102/102
key <LWIN> { [Meta_L] }; // 133/133
key <SPCE> { [space,space,nobreakspace,nobreakspace], type="FOUR_LEVEL" };
key <HENK> { [Alt_R] };  // 100/136
key <RWIN> { [Alt_R] };  // 134/134
key <RALT> { [ISO_Level3_Shift] }; // 108/108

/// R.Jaksa 2023
