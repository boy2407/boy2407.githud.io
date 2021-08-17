#include<stdio.h>
#include<math.h>
/*
số chính phuowg là số mà khai căn bạc 2 ra kết quả số nguyên

*/
int main() {
   int a;
    scanf_s("%d", &a);
    if (a >= 0)
    {
        double kq = sqrt((double)a);
        if (kq == (int)kq)
        {
            printf("\nLa so chinh phuong");
        }
        else
        {
            printf("\nkhong phai so chinh phuong");
        }
    }
    else
    {
        printf("gia tri khong hop le");
    }
  
    return 0;
}