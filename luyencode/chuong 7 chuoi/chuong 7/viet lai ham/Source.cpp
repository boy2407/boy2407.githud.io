#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
int Strlen(char* s);
void textcolor(int x);
void Strcpy(char* s1, char* s2);
void Strcpy(char* s1, char* s2)
{
	int lengths2 = Strlen(s2);
	for (int i = 0; i < lengths2; i++)
	{
		s1[i] = s2[i];
	}
	s1[lengths2] = '\0';// phai co ket thuc chuoi
}
int Strlen(char* s)
{
	int dem = 0;
	while (s[dem++] != '\0') {}
	return dem - 1;
}
char* Strdup(char* s)
{
	int length = Strlen(s);
	char* p = (char*)malloc(length + 1);// cap phat bo nho cho length +1
	Strcpy(p, s);
	return p;
}
void Strlwr(char* s)
{
	int length = Strlen(s);
	for (int i = 0; i < length; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] += 32;
		}
	}
}
void Strupr(char* s)
{
	int length = Strlen(s);
	for (int i = 0; i < length; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
		}
	}
}
void HoanVi(char& x, char& y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}
void Strrev(char* s)
{
	int length = Strlen(s);
	for (int i = 0; i < length / 2; i++)
	{
		HoanVi(s[i], s[length - 1 - i]);
	}
}
int Strcmp(char* s1, char* s2)
{
	int i;
	int Min = Strlen(s1) < Strlen(s2) ? Strlen(s1) : Strlen(s2);
	for (i = 0; i < Min; i++)
	{
		if (s1[i] < s2[i])
		{
			return -1;
		}
		else if (s1[i] > s2[i])
		{
			return 1;
		}
	}
	if (s1[i] == '\0')
	{
		if (s2[i] == '\0')
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	if (s2[i] == '\0')
	{
		if (s1[i] == '\0')
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}
int Stricmp(char* s1, char* s2)
{
	Strlwr(s1);
	Strlwr(s2);
	return Strcmp(s1, s2);
}
void Strcat(char* s1, char* s2)
{
	int lengths1 = Strlen(s1);
	int lengths2 = Strlen(s2);
	for (int i = 0; i < lengths2; i++)
	{
		s1[lengths1++] = s2[i];
	}
	s1[lengths1] = '\0';
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void Strstr(char* s, char* key)
{
	int length_s = Strlen(s);
	int length_key = Strlen(key);
	int idx = 0;
	int arr[100];

	for (int i = 0; i < length_s; i++)
	{
		if (s[i] == key[0])
		{
			bool check = true;
			int k = 1;
			for (int j = i + 1; j < length_key; j++)
			{
				if (s[j] != key[k++])
				{
					check = false;
					break;
				}
			}
			if (check == true)
			{
				//i start, i+length_key la end
				arr[idx++] = i;
			}
		}
	}
	idx = 0;
	for (int i = 0; i < length_s; i++)		
	{

		if (i == arr[idx])
		{
			textcolor(14);
		}
		if (i == arr[idx] + length_key)
		{
			textcolor(7); // bat mau trang
			idx++;
		}
		printf("%c", s[i]);
	}
	textcolor(7);
}
int ATOI(char* s)
{
	int length = strlen(s);
	int tong = 0;
	int Temp = length;
	for (int i = 0; i < length; i++)
	{
		if (s[i] < '0' || s[i]>'9')
		{
			Temp = i;
			break;
		}
	}
	int Temp1 = Temp;
	for (int i = 0; i < Temp; i++)
	{		
		tong += (s[i] - 48) * pow(10.0, --Temp1);
	}
	return tong ;
}
float ATOF(char* s)
{
	int length = strlen(s);
	char phannguyen[30];
	char phanle[30];
	int index=0;
	bool check = true;
	for (int i = 0; i < length; i++)
	{
		if (s[i] < '0' || s[i]>'9')
		{
			if (s[i] == '.')
			{
				check = false;
				index = 0;
				continue;
			}
			break;
			
		}
		if (check==true)
		{
			phannguyen[index++] = s[i];
		}
		else 
		{
			phanle[index++] = s[i];
		}
		
	}
	float nguyen = ATOI(phannguyen);
	float le = ATOI(phanle)/pow(10.0,index);
	double tong = nguyen + le;
	return tong ;
}
void ITOA(int value, char* ketqua, int coso)
{		
	int idx = 0;
	while (value != 0)
	{
		int so = value % coso;
		if (so < 10)
		{
			ketqua[idx++] = so + 48;
		}
		else if(so == 10)
		{
			ketqua[idx++] = 'A';
		}
		else if (so == 11)
		{
			ketqua[idx++] ='B';
		}
		else if (so == 12)
		{
			ketqua[idx++] = 'C';
		}
		else if (so == 13)
		{
			ketqua[idx++] ='D';
		}
		else if (so == 14)
		{
			ketqua[idx++] = 'E';
		}
		else if (so == 15)
		{
			ketqua[idx++] = 'F';
		}
		value /= coso;
	}
	ketqua[idx] = '\0';
	Strrev(ketqua);
}
int main()
{

	char s1[] = "250";
	char s2[] = "dep trai";
	float tong = ATOF(s1);
	printf("%lf", tong);
	int value = 16;
	int coso = 16;
	char ketqua[30];
	ITOA(value, ketqua, coso);
	printf("\n%s", ketqua);
	
	return 0;
}