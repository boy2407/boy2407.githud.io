﻿#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
void NhapMang(int a[][MAX], int& dong, int& cot)
{
    //Nhập số dòng
    do
    {
        printf("\nNhap vao so dong: ");
        // Cách tà đạo: scanf("dong =%d",&dong);  // Lúc nhập phải viết thêm  chữ ( dong =  ) ở khung console
        scanf_s("%d", &dong);

        if (dong < 1 || dong > MAX)
        {
            printf("\nSo dong khong hop le. Xin kiem tra lai!");
        }

    } while (dong < 1 || dong > MAX);

    //Nhập số cột
    do
    {
        printf("\nNhap vao so cot: ");
        scanf_s("%d", &cot);

        if (cot < 1 || cot > MAX)
        {
            printf("\nSo cot khong hop le. Xin kiem tra lai!");

        }

    } while (cot < 1 || cot > MAX);
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            printf("\nNhap a[%d][%d] = ", i, j);
            scanf_s("%d", &a[i][j]);
        }
    }
}

void XuatMang(int a[][MAX], int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n\n");
    }
}

void LietKeCacCotCoNhieuChuSoNhat(int a[][MAX], int dong, int cot)
{
    
        int dem[MAX] = { 0 };
        for (int i = 0; i < cot; i++)
        {
            for (int j = 0; j < dong; j++)
            {
                int tam = abs(a[j][i]);
                do
                {
                    dem[i]++;
                    printf("\n%d", dem[i]);
                    tam /= 10;
                } while (tam > 0);
            }          
        }
        for (int t = 0; t < cot;t++)
        {
            printf("\n%d", dem[t]);
        }
        int Max = dem[0];
        for (int i = 1; i < cot; i++)
        {
            Max = (Max > dem[i]) ? Max : dem[i];
        }
        for (int i = 0; i < cot; i++)
        {
            if (Max == dem[i])
            {
                printf("\nCot %d co nhieu chu so nhat la %d", i, Max);
            }
        }
    
}
int main()
{
    int a[MAX][MAX], dong, cot;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    LietKeCacCotCoNhieuChuSoNhat(a, dong, cot);


   
    return 0;
}