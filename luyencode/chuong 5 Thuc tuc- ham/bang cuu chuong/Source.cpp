#include<stdio.h>
#include<conio.h>

void LietKe(int x , int y)
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = x; j <= y; j++)
		{
			printf("%d  * %d = %2d |", j, i, i * j);
		}
		printf("\n");
	}
}
int main() 
{
	int x=7, y=3;
	LietKe(x, y);
	
	return 0;

}