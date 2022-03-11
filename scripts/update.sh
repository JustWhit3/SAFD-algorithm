#!/bin/bash

#====================================================
#     UPDATING THE REPOSITORY
#====================================================
echo ""
echo "Updating the repository..."
echo ""

#Deleting old files and downloading the new repo:
cd ..
rm -rf SAFD-algorithm*

#Downloading new ones:
wget https://github.com/JustWhit3/SAFD-algorithm/archive/main.zip
mv main.zip SAFD-algorithm-main.zip
unzip SAFD-algorithm-main.zip
rm SAFD-algorithm-main.zip
mv SAFD-algorithm-main SAFD-algorithm
echo ""
echo "Repository is up-to-date!"
echo ""
echo "Enter the following commands:"
echo "1. cd .."
echo "2. cd SAFD-algorithm"
echo ""