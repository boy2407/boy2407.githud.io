#include<stdio.h>
#include<conio.h>
#include <string>
char* BienChuoiThanhThuong(char* s)
{
	//tao ban sao
	char* p = strdup(s);

	//bien thanh thuong
	strlwr(p);
	return p;
}
char* BienChuoiThanhHoa(char* s)
{
	//tao ban sao
	char* p = strdup(s);

	//bien thanh thuong
	strupr(p);
	return p;
}
char* BienKyTuDauThanhHoa(char* s)
{
	char* p = strdup(s);
	/*tr??c ?ó là 1 kho?ng tr?ng và ??ng sau khác th?ng tr?ng
	*
	*/
	if (p[0] != '\0')
	{
		if (p[0] >= 'a' && p[0] <= 'z')
		{
			p[0] -= 32;
		}
	}

	for (int i = 0; i < strlen(p); i++)
	{
		if (p[i] == '\0' && p[i + 1] != '\0')
		{
			if (p[i + 1] >='a' && p[i + 1] <= 'z')
			{
				p[i + 1] -= 32;
			}
		}
	}
	return p;
}
void XoaKyTu(char* s, int vitrixoa)
{
	int length = strlen(s);
	for (int i = vitrixoa + 1; i < length; i++)
	{
		s[i - 1] = s[i];
	}
	s[length-1] = '\0';
}
char* XoaKhoangTrangThuong(char* s)
{
	char* p = strdup(s);
	int length = strlen(p);
	for (int i = 0; i < length; i++)
	{
		if (p[i] == '\0' && p[i + 1] == '\0')
		{
			XoaKyTu(p, i);
			i--;
			length--;
		}
	}
	if (p[0] == '\0')
	{
		XoaKyTu(p, 0);
	}
 }
int main()
{
	char s[] = "nghia dep trai";

	char p[30];

	strcpy(p, BienChuoiThanhThuong(s));
	printf("\n s= %s", s);
	printf("\n p = %s", p);
	return 0;
}