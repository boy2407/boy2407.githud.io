#include<string.h>
#include<conio.h>
#include<stdio.h>

char* SubStr(char* s, int start, int end)
{
	char p[100];
	int idx = 0;
	for (int i = start; i <= end; i++)
	{
		p[idx++] = s[i];
	}
	p[idx] = '\0';
	return p;
}
void XuatCacTu(char* s)
{
	int Start, End;
	int Length = strlen(s);
	for (int i = 0; i < Length; i++)
	{
		if (s[i] != ' ')
		{
			Start = i;
			for (int j = Start;  j <= Length; j++)
			{
				if (s[j] = ' ' || s[j] == '\0')
				{
					End = j - 1;
					char p[100];
					strcpy(p, SubStr(s, Start, End));
					printf("\n%s", p);
					 
					i = j;///quan trong 
					// cap nhat lai vi tri
					break;
				}
			}
		}
	}
}

int main()
{

}