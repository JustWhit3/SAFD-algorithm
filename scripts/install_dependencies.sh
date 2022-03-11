#!/bin/bash

echo "Installing dependencies..."
sudo apt install build-essential g++ wget unzip
echo ""
echo "Installing arsenalgear and osmanip library..."
wget https://github.com/JustWhit3/osmanip/archive/main.zip
mv main.zip osmanip-main.zip
unzip osmanip-main.zip
cd osmanip-main || exit
./scripts/install.sh
cd ..
rm -rf osmanip-*
