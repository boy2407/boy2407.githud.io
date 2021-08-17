#include<stdio.h>
#include<conio.h>
int Laychuso(int n, int vitrilay);
int Laychuso(int n, int vitrilay)
{
	int dem = 0;
	while (n!=0)
	{
		int chuso = n % 10;
		n /= 10;
		dem++;
		if (dem == vitrilay)
		{
			return chuso;
		}
	}
	return -1;
}
int main()
{
 int solayduoc =	Laychuso(12345, 2);
 printf("\n%d", solayduoc);
} 