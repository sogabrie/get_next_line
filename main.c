#include "get_next_line.h"

int	main()
{
	int b = open("a2.txt", O_RDONLY);
	char *a = get_next_line(b);
	//if (a)
		printf("get_next == %s\n", a);
	a = get_next_line(b);
    if (a)
		printf("get_next == %s\n", a);
	//close(b);
	a = get_next_line(b);
	if (a)
    	printf("get_next == %s\n", a);
	a = get_next_line(b);
	if (a)
    	printf("get_next == %s\n", a);
	a = get_next_line(b);
    if (a)
		printf("get_next == %s\n", a);
	return (0);
}
