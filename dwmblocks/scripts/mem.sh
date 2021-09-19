#!/bin/sh

usage=$(free -h | grep Mem | awk '{print $3}')

echo "$usage "
