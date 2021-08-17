#include <stdio.h>
#include<conio.h>
int main() {
	/*
	tìm các s? có 2 ch? s? 

	*/
	for (int i = 10; i < 100; i++)
	{
		int hangchuc = i / 10;
		int hangdonvi = i % 10;
		if (hangchuc * hangdonvi == 2*(hangchuc + hangdonvi))
		{
			printf("\n %4d",i);
		}
	}
	return 0;
}