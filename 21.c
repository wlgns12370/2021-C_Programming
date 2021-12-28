#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning (disable:4996)
#define SIZE 100
#define MAXBUFSIZE 100

void eg_1();
void eg_2();
void eg_3();
void eg_4();
void eg_5();


int main()
{
	// 주석을 제거하면서 문제를 실행할수있음
	eg_1();
	//eg_2();
	//eg_3();
	//eg_4();
	//eg_5();

}

typedef struct
{
	int hour;
	int min;
	int sec;

}TIME;


void eg_1()
{
	TIME list[2] = { 0 };
	FILE* fp;
	int i = 0;
	int start = 0, end = 0, result = 0;
	int hour = 0, min = 0, sec = 0;
	char f_name[SIZE / 2] = { "\0" };
	
	scanf("%s", f_name);
	fp = fopen(f_name, "r");

	while (fscanf(fp, "%d:%d:%d", &list[i].hour, &list[i].min, &list[i].sec) != EOF)
	{
		i++;
	}
	start = (list[0].hour * 3600) + (list[0].min * 60) + list[0].sec;
	end = (list[1].hour * 3600) + (list[1].min * 60) + list[1].sec;
	result = end - start;
	hour = result / 3600;
	result %= 3600;
	min = result / 60;
	result %= 60;
	sec = result;
	if (hour >= 10)
	{
		if (min >= 10)
		{
			if (sec >= 10)
			{
				printf("%d:%d:%d", hour, min, sec);
			}
			else
			{
				printf("%d:%d:0%d", hour, min, sec);
			}
		}
		else
		{
			if (sec >= 10)
			{
				printf("%d:0%d:%d", hour, min, sec);
			}
			else
			{
				printf("%d:0%d:0%d", hour, min, sec);
			}
		}
	}
	else
	{
		if (min >= 10)
		{
			if (sec >= 10)
			{
				printf("0%d:%d:%d", hour, min, sec);
			}
			else
			{
				printf("0%d:%d:0%d", hour, min, sec);
			}
		}
		else
		{
			if (sec >= 10)
			{
				printf("0%d:0%d:%d", hour, min, sec);
			}
			else
			{
				printf("0%d:0%d:0%d", hour, min, sec);
			}
		}
	}
}

typedef struct
{
	char name[SIZE / 2];
	char phone[SIZE / 2];
}P;

void eg_2()
{
	P arr[SIZE / 2] = { "\0" };
	FILE* fp;
	int cnt = 0;
	char f_name[SIZE / 2] = { "\0" };
	char sh[SIZE /2 ] = { "\0" };
	int r = -1;

	scanf("%s", f_name);
	scanf("%s", sh);
	
	fp = fopen(f_name, "r");
	
	while (fscanf(fp, "%s\n%s", arr[cnt].name, arr[cnt].phone) != EOF)
	{
		cnt++;
	}
	
	for (int i = 0; i < cnt; i++)
	{
		if (strcmp(sh,arr[i].name) == 0 )
		{
			r = i;
		}
	}
	
	if (r == -1)
	{
		printf("cannot find");
	}
	else
	{
		printf("%s : %s", arr[r].name, arr[r].phone);
	}

	

}
typedef struct
{
	int a;
	int b;
	int c;
}T;

void eg_3()
{
	T arr = {0};
	int a[3] = { 0 };
	FILE* fp;
	int cnt = 0;
	int temp = 0;
	char f_name[SIZE / 2] = { "\0" };

	scanf("%s", f_name);

	scanf("%d %d %d", &arr.a, &arr.b, &arr.c);

	a[0] = arr.a;
	a[1] = arr.b;
	a[2] = arr.c;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (a[j] < a[j + 1])
			{
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}

	
	fp = fopen(f_name, "w");

	if (a[0] > a[1]+a[2])
	{
		fprintf(fp,"Not Triangle");
	}
	else
	{
		if (a[0] == a[1] && a[0] == a[2])
		{
			fprintf(fp, "Regular Triangle");
		}
		else if(a[0] == a[1] && a[0] != a[2])
		{
			fprintf(fp, "Isosceles Triangle");
		}
		else
		{
			fprintf(fp, "General Triangle");
		}
	}

	fclose(fp);

}

typedef struct
{
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;
	int h;

}Money;

void eg_4()
{
	Money arr = { 0 };
	int m[8] = { 0 };
	int mon = 0;
	FILE* fp;
	FILE* fp2;
	int cnt = 0;
	
	char f_name[SIZE / 2] = { "\0" };
	char f_name2[SIZE / 2] = { "\0" };

	scanf("%s", f_name);
	scanf("%s", f_name2);

	fp = fopen(f_name, "r");
	fscanf(fp,"%d", &mon);

	arr.a = mon / 50000;
	mon %= 50000;
	arr.b = mon / 10000;
	mon %= 10000;
	arr.c = mon / 5000;
	mon %= 5000;
	arr.d = mon / 1000;
	mon %= 1000;
	arr.e = mon / 500;
	mon %= 500;
	arr.f = mon / 100;
	mon %= 100;
	arr.g = mon / 50;
	mon %= 50;
	arr.h = mon / 10;
	
	m[0] = arr.a;
	m[1] = arr.b;
	m[2] = arr.c;
	m[3] = arr.d;
	m[4] = arr.e;
	m[5] = arr.f;
	m[6] = arr.g;
	m[7] = arr.h;

	fp2 = fopen(f_name2, "w");

	for (cnt = 0; cnt < 8; cnt++)
	{
		if (m[cnt] != 0) {
			
			if (cnt == 0)
			{
				fprintf(fp2, "50,000:%d\n", m[cnt]);
			}
			else if (cnt == 1)
			{
				fprintf(fp2, "10,000:%d\n", m[cnt]);
			}
			else if (cnt == 2)
			{
				fprintf(fp2, "5,000:%d\n", m[cnt]);
			}
			else if (cnt == 3)
			{
				fprintf(fp2, "1,000:%d\n", m[cnt]);
			}
			else if (cnt == 4)
			{
				fprintf(fp2, "500:%d\n", m[cnt]);
			}
			else if (cnt == 5)
			{
				fprintf(fp2, "100:%d\n", m[cnt]);
			}
			else if (cnt == 6)
			{
				fprintf(fp2, "50:%d\n", m[cnt]);
			}
			else if (cnt == 7)
			{
				fprintf(fp2, "10:%d\n", m[cnt]);
			}
		}
		else
		{
			continue;
		}
	}

	fclose(fp);
	fclose(fp2);
	
}

typedef struct
{
	int year;
	int mon;
	int day;
}Y;

void eg_5()
{
	Y arr = { 0 };
	FILE* fp;
	FILE* fp2;

	char f_name[SIZE / 2] = { "\0" };
	char f_name2[SIZE / 2] = { "\0" };

	scanf("%s", f_name);
	scanf("%s", f_name2);

	fp = fopen(f_name, "r");
	fp2 = fopen(f_name2, "w");

	fscanf(fp, "%d %d %d", &arr.year , &arr.mon, &arr.day);
	

	switch (arr.mon)
	{
		case 1:
			if ( arr.day > 0 && arr.day <= 31 )
			{
				if (arr.day == 31)
				{
					arr.day = 1;
					arr.mon++;
					if (arr.mon == 13)
					{
						arr.mon = 1;
						arr.year++;
					}
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
				else
				{
					arr.day++;
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
			}
			else
			{
				fprintf(fp2, "wrong input");
				break;
			}

		case 2:
			if ((arr.year%4 == 0 && arr.year%100 != 0) || arr.year%400 == 0)
			{
				if (arr.day > 0 && arr.day <= 29)
				{
					if (arr.day == 29)
					{
						arr.day = 1;
						arr.mon++;
						if (arr.mon == 13)
						{
							arr.mon = 1;
							arr.year++;
						}
						fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
						break;
					}
					else
					{
						arr.day++;
						fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
						break;
					}
				}
				else
				{
					fprintf(fp2, "wrong input");
					break;
				}
			}
			else
			{
				if (arr.day > 0 && arr.day <= 28)
				{
					if (arr.day == 28)
					{
						arr.day = 1;
						arr.mon++;
						if (arr.mon == 13)
						{
							arr.mon = 1;
							arr.year++;
						}
						fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
						break;
					}
					else
					{
						arr.day++;
						fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
						break;
					}
				}
				else
				{
					fprintf(fp2, "wrong input");
					break;
				}
			}
		case 3:
			if (arr.day > 0 && arr.day <= 31)
			{
				if (arr.day == 31)
				{
					arr.day = 1;
					arr.mon++;
					if (arr.mon == 13)
					{
						arr.mon = 1;
						arr.year++;
					}
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
				else
				{
					arr.day++;
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
			}
			else
			{
				fprintf(fp2, "wrong input");
				break;
			}

		case 4:
			if (arr.day > 0 && arr.day <= 30)
			{
				if (arr.day == 30)
				{
					arr.day = 1;
					arr.mon++;
					if (arr.mon == 13)
					{
						arr.mon = 1;
						arr.year++;
					}
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
				else
				{
					arr.day++;
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
			}
			else
			{
				fprintf(fp2, "wrong input");
				break;
			}

		case 5:
			if (arr.day > 0 && arr.day <= 31)
			{
				if (arr.day == 31)
				{
					arr.day = 1;
					arr.mon++;
					if (arr.mon == 13)
					{
						arr.mon = 1;
						arr.year++;
					}
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
				else
				{
					arr.day++;
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
			}
			else
			{
				fprintf(fp2, "wrong input");
				break;
			}
	
		case 6:
			if (arr.day > 0 && arr.day <= 30)
			{
				if (arr.day == 30)
				{
					arr.day = 1;
					arr.mon++;
					if (arr.mon == 13)
					{
						arr.mon = 1;
						arr.year++;
					}
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
				else
				{
					arr.day++;
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
			}
			else
			{
				fprintf(fp2, "wrong input");
				break;
			}

		case 7:
			if (arr.day > 0 && arr.day <= 31)
			{
				if (arr.day == 31)
				{
					arr.day = 1;
					arr.mon++;
					if (arr.mon == 13)
					{
						arr.mon = 1;
						arr.year++;
					}
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
				else
				{
					arr.day++;
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
			}
			else
			{
				fprintf(fp2, "wrong input");
				break;
			}

		case 8:
			if (arr.day > 0 && arr.day <= 31)
			{
				if (arr.day == 31)
				{
					arr.day = 1;
					arr.mon++;
					if (arr.mon == 13)
					{
						arr.mon = 1;
						arr.year++;
					}
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
				else
				{
					arr.day++;
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
			}
			else
			{
				fprintf(fp2, "wrong input");
				break;
			}
		
		case 9:
			if (arr.day > 0 && arr.day <= 30)
			{
				if (arr.day == 30)
				{
					arr.day = 1;
					arr.mon++;
					if (arr.mon == 13)
					{
						arr.mon = 1;
						arr.year++;
					}
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
				else
				{
					arr.day++;
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
			}
			else
			{
				fprintf(fp2, "wrong input");
				break;
			}
		
		case 10:
			if (arr.day > 0 && arr.day <= 31)
			{
				if (arr.day == 31)
				{
					arr.day = 1;
					arr.mon++;
					if (arr.mon == 13)
					{
						arr.mon = 1;
						arr.year++;
					}
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
				else
				{
					arr.day++;
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
			}
			else
			{
				fprintf(fp2, "wrong input");
				break;
			}

		
		case 11:
			if (arr.day > 0 && arr.day <= 30)
			{
				if (arr.day == 30)
				{
					arr.day = 1;
					arr.mon++;
					if (arr.mon == 13)
					{
						arr.mon = 1;
						arr.year++;
					}
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
				else
				{
					arr.day++;
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
			}
			else
			{
				fprintf(fp2, "wrong input");
				break;
			}
		
		case 12:
			if (arr.day > 0 && arr.day <= 31)
			{
				if (arr.day == 31)
				{
					arr.day = 1;
					arr.mon++;
					if (arr.mon == 13)
					{
						arr.mon = 1;
						arr.year++;
					}
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
				else
				{
					arr.day++;
					fprintf(fp2, "%d.%d.%d", arr.year, arr.mon, arr.day);
					break;
				}
			}
			else
			{
				fprintf(fp2, "wrong input");
				break;
			}

		default:
			fprintf(fp2,"wrong input");
			break;
	}
}

