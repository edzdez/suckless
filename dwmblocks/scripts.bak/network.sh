#!/bin/bash

conntype=$(ip route | awk '/default/ { print substr($5,1,1) }')

if [ -z "$conntype" ]; then
	echo "^c#ebcb8b^ down^d^"
elif [ "$conntype" = "e" ]; then
	echo " eth"
elif [ "$conntype" = "w" ]; then
    echo   "$(nmcli -t -f active,ssid dev wifi | grep yes | awk -F ':' '{print $2}')"
fi
