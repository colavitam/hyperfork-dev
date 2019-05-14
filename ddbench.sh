#!/bin/busybox sh

# Simple dd RAM benchmark:
# write some memory (using tmpfs), signal to host to fork,
# and then write over it again

SOURCE=/dev/urandom
FILE=/dev/shm/ddbench.bin
BS=1M
COUNT=1000

dd if=/dev/urandom of=$FILE bs=$BS count=$COUNT
/bin/fork
dd if=/dev/urandom of=$FILE bs=$BS count=$COUNT
/bin/done
rm $FILE
