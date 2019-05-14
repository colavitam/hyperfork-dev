#include <sys/io.h>
#include <stdio.h>
#include "comm.h"

#define FORK 0x10

int main(int argc, char **argv) {
  int r;

  r = init_comm();
  if (r != 0)
    return 1;

  send_comm(FORK);

  return 0;
}
