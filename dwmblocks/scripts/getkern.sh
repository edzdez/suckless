#!/bin/bash

info=$(uname -ar)

echo $info | awk '{ print $2 "-" $3 " "}'
