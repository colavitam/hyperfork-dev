#ifndef COMM_H
#define COMM_H

#define FORK 0x10
#define DONE 0x20

int init_comm(void);
void send_comm(unsigned char);

int comm_fork();
int comm_done();

#endif
