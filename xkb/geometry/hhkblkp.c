// HHKB Lite + KP -*-c-*-

default xkb_geometry "hhkblkp" {

  # include "hhkb.h"

  description	= "HHKB Lite + KP";
  text "brand" { left=18; top=2; fontSize=18; text="PFU"; };
  text "label" { left=251; top=91; fontSize=15; text="Happy Hacking\n Keyboard Lite"; };
  
  # include "kp.h"
  # include "hhkbl.h"

}; // R.Jaksa 2023
