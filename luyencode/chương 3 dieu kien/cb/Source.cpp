#include<math.h>
#include<stdio.h>

int main() {

    
    // nhập số có 2 chữ số , in ra cách đọc
    int n; 
    printf("\nnhap vao n");
    scanf_s("%d", &n);
    int check = 0;
    
    if (n < 0)
    {
        check = 1;//Bật thành 1 
        n *= -1;// biến n thành dương
    }
    int sochuso = log10((double)n) + 1;
    // xử lý
    if (sochuso == 2)
    {
        int hangchuc, hangdonvi;
        hangchuc = n / 10;
        hangdonvi = n % 10;
        if (check == 1)
        {
            printf("Am");
        }
        hangdonvi = n % 10;
        if (hangchuc == 1)
        {
            printf("\nmuoi");
        }
        else if (hangchuc==2)
        {
            printf("\nhai muoi");
        }
        else if (hangchuc == 3)
        {
            printf("\nba muoi");
        }
        else if (hangchuc == 4)
        {
            printf("\nbon muoi");
        }
        else if (hangchuc == 5)
        {
            printf("\nnam muoi");
        }
        else if (hangchuc == 6)
        {
            printf("\nsau muoi");
        }
        else if (hangchuc == 7)
        {
            printf("\nbay muoi");
        }
        else if (hangchuc == 8)
        {
            printf("\ntam muoi");
        }
        else if (hangchuc == 9)
        {
            printf("\nchin muoi");
        }
        if (hangdonvi == 1)
        {
            printf(" mot ");
        }
        else if (hangdonvi == 2)
        {
            printf(" hai ");
        }
        else if (hangdonvi == 3)
        {
            printf(" ba ");
        }
        else if (hangdonvi == 4)
        {
            printf(" bon ");
        }
        else if (hangdonvi == 5)
        {
            printf(" nam ");
        }
        else if (hangdonvi == 6)
        {
            printf(" sau");
        }
        else if (hangdonvi == 7)
        {
            printf(" bay");
        }
        else if (hangdonvi == 8)
        {
            printf(" tam ");
        }
        else if (hangdonvi == 9)
        {
            printf(" chin");
        }
        
    }
    else
    {
        printf("\n so chu so phải la 2 chu so");
    }
    return 0;
}