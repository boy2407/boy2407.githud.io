#include<stdio.h>
#include<conio.h>
#include<string.h>

void ThemKyThuVaoChuoi(char* s, char phantu, int vitri)
{
	int length = strlen(s);

	for (int i = length - 1; i >=vitri; i--)
	{
		s[i + 1] = s[i];
	}
	s[vitri] = phantu;
	s[length + 1] = '\0';
}
char * Cong(char* s1, char* s2)
{
	int length_s1 = strlen(s1);
	int length_s2 = strlen(s2);

	int Min = length_s1 < length_s2 ? length_s1 : length_s2;
	int Max = length_s1 > length_s2 ? length_s1 : length_s2;

	if (Min == length_s1) // s1 cần thêm 0 vào đầu cho đủ
	{
		for (int i = 1; i <= Max - Min; i++)
		{
			ThemKyThuVaoChuoi(s1, '0', 0);
		}
	}
	else if (Min == length_s2) // s2 cần thêm 0 vào đầu cho đủ
	{
		for (int i = 1; i <= Max - Min; i++)
		{
			ThemKyThuVaoChuoi(s2, '0', 0);
		}
	}
	/*Buoc2*/
	char ketqua[100];
	int idx = 0;
	int nho = 0;
	for (int i = Max - 1; i >= 0; i--)
	{
		int so = ((s1[i] - 48) + (s2[i] - 48)) + nho;
		nho = so / 10;//16 nho 1
		so %= 10;//16 lay 6
		ketqua[idx++] = so + 48;
	}
	if (nho != 0)
	{
		ketqua[idx++] = nho + 48;

	}
	ketqua[idx] = '\0';

	_strrev(ketqua);
}
int main()
{

	/*char s1[100] = "99999";
	char s2[100] = "00001";

	char* ketqua;
	ketqua = Cong(s1, s2);
	printf("\nketqua = %s", ketqua);*/
	int a = 450;
	char b[] = "1";
	 b-48;
	printf("%d  %s  %d", a, b);
	return 0;
}