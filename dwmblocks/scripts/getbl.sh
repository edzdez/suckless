#!/bin/bash

resdirt=$(brightnessctl | grep % | awk '{print $NF}')
resnotint=$(echo $resdirt | tr --delete % | tr --delete \( | tr -- delete \))

echo " $resnotint%" | tr --delete \)
