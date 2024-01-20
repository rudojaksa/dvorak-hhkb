// KP section

width = 417;

// outlines
shape "KP" { cornerRadius=2,  {[85,110]}};
solid "edges2" { top=-4; left=326; angle=1; shape="KP"; color="grey6"; };

section "KP" { top=6; left=325; angle=10;
  row { top=1;  keys { <NMLK>, <KPDV>, <KPMU>, <KPSU> };};
  row { top=20; keys { <KP7>, <KP8>, <KP9>, { <KPAD>,"KPAD" }};};
  row { top=39; keys { <KP4>, <KP5>, <KP6> };};
  row { top=58; keys { <KP1>, <KP2>, <KP3>, { <KPEN>,"KPAD" }};};
  row { top=77; keys {{ <KP0>, "KP0" }, <KPDL> };};};

shape "LED"  { cornerRadius=1, {[2,2]}};
indicator.shape    = "LED";
indicator.offColor = "grey2";
indicator.onColor  = "green60";
indicator "Num Lock" { top=3; left=337; };

/// R.Jaksa 2023
