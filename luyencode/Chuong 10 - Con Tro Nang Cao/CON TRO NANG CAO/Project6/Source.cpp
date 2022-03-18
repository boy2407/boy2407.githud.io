#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void NhapMangRangCua(int **a, int dong, int *cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot[i]; j++)
		{
			printf("\nNhap vao a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void XuatMangRangCua(int **a, int dong, int *cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot[i]; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int dong;

	printf("\nNhap vao so dong: ");
	scanf("%d", &dong);

	int *cot = (int *)malloc(dong * sizeof(int));

	int **a = (int **)malloc(dong * sizeof(int));
	for(int i = 0; i < dong; i++)
	{
		printf("\nBan muon tren dong %d co bao nhieu cot: ", i);
		scanf("%d", &cot[i]);
		a[i] = (int *)malloc(cot[i] * sizeof(int));
	}

	NhapMangRangCua(a, dong, cot);
	XuatMangRangCua(a, dong, cot);

	for(int i = 0; i < dong; i++)
	{
		free(a[i]);
	}
	free(a);

	free(cot);

	getch();
	return 0;
}