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

	int ngay, thang, nam;

	fscanf(FileIn, "%d",&ngay);
	fseek(FileIn, 1, 2);
	fscanf(FileIn, "%d", &thang);
	fseek(FileIn, 1, 1);
	fscanf(FileIn, "%d", &nam);
	printf("\nNgay %d Thang %d Nam %d", ngay, thang, nam);
	fclose(FileIn);

	return 0;
}