width           = 294;
height          = 110;
section.left    = 1;
row.left        = 3;
key.gap         = 1;
key.shape       = "NORM";
color           = "gray6";
key.color       = "grey2";
text.color      = "grey40";
shape.cornerRadius = 1;

// keys: outer_rectangle,shift,inner_rectangle
shape "NORM" {{[18,18]},{[2,1],[15,15]}};
shape "BKSP" {{[27,18]},{[2,1],[24,15]}};
shape "TAB"  {{[28,18]},{[2,1],[25,15]}};
shape "CTRL" {{[32,18]},{[2,1],[29,15]}};
shape "RTRN" {{[42,18]},{[2,1],[39,15]}};
shape "SPCE" {{[114,18]},{[2,1],[111,15]}};
shape "KPAD" {{[18,37]},{[2,1],[15,34]}};
shape "KP0"  {{[37,18]},{[2,1],[34,15]}};

// outlines
shape "KB" { cornerRadius=2, {[294,110]}};
solid "edges" { top=0; left=0; shape="KB"; color="grey6"; };

/// R.Jaksa 2023
