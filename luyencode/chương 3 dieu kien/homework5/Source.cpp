#include<stdio.h>
#include<conio.h>
int main() 
{
	float a, b, c;
	scanf_s("%d%d%d", &a, &b, &c);
	if(a+b<=c|| a+c<=b || b+c<=a)
	{
		getch();
		return 0;
	}


	getch();
	return 0;
}