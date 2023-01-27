#include "get_next_line.h"

int	main()
{
	int b = open("a3", O_RDONLY);
	char *a = get_next_line(b);
	//if (a)
		printf("get_next1 == %s\n", a);
	a = get_next_line(b);
    if (a)
		printf("get_next2 == %s\n", a);
	//close(b);
	a = get_next_line(b);
	if (a)
    	printf("get_next3 == %s\n", a);
	a = get_next_line(b);
	if (a)
    	printf("get_next4 == %s\n", a);
	a = get_next_line(b);
    if (a)
		printf("get_next5 == %s\n", a);
	a = get_next_line(b);
	 if (a)
 	    printf("get_next6 == %s\n", a);
 	a = get_next_line(b);
    if (a)
       printf("get_next7 == %s\n", a);
	return (0);
}
