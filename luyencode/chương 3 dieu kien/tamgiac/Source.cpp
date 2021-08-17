#include<stdio.h>
#include<math.h>
int main() {
	int a1, a2, b1, b2, c1, c2;
	printf("\nnhap toa do diem A (X,Y)");
	scanf_s("%d %d", &a1, &a2);
	printf("\nnhap toa do diem B (X,Y)");
	scanf_s("%d %d", &b1, &b2);
	printf("\nnhap toa do diem C (X,Y)");
	scanf_s("%d %d", &c1, &c2);
	double ab, bc, ca,s,s1,p;
	ab = sqrt(pow((double)(b1 - a1), 2) + pow((double)(b2 - a2),2));
	bc = sqrt(pow((double)(c1 - b1), 2) + pow((double)(c2 - b2), 2));
	ca = sqrt(pow((double)(a1 - c1), 2) + pow((double)(a2 - c2), 2));
	p = (ab + bc + ca) / 2.0;
	if (ab + bc <= ca || ab + ca <= bc || ca + bc <= ab)
	{
		printf("khong phai tam giac");
		printf("\nAB :%f", ab);
		printf("\nAC: %f", ca);
		printf("\nBC: %f", bc);
	}
	else
	{
		s = abs((b1 - a1) * (c2 - a2) - (c1 - a1) * (b2 - a2))*(1.0/2);
		s1 = sqrt(p * (p-ca) * (p - bc) * (p - ab));
		printf("\ndien tich cua tam giac la : %f", s1);
		printf("\ndien tich cua tam giac la : %f", s);
		printf("\nAB :%f", ab);
		printf("\nAC: %f", ca);
		printf("\nBC: %f", bc);
	}
	// công thức tính diện theo 3 toa độ đỉnh 1/2(b1-a1)*(c2-a2)-(c1-a1)*(b2-a2)
}