#!/bin/bash

info=$(uname -ar)

echo $info | awk '{ print $3 " "}'
