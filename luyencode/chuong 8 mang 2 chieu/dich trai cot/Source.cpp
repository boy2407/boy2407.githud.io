﻿
#include<stdio.h>
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
/*
Cách 1: dùng thêm mảng phụ, lưu lại cột bên phải ngoài cùng, rồi gán từ phải qua trái. Cuối cùng là gán mảng vào cột cuối bên trái
*/
void DichTraiXoayVongCacCotTrongMaTran(int a[][MAX], int dong, int cot)
{
    int temp[MAX];
    for (int i = 0; i < dong; i++)
    {
        temp[i] = a[i][0];
    }
    for (int j = 0; j < cot - 1; j++)
    {
        for (int i = 0; i < dong; i++)
        {
            a[i][j] = a[i][j + 1];
        }
    }
    for (int i = 0; i < dong; i++)
    {
        a[i][cot - 1] = temp[i];
    }
}

// Cách 2: Hoán vị 2 cột từ phải qua trái
void HoanVi(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void HoanVi2Cot(int a[][MAX], int dong, int cot, int cot1, int cot2)
{
    if ((cot1 >= 0 && cot1 < cot) && (cot2 >= 0 && cot2 < cot))
    {
        for (int i = 0; i < dong; i++)
        {
            HoanVi(a[i][cot1], a[i][cot2]);
        }
    }
}

void DichTraiXoayVongCacCotTrongMaTran_Cach2(int a[][MAX], int dong, int cot)
{
    for (int j = 0; j < cot - 2; j++)
    {
        for (int i = 0; i < dong; i++)
        {
            HoanVi(a[i][j], a[i][j + 1]);
        }
    }
}
int main()
{
    int a[MAX][MAX], dong, cot;
    int cot1, cot2;
    NhapMang(a, dong, cot);
    XuatMang(a, dong, cot);
    DichTraiXoayVongCacCotTrongMaTran_Cach2(a, dong, cot);
    printf("\nMa tran sau khi dich trai xoay vong cac cot: \n");
    XuatMang(a, dong, cot);

    
    return 0;
}

