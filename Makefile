CC = cc
#CFLAGS = -L. -lftprintf -o 

all: a

a: *.c Makefile get_next_line.h
	#$(CC) -fsanitize=address -g *.c -o a 
	$(CC) main.c get_next_line.c get_next_line_utils.c -o a

clean:
	rm -rf  a 
