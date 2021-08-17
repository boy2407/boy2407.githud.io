#include<stdio.h>
#include<conio.h>
#include<math.h>
int main() {
	int n;
	scanf_s("%d", &n);
	int check = 1;
	if (n <2)
	{
		printf("\nkhong phai nguyen to");
	}
	else if(n >2)
	{
		if (n % 2 == 0)
		{
			check = 0;
		}
		else
		{
			for (int i = 3; i <= sqrt((double)n); i += 2)
			{
				if (n % i == 0)
				{
					check = 0;
					break;
				}
			}
			if (check == 1)
			{
				printf("\nla so nguyen to %lf", sqrt((double)n));
			}
			else
			{
				printf("\nkhong phai la so nguyen to %lf", sqrt((double)n));
			}
		}
	}

}
//int main() {
//    int N = 30;
//    bool check[30+1];
//    // Khởi tạo tất cả các số [2...N] đều là số nguyên tố
//    for (int i = 2; i <= N; i++) {
//        check[i] = true;
//    }
//
//    // Thuật toán sàng nguyên tố
//    // Nếu một số là số nguyên tố, thì tất cả các bội của nó không phải số nguyên tố
//    for (int i = 2; i <= N; i++) {//i*i<=n
//        printf("\ni=%d ", i);
//        if (check[i] == true) {
//            for (int j = 2 * i; j <= N; j += i)
//            {//j=i*i
//                check[j] = false;
//                printf("j=%d ", j);
//            }
//        }
//    }
//    // In ra các số là số nguyên tố
//    for (int i = 2; i <= N; i++) {
//        if (check[i] == true) {
//            printf("\n%d ", i);
//        }
//    }
//}

