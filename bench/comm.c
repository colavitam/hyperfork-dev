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

int comm_fork(void) {
  int r;

  r = init_comm();
  if (r != 0)
    return 1;

  send_comm(FORK);

  return 0;
}

int comm_done(void) {
  int r;

  r = init_comm();
  if (r != 0)
    return 1;

  send_comm(DONE);

  return 0;
}
