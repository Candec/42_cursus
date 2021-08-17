#!/bin/bash

VB_Name='Devian_Test'
VB_OS='Debian_64'
VB_StoragePath="/goinfre/$USER/VB_Name.vdi"
VB_ISOPath="/goinfre/$USER/debian-10.9.0-amd64-netinst.iso"

# Creates the VirtualBox and expects an OS. Different OS can be selected using the command 
# 	$ VBoxManage ostype
VBoxManage createvm --name $VB_Name --ostype $VB_OS --register

# Sets the main characteristics of the VB [CPUS, Memory, VRAM and Storage capacity]
# It can never be greater than the computer it is hosting the VB
VBoxManage modifyvm $VB_Name --cpus 1 --memory 5120 --vram 16
VBoxManage createhd --filename $VB_StoragePath --size 5120

# Sets up a Dynamic Space Unit, rather than a fixed one
--variant Standard

# Makes the VB boot from the SATA
VBoxManage storagectl $VB_Name --name "SATA Controller" --add sata --bootable on

# Gives control of the SATA to the VB
VBoxManage storageattach $VB_Name --storagectl "SATA Controller" --port 0 --device 0 --type hdd --medium $VB_StoragePath

# Adds a virtual CD/DVD drive so it can read the ISO with the OS
VBoxManage storagectl $VB_Name --name "IDE Controller" --add ide

# Mounts the ISO into the virtual CD/DVD drive
VBoxManage storageattach $VB_Name --storagectl "IDE Controller" --port 0 --device 0 --type dvddrive --medium $VB_ISOPath

# Displays the info of the VB
VBoxManage showvminfo $VB_Name