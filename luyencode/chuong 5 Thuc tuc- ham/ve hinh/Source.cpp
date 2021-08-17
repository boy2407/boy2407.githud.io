#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<iostream>
#include<iomanip>
using namespace std;
void vevien(int a, int b);
void ve(int a, int b);
void ve(int a,int b)
{
	for (int i = 1; i <= a; i++)
	{
		
		for (int j = 1; j <= b; ++j)
		{
			Sleep(1000);
			printf(" *");
		}
		printf("\n");
	}
}
void vetamgiacrong(int canh)
{
	int x = 30;
	;
	for (int i=1 ; i <= canh; i++)
	{
		Sleep(500);
			cout << setw(x - i) << "*";
		if (i != 1  && i != canh)
		{
			Sleep(500);
			cout << setw(i*2-2) << "*";
								
		}
		else if(i==canh)
		{
			for (int j = 1; j <= i*2-2; j++)
			{
				Sleep(200);
				cout  << "*";
			}
		}	 
		cout << endl;
	}
}

void vevien(int a, int b)
{
	for (int i = 1; i <= a; i++)
	{
		if (i == 1 || i == a)
		{
			for (int j = 1; j <= b; ++j)
			{
				printf(" * ");
			}
		}
		else
		{
			for (int j = 1; j <= b; ++j)
			{
				if (j == 1 || j == b)
				{
					printf(" * ");
				}
				else
				{
					printf("   ");
				}
				
			}
		}
		
		printf("\n");
	}
}
int main()
{
	vetamgiacrong(4);
}