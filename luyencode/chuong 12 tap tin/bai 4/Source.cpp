#include<stdio.h>

#include<conio.h>

int main()
{

	FILE* FileIN;
	FileIN = fopen("INPUT.TXT", "r");
	//eof=> end of line 
	
	int Max;
	fscanf_s(FileIN, "%d", &Max);
	// vòng l?p này s? l?p liên t?c cho t?i ??n cu?i file
	while (!feof(FileIN))
	{
		int Number;
		fscanf_s(FileIN, "%d", &Number);
		if (Number > Max)
		{
			Max = Number;
		}
	}
	fclose(FileIN);


	FILE* FileOut;
	FileOut = fopen("OUTPUT.TXT", "w");
	fprintf(FileOut, "\nMax = %d", Max);
	fclose(FileOut);
	return 0;
}