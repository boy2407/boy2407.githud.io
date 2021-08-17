#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void XuatMang(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
}
void DocFile(FILE *&FileIn, int* &a, int&n)
{
	FileIn = fopen("TapTin.TXT", "rb");
	if (!FileIn)
	{
		printf("\nKhong Tim thay tap tin");
		exit(0);
	}
	fseek(FileIn, 0, SEEK_END);
	n = (ftell(FileIn) + 1) / (sizeof(int));
	a = (int*)malloc(n * 4);
	rewind(FileIn);
	fread(a, sizeof(int), n, FileIn);

	fclose(FileIn);
}
int main()
{
	int n, *a;
	FILE* FileIn;
	DocFile(FileIn, a,n);
	XuatMang(a, n);
	free(a);
	return 0;

}