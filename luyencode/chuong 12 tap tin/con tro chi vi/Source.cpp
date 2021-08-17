///Nguyen Trong Nghia

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	FILE* FileIn;
	FileIn = fopen("INPUT.TXT", "r");
	if (!FileIn)
	{
		printf("\khong tim thay tap tin ");
		return 0;
	}

	char *str1,*str2;
	str1 = (char*)calloc(6,sizeof(char));
	str2 = (char*)calloc(6,sizeof(char));
	fseek(FileIn,7, SEEK_SET);
	fgets(str1, 6, FileIn);
	printf("%s", str1);//Trong

	fseek(FileIn,1, SEEK_CUR);
	fgets(str2, 6, FileIn);
	printf("\n%s", str2);//Nghia
	fclose(FileIn);

	return 0;
}