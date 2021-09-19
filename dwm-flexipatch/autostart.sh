#!/bin/bash

function run {
 if ! pgrep $1 ;
  then
    $@&
  fi
}

run "nitrogen --restore"
run "picom --experimental-backends"
run "wmname LG3D"
#run "dunst"
#run "/usr/lib/xfce4/notifyd/xfce4-notifyd"
run "/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1"
#run slstatus
run "dwmblocks"
run "nm-applet --indicator"
run "/home/edzdez/.local/bin/pa-applet"
run "setxkbmap -option caps:escape"
