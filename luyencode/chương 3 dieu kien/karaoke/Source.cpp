#include<stdio.h>
#include<math.h>
#define GIA 30000
int main() {
	float checkin, checkout;
	printf("\ngio vao");
	scanf_s("%f", &checkin);
	printf("\ngio ra");
	scanf_s(" %f", &checkout);
	float thoigian = checkout - 17;
	float thoigiangiam = 17 - checkin;
	
		if (checkin > 17 && checkout > 17)
		{
			printf("%f", (checkout - checkin) * GIA);
		}
		else if ((checkin >= 8 && checkin <= 17))
		{
			if (checkout > 17)
			{

				printf("%f", (GIA * 0.9 * thoigiangiam) + (GIA * thoigian));
			}
			else
			{
				printf("%f", GIA * 0.9 * thoigiangiam);
			}
		}
	
	return 0;
	

}