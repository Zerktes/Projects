#include <stdio.h>

int days(int, int);
int dayofweek(int, int);

int main()
{
	int year, month;
	printf("enter month: ");
	scanf("%d", &month);
	printf("enter year: ");
	scanf("%d", &year);

	if (month <= 0 || month > 12)
		printf("!Error : Enter valid month between 1 and 12 \n");
	else if (year <= 0)
		printf("!Error : Enter valid year \n");
	else
	{
		int n = days(month, year);
		int r = dayofweek(month, year);
		int date = 1;
		printf("%d \n", n);
		printf("year : %d, month : %d\n", year, month);
		printf("Su  Mo  Tu  We  Th  Fr  Sa \n");

		
		for (int i = 1; i <= 6; i++)
		{
			{
				for (int k = 1; k <= 7; k++)
				{
					if (date == n + 1)
						break;
					else
					{
						(i <= 1 && k <= r) ? printf("    ") : printf("%2d  ", date++);
					}
				}
				printf("\n");
			}
		}
	}
}

int days(int month, int year)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		return 31;
	}
	else if (month == 2)
	{
		if (year % 4 == 0)
		{
			if (year % 100 == 0 && year % 400 != 0)
				return 28;
			else
				return 29;
		}
		else
			return 28;
	}
	else
		return 30;
}

int dayofweek(int month, int year)
{
	int month_code[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
	int century_code;

	if (year % 400 <= 99 && year % 400 >= 0)
	{
		century_code = 6;
	}

	else if (year % 400 <= 199 && year % 400 >= 100)
	{
		century_code = 4;
	}

	else if (year % 400 <= 299 && year % 400 >= 200)
	{
		century_code = 2;
	}

	else if (year % 400 <= 399 && year % 400 >= 300)
	{
		century_code = 0;
	}

	int lastTwoDigit = year % 100;
	int add = 1 + month_code[month - 1] + century_code + lastTwoDigit + (lastTwoDigit / 4);
	if ((year % 4 == 0 || year % 400) && (month == 1 || month == 2))
		return (add % 7) - 1;
	else
		return add % 7;
}


















