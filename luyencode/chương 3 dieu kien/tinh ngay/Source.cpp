#include<stdio.h>
#include<math.h>
int main() {
	int ngaytruocdo, thangtruocdo, namtruocdo;
	int ngaykettiep, thangketiep, namketiep;
	int thang, ngay, nam;

	scanf_s("%d%d%d", &ngay, &thang, &nam);
	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
	{

		if (ngay >= 2 && ngay <= 30)
		{
			ngaykettiep = ngay + 1;
			thangketiep = thang;
			namketiep = nam;

			ngaytruocdo = ngay + -1;
			thangtruocdo = thang;
			namtruocdo = nam;
		}
		else if (ngay == 1) // ngay dau thang 
		{
			ngaykettiep = ngay + 1;
			thangketiep = thang;
			namketiep = nam;

			//xét tháng trước đó có bao nhiêu ngày 
			thangtruocdo = thang - 1;
			if (thangtruocdo == 0)
			{
				thangtruocdo = 12;
				namtruocdo = nam - 1;
				ngaytruocdo = 31;
			}
			else if (thangtruocdo == 7)
			{
				ngaytruocdo = 31;
				namtruocdo = nam;

			}
			else if (thangtruocdo == 4 || thangtruocdo == 6 || thangtruocdo == 9 || thangtruocdo == 11)
			{
				ngaytruocdo = 30;
				namtruocdo = nam;
			}
			else// thang 2			
			{
				if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
				{
					ngaytruocdo = 29;

				}
				else
				{
					ngaytruocdo = 28;
				}

				namtruocdo = nam;
			}

		}
		else if (ngay == 31)
		{
			ngaykettiep = 1;
			thangketiep = thang + 1;
			namketiep = nam;
			if (thangketiep == 13)
			{
				namketiep = nam + 1;
				thangketiep = 1;
			}
			ngaytruocdo = ngay - 1;
			thangtruocdo = thang;
			namtruocdo = nam;
		}

	}
	else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
	{
		if (ngay >= 2 && ngay <= 29)
		{
			ngaykettiep = ngay + 1;
			thangketiep = thang;
			namketiep = nam;

			ngaytruocdo = ngay + -1;
			thangtruocdo = thang;
			namtruocdo = nam;
		}
		else if (ngay == 1)
		{
			ngaykettiep = ngay + 1;
			thangketiep = thang;
			namketiep = nam;

			//xét tháng trước đó có bao nhiêu ngày 
			thangtruocdo = thang - 1;
			if (thangtruocdo == 0)
			{
				thangtruocdo = 12;
				namtruocdo = nam - 1;
			}
			else
			{
				namtruocdo = nam;
			}
			if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
			{
				ngaytruocdo = 31;
			}
			else if (thangtruocdo == 4 || thangtruocdo == 6 || thangtruocdo == 9 || thangtruocdo == 11)
			{
				ngaytruocdo = 30;
			}
			/*else
			{
				if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
				{
					ngaytruocdo == 29;
				}
				else
				{
					ngaytruocdo == 28;
				}
			}*/
		}
		else if (ngay == 30)
		{
			ngaykettiep = 1;
			thangketiep = thang + 1;
			namketiep = nam;

			ngaytruocdo = ngay - 1;
			thangtruocdo = thang;
			namtruocdo = nam;
		}
	}
	else
	{

		if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
		{
			if (ngay >= 2 && ngay <= 28)
			{
				ngaykettiep = ngay + 1;
				thangketiep = thang;
				namketiep = nam;

				ngaytruocdo = ngay - 1;
				thangtruocdo = thang;
				namtruocdo = nam;
			}
			else if (ngay == 1)
			{
				ngaykettiep = ngay + 1;
				thangketiep = thang;
				namketiep = nam;

				ngaytruocdo = 31;
				thangtruocdo = thang - 1;
				namtruocdo = nam;
			}
			else
			{
				thangketiep = thang + 1;
				namketiep = nam;
				ngaykettiep = 1;

				ngaytruocdo = ngay - 1;
				thangtruocdo = thang;
				namtruocdo = nam;
			}

		}
		else
		{
			if (ngay >= 2 && ngay <= 27)
			{
				ngaykettiep = ngay + 1;
				thangketiep = thang;
				namketiep = nam;
			}
			else if (ngay == 1)
			{
				ngaykettiep = ngay + 1;
				thangketiep = thang;
				namketiep = nam;

				ngaytruocdo = 31;
				thangtruocdo = thang - 1;
				namtruocdo = nam;
			}
			else
			{
				thangketiep = thang + 1;
				namketiep = nam;
				ngaykettiep = 1;

				ngaytruocdo = ngay - 1;
				thangtruocdo = thang;
				namtruocdo = nam;
			}

		}
	}
	printf("\nngay %d thang %d nam %d", ngay, thang, nam);
	printf("\nngay truoc do %d thang truoc do %d nam truoc do %d", ngaytruocdo, thangtruocdo, namtruocdo);
	printf("\nngay ke %d thang ke  %d nam ke %d", ngaykettiep, thangketiep, namketiep);
	return 0;

}