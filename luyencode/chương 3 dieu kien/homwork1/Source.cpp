#include<stdio.h>
#include<math.h>
#include<conio.h>
/*int main() {
	int a, b, c, d,max,min;
	scanf_s("%d%d%d%d", &a, &b, &c,&d );
	printf("1111\n");
	max = a;
	min = a;
	if (b > max)
	{
		max = b;
	}
	if (c > max)
	{
		max = c;
	}
	if (d > max)
	{
		max = d;
	}
	printf("%d", max);
	if (b < min)
	{
		min = b;
	}
	if (c < min)
	{
		min = c;
	}
	if (d < min) {
		min = d;
	}
	printf(" %d ", min);
}*/
//int main()
//{
//    int a, b, c;
//    scanf_s("%d%d%d", &a, &b, &c);
//    if (a == 5 || a == 7)
//    {
//        if (a == 5)
//        {
//            if (b == 5 && c == 7|| c == 5 && b == 7)
//            {
//                printf("YES");
//            }
//			else
//			{
//				printf("NO");
//			}                     
//        }
//        else if (a == 7)
//        {
//            if (c == 5 && b== 5)
//            {
//                printf("YES");
//            }
//            else
//            {
//                printf("NO");
//            }
//        }
//    }
//    else
//    {
//        printf("NO");
//    }
//    return 0;
//}
int main()
{
	int a, b, c;
	scanf_s("%d%d%d", &a, &b, &c);
	if ((a==5&&b==5&&c==7)|| (a == 7 && b == 5 && c == 5)|| (a == 5 && b == 7 && c == 5))
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	
}