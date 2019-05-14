/* rambench.c
 * Simple copy-on-write benchmark
 * Allocates a large chunck of memory, writes to every page, then hyperforks.
 * After forking, it again writes to each of those pages.
 */

#include <stdlib.h>
#include <sys/mman.h>
#include <assert.h>
#include "comm.h"

#define NPAGES 1000000
#define PGSIZE 4096
#define WRITE_SIZE 128

int main(int argc, char **argv)
{
	char *mem = mmap(NULL, (size_t) NPAGES * PGSIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	assert(mem > 0);

	for (unsigned i = 0; i < NPAGES; i++) {
		int *addr = (int *) (mem + i * PGSIZE);
		for (unsigned j = 0; j < WRITE_SIZE / sizeof(int); j++) {
			addr[j] = random();
		}
	}

	comm_fork();

	for (unsigned i = 0; i < NPAGES; i++) {
		int *addr = (int *) (mem + i * PGSIZE);
		for (unsigned j = 0; j < WRITE_SIZE / sizeof(int); j++) {
			addr[j] = random();
		}
	}

	comm_done();

	return 0;
}
