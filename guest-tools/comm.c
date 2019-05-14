#include <sys/io.h>
#include <stdio.h>
#include "comm.h"

#define PORT 0x1234

int init_comm(void) {
  return ioperm(PORT, 8, 1);
}

void send_comm(unsigned char msg) {
  outb(msg, PORT);
}

