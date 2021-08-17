#include<stdio.h>
#include<conio.h>

int main()
{
	
	FILE* FileIN;
	FileIN = fopen("INPUT.TXT", "r");

	int n;
	n=fgetc(FileIN);
	printf("\n%d", n);
	int Max;
	fscanf_s(FileIN, "%d", &Max);
	printf("\n%d", Max);
	for (int i = 2; i <= n; i++)
	{
		int Number;
		Number = fgetc(FileIN);
		if (Number > Max)
		{
			
			Max = Number;
		}
	}
	fclose(FileIN);



	FILE* FileOut;
	FileOut = fopen("OUTPUT.TXT","w" );
	fprintf(FileOut, "\nMax = %d", Max);
	fclose(FileOut);
	return 0;
}