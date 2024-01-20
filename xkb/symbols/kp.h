// Keypad block

key.type = "KEYPAD";

key <NMLK> { [Num_Lock], type="ONE_LEVEL" };
key <KPDV> { [KP_Divide], type="ONE_LEVEL" };
key <KPMU> { [KP_Multiply], type="ONE_LEVEL" };
key <KPSU> { [KP_Subtract], type="ONE_LEVEL" };

key <KP7>  { [KP_Home,KP_7] };
key <KP8>  { [KP_Up,KP_8] };
key <KP9>  { [KP_Prior,KP_9] };
key <KPAD> { [KP_Add], type="ONE_LEVEL" };

key <KP4>  { [KP_Left,KP_4] };
key <KP5>  { [KP_Begin,KP_5] };
key <KP6>  { [KP_Right,KP_6] };

key <KP1>  { [KP_End,KP_1] };
key <KP2>  { [KP_Down,KP_2] };
key <KP3>  { [KP_Next,KP_3] };
key <KPEN> { [KP_Enter], type="ONE_LEVEL" };

key <KP0>  { [KP_Insert,KP_0] };
key <KPDL> { [KP_Delete,KP_Decimal] };

modifier_map Mod2 { Num_Lock };

/// R.Jaksa 2023
