#include<stdio.h>
#include<math.h>
int giaiphuongtrinh(float a, float b, float c, float& x1, float& x2)
{
	float detal = b * b - a * 4 * c;
	if (detal < 0) {
		x1 = x2 = 0.0;
		return 0;
	}
	else if (detal == 0) {
		x1 = x2 = -b / (2 * a);
		return 1;
	}
	else
	{
		detal == sqrt(detal);
		x1 = (-b + detal) / (2 * a);
		x2 = (-b - detal) / (2 * a);
		return 2;
	}
}
int main() {
	float a, b, c, x1,x2;
	do 
	{
		scanf_s("%f%f%f", &a, &b, &c); 
	}
	while (!a);
	if (giaiphuongtrinh(a, b, c, x1, x2) == 0)
	{
		printf("phuong trinh vao nghiem");
	}
	else if (giaiphuongtrinh(a,b,c,x1,x2)==1)
	{
		if (x1 < 0) {
			printf("phuong trinh vao nghiem");
		 }
		else if (x1 == 0)
		{
			printf("phuong trinh co mot nghiem");
		}
		else
		{
			printf("phuong trinh co 2 nghiem %f %f ", sqrt(x1), -sqrt(x1));
		}
	}
	else 
	{
		if (x1 < 0) {
			if (x2 < 0) {
				printf("phuong trinh vo nghiem");
			}
			else if (x2 == 0) {
				printf("phuong trinh co 2 nghiem %f %f", sqrt(x2), -sqrt(x2));
			}
		}
		else if (x1 == 0) {
			if (x2 < 0) {
				printf("phuong trinh co mot nghiem 0");
			}
			else
			{
				printf("phuong trinh co 3 nghiem %f %f 0", sqrt(x2), -sqrt(x2));
			}
		}
		else
		{
			if (x2 < 0) {
				printf("phuong trinh co 2 nghiem %f %f ", sqrt(x1), -sqrt(x1));

			}
			else if (x2==0)
			{	
				printf("phuong trinh co 3 nghiem 0 %f %f", sqrt(x1), -sqrt(x1));
			}
			else
			{
				printf("phuong trinh co 4 nghiem %f %f %f %f", sqrt(x1), -sqrt(x1), sqrt(x2), -sqrt(x2));
			}
		}
	}

}
