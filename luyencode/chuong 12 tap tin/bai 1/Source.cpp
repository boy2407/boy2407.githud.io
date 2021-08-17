#include<stdio.h>
#include<conio.h>


int main()
{
	//B1 mở file
	FILE* FileIn;
	//
	FileIn = fopen("INPUT.txt", "rt");


	if (!FileIn)
	{
		printf("\nKhong Tim thay tap tin INPUT.TXT");
		return 0;

	}
	//B2 đọc dữ liệu từ tập tin vào chương trình 
	// đọc dữ liệu vào chương trình <=> nhập dư liệu từ bàn phím vào chương trình
	// ghi dữ liệu từ chương trình ra tập tin <=> xuất dữ liệu ra màn hình

	int a, b;
	//đọc dữ liệu vào chương trình.
	fscanf_s(FileIn, "%d%d", &a,&b);

	fclose(FileIn);
	int Max = a > b ? a : b;
	FILE* FileOut;
	FileOut = fopen("OUTPUT.TXT", "w");

	fprintf(FileOut,"\nMax = %d", Max);
	fclose(FileOut);
	return 0;
}