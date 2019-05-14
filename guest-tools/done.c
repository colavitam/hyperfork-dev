#include <sys/io.h>
#include <stdio.h>
#include "comm.h"

#define DONE 0x20

int main(int argc, char **argv) {
  int r;

  r = init_comm();
  if (r != 0)
    return 1;

  send_comm(DONE);

  return 0;
}

