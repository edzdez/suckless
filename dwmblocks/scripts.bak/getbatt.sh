#!/bin/bash

cap=$(/bin/cat /sys/class/power_supply/BAT1/capacity)

if [ "$(/bin/cat /sys/class/power_supply/BAT1/status)" = "Charging" ]; then
    echo "⚡ $cap%"
else
    if [ "$cap" -ge 90 ]; then
        echo " $cap%"
    elif [ "$cap" -ge 75 ]; then
        echo " $cap%"
    elif [ "$cap" -ge 50 ]; then
        echo " $cap%"
    elif [ "$cap" -ge 25 ]; then
        echo "^c#ebcb8b^ $cap%^d^"
    elif [ "$cap" -ge 0  ]; then
        echo "^c#d08770^ $cap%^d^"
    fi
fi
