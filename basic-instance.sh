#!/bin/bash

# From tutorial at `https://github.com/firecracker-microvm/firecracker/blob/master/docs/getting-started.md`

# First, start firecracker in another terminal with `./firecracker --api-sock /tmp/firecracker.socket`

KERNEL=./hello-vmlinux.bin
ROOTFS=./hello-rootfs.ext4

curl --unix-socket /tmp/firecracker.socket -i -X PUT 'http://localhost/boot-source' -H 'Accept: application/json' -H 'Content-Type: application/json' -d '{"kernel_image_path": \"$KERNEL\", "boot_args": "console=ttyS0 reboot=k panic=1 pci=off"}'

curl --unix-socket /tmp/firecracker.socket -i -X PUT 'http://localhost/drives/rootfs' -H 'Accept: application/json' -H 'Content-Type: application/json' -d '{"drive_id": "rootfs", "path_on_host": $ROOTFS, "is_root_device": true, "is_read_only": false}'

curl --unix-socket /tmp/firecracker.socket -i -X PUT 'http://localhost/actions' -H  'Accept: application/json' -H  'Content-Type: application/json' -d '{"action_type": "InstanceStart"}'
