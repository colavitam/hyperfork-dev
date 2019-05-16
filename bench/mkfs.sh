#!/bin/bash

mkdir mnt
sudo mount output/images/rootfs.ext4 mnt
sudo cp -r staging/* mnt/root
sudo cp staging/S50bench mnt/etc/init.d
sudo umount mnt
rmdir mnt
