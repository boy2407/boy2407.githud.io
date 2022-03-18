#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int *a = (int *)malloc(5 * sizeof(int));

	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;

	realloc(a, 4 * sizeof(int));

	for(int i = 0; i < 5; i++)
	{
		printf("%4d", a[i]);
	}



	free(a);


	getch();
	return 0;
}