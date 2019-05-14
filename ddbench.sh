#!/bin/busybox sh

# Simple dd RAM benchmark:
# write some memory (using tmpfs) and then write over it again

FILE=/tmp/ddbench.bin
BS=1M
COUNT=1000

function signal_host {
    echo $1
}

dd if=/dev/urandom of=$FILE bs=$BS count=$COUNT
signal_host "allocated file"
dd if=/dev/urandom of=$FILE bs=$BS count=$COUNT
signal_host "done"
rm $FILE
