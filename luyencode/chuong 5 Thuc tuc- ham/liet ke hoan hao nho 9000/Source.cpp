#include<stdio.h>
#include<conio.h>
int KiemtraHoanThien(int n)
{
	int sum = 0;
	for (int i = 1; i < n / 2; ++i)
	{
		if (n % i == 0)
		{
			sum += i;
		}
	}
	if (sum == n)
	{
		return 1;
	}
	return 0;
}
void LietKeHoanHao(int n)
{
	printf("\nCac so hoan hao nho hon %d", n);
	for (int i = 1; i < n; i++)
	{
		if (KiemtraHoanThien(i) == 1)
		{
			printf("4%d", i);
		}
	}
}
int main()
{

}