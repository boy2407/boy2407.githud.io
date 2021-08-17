#include<stdio.h>
#include<conio.h>
#include<math.h>
int xuly(int n)
{
	if (n == 0)
	{
		return 1;
	}
	int dem = 0;
	while (n!=0)
	{
		n /= 10;
		dem++;
	}
	return dem;
}
int xulycach2(int n)// khong xu ly n<1
{


	if (n == 0)
	{
		return 1;
	}
	if (n < 0)
	{
		n *= -1;
	}
	return log10((double)n) + 1;
}
int main()
{

}