#!/bin/bash

# SINK=$( pactl list short sinks | sed -e 's,^\([0-9][0-9]*\)[^0-9].*,\1,' | head -n 1 )
SINK=3
NOW=$( pactl list sinks | grep '^[[:space:]]Volume:' | head -n $(( $SINK + 1 )) | tail -n 1 | sed -e 's,.* \([0-9][0-9]*\)%.*,\1,' )

if [ "$(pamixer --get-mute)" = "true" ]; then
    echo "ﱝ $NOW% "	
elif [ "$NOW" -ge 60 ]; then
   echo " $NOW% "
elif [ "$NOW" -ge 40 ]; then
   echo " $NOW% "
elif [ "$NOW" -ge 0 ]; then
   echo " $NOW% "	
fi
