/* rambench.c
 * Simple copy-on-write benchmark
 * Allocates a large chunck of memory, writes to every page, then hyperforks.
 * After forking, it again writes to each of those pages.
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include "comm.h"

#define PGSIZE 4096
#define WRITE_SIZE 128

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Usage: rambench size\nWhere `size` is the amount of memory to allocate in bytes.\n");
		exit(1);
	}

	unsigned long size = atol(argv[1]);

	char *mem = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (mem == (char *) -1) {
		printf("Error allocating memory\n");
		exit(1);
	}

	for (unsigned i = 0; i < size / PGSIZE; i++) {
		int *addr = (int *) (mem + i * PGSIZE);
		for (unsigned j = 0; j < WRITE_SIZE / sizeof(int) &&
			     addr + j < (int *) (mem + size); j++) {
			addr[j] = random();
		}
	}

	comm_fork();

	for (unsigned i = 0; i < size / PGSIZE; i++) {
		int *addr = (int *) (mem + i * PGSIZE);
		for (unsigned j = 0; j < WRITE_SIZE / sizeof(int) &&
			     addr + j < (int *) (mem + size); j++) {
			addr[j] = random();
		}
	}

	comm_done();

	return 0;
}
