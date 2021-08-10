#!/bin/bash

id
sudo -s <<EOF
echo Now i am root
id
echo "yes!"
sudo apt install sudo
dpkg -l | gerp sudo
EOF
