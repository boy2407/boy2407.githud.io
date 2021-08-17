#include <stdio.h>
#include<math.h>

int main() {
	int month, year;
	scanf_s("%d%d", &month, &year);
	int check = 0;
	if (year % 400==0) {
		check = 1;
		
	}
	if (year % 4==0 && year % 100 != 0)
	{
		check = 1;
		
	}
	switch (month)
	{
	case 1:
		printf("31");
		break;
	case 2:
		if (check==0)
		{
			printf("28");
			
		}
		else if (check == 1)
		{
			
			printf("29");
		}	
		break;
	case 3:
		printf("31");
		break;
	case 4:
		printf("30");
		break;
	case 5:
		printf("31");
		break;
	case 6:
		printf("30");
		break;
	case 7:
		printf("31");
		break;
	case 8:
		printf("31");
		break;
	case 9:
		printf("30");
		break;
	case 10:
		printf("31");
		break;
	case 11:
		printf("30");
		break;
	case 12:
		printf("31");
		break;
	}
}
