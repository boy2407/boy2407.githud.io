#include<stdio.h>
#include<math.h>
int main() {
	float x = 6000000;

	x +=x*(1.8/100);
	x += x * (1.8 / 100);
	x += x * (1.8 / 100);
	x += x * (1.8 / 100);
	x += x * (1.8 / 100);
	x += x * (1.8 / 100);
	x += x * (1.8 / 100);
	x += x * (1.8 / 100);
	x += x * (1.8 / 100);
	x += x * (1.8 / 100);

	printf("%f", x);
}