#include "get_next_line.h"

int	main()
{
	//printf("qqqqqqqqq\n");
	int b = open("a1.txt", O_RDONLY);
	char *a = get_next_line(b);
	printf("eeeeeeeeeeeeee\n");
	if (a)
		printf("get_next1 == %s|\n", a);
		//free(a);
	a = get_next_line(b);
    if (a)
	{
		printf("get_next2 == %s|\n", a);
		//free(a);
	}
	a = get_next_line(b);
    if (a)
	{
		printf("get_next3 == %s|\n", a);
		//free(a);
	}
	a = get_next_line(b);
    if (a)
	{
		printf("get_next4 == %s|\n", a);
		//free(a);
	}
	a = get_next_line(b);
    if (a)
	{
		printf("get_next5 == %s|\n", a);
		//free(a);
	}
	a = get_next_line(b);
    if (a)
	{
		printf("get_next6 == %s|\n", a);
		//free(a);
	}
	a = get_next_line(b);
    if (a)
	{
		printf("get_next7 == %s\n", a);
		//free(a);
	}
	return (0);
}
