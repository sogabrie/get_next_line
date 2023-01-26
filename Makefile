CC = cc
#CFLAGS = -L. -lftprintf -o 

all: a 

a: *.o
	$(CC) *.o -o a 

*.o : *.c
	$(CC) -c *.c

clean:
	rm -rf  a
