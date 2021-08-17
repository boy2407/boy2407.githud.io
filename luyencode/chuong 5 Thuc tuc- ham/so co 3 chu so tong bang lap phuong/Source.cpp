#include<stdio.h>
#include<conio.h>
#include<math.h>
int KiemTraAmstrong(int n);

void LietKe(int end,int start) 
{
	for (int i = start; i < end; ++i)
	{
		
		if( KiemTraAmstrong(i)==1)
		{
			printf("4%d", i);
		}
	}
}
int KiemTraAmstrong(int n)
{
	int temp = n;
	int soluongchuso = log10((double)temp) + 1;
	int tong=0;
	while (n!=temp)
	{
		int chuso = temp % 10;
		temp /= 10;
		tong += pow((double)chuso, soluongchuso);
	}
	if (tong == n)
	{
		return 1;
	}
	return 0;
}
int main(){

}