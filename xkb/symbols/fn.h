// Fn block

key.type = "ONE_LEVEL";

key <FK01> { [F1] };     // 1
key <FK02> { [F2] };     // 2
key <FK03> { [F3] };     // 3
key <FK04> { [F4] };     // 4
key <FK05> { [F5] };     // 5
key <FK06> { [F6] };     // 6
key <FK07> { [F7] };     // 7
key <FK08> { [F8] };     // 8
key <FK09> { [F9] };     // 9
key <FK10> { [F10] };    // 0
key <FK11> { [F11] };    // [
key <FK12> { [F12] };    // ]
key <INS>  { [Insert] }; // \
key <DELE> { [Delete] }; // `

key <PRSC> { [Print,Sys_Req], type="TWO_LEVEL" }; // c
key <SCLK> { [Scroll_Lock] };                     // r
key <PAUS> { [Pause,Break], type="TWO_LEVEL" };   // l
key <UP>   { [Up] };                              // /

key <HOME> { [Home] };   // t
key <PGUP> { [Prior] };  // n
key <LEFT> { [Left] };   // s
key <RGHT> { [Right] };  // -

key <END>  { [End] };    // w
key <PGDN> { [Next] };   // v
key <DOWN> { [Down] };   // z

key <STOP> { [Alt_R] };  // HENK (136) - HHKB Professional 2 only

/// R.Jaksa 2023
