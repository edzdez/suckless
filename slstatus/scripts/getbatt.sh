#!/bin/bash

cap=$(/bin/cat /sys/class/power_supply/BAT1/capacity)

if [ "$cap" -ge 90 ]; then
    echo " $cap"
elif [ "$cap" -ge 75 ]; then
    echo " $cap"
elif [ "$cap" -ge 50 ]; then
    echo " $cap"
elif [ "$cap" -ge 25 ]; then
    echo " $cap"
elif [ "$cap" -ge 0  ]; then
    echo " $cap"
fi
