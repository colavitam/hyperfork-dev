CFLAGS=-O2
LDFLAGS=-static

all: fork done rambench

fork: fork.o comm.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

done: done.o comm.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

rambench: rambench.o comm.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o fork done rambench

.PHONY: clean
