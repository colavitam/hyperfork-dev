#include <sys/io.h>
#include <stdio.h>
#include "comm.h"

#define DONE 0x20

int main(int argc, char **argv) {
  return comm_done();
}
