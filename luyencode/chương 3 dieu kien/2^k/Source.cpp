#include<stdio.h>
#include<math.h>
int main() {
	float a, k;
	scanf_s("%f", &a);
	 k = log10(a) / log10(2);
	 if (k ==(int)k)
	 {
		 printf("%.f la chi co 2^k có s? k là %.f", a, k);
	 }
	 else
	 {
		 printf("%.f khong phai chi co 2^k",a);
	 }
}