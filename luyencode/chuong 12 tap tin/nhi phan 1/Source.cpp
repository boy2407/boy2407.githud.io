#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void NhapMang(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\Nhap vao a[%d] = ",i);
		scanf_s("%d", &a[i]);
	}
}
void GhiFile(FILE*& FileOut, int* a, int n)
{
	FileOut = fopen("TapTin.DOC", "wb");
	if (FileOut != NULL)
	{
		fwrite(a, sizeof(int), n, FileOut);
	}
	fclose(FileOut);
}
int main()
{

	int n = 5;
	int* a = (int*)malloc(n * sizeof(int));

	NhapMang(a, n);
	FILE *FileOut;
	GhiFile(FileOut, a, n);
	return 0;
}