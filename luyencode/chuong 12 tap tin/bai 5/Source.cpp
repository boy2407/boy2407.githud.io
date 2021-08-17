#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void HoanVi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void SapXep(int* a, int n, char phanloai)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (phanloai == 't')
			{
				if (a[i] > a[j])
				{
					HoanVi(a[i], a[j]);
				}
			}
			else if (phanloai == 'g')
			{
				if (a[i] < a[j])
				{
					HoanVi(a[i], a[j]);
				}
			}
		}
	}
}
int main()
{

	FILE* FileIN;

	FileIN = fopen("INPUT.TXT", "r");
	if (!FileIN)
	{
		printf("\nKhong tim thay tap tin INPUT.TXT ! Xin kiem tra lai !");
		return 0;
	}

	int n;
	int* arr;
	fscanf_s(FileIN, "%d", &n);

	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i <= n; i++)
	{	
		fscanf_s(FileIN, "%d", &arr[i]);
	}
	fclose(FileIN);

	SapXep(arr, n, 't');

	FILE* FileOut;
	FileOut = fopen("OUTPUT.TXT", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(FileOut, "%4d ", arr[i]);
	}
	fclose(FileOut);

	free(arr);
	return 0;
}