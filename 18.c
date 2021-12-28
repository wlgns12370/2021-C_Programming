#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define SIZE 100
#define MAXBUFSIZE 100

void eg_1();
void eg_2();
typedef enum day day;
void eg_3();
void eg_4();
void eg_5();
void eg_6();

int main()
{
	//eg_1();
	eg_2();
	//eg_3();
	//eg_4();
	//eg_5();
	
}

typedef struct
{
	int num;
	char mw;
	double t;
	double w;

}Student;

void PrintfS(Student arr[], int size)
{
	int mcnt = 0;
	double mttotal = 0;
	double mwtotal = 0;
	double wwtotal = 0;
	double wttotal = 0;
	int wcnt = 0;
	double mtavg = 0;
	double mwavg = 0;
	double wtavg = 0;
	double wwavg = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].mw == 'M')
		{
			mttotal += arr[i].t;
			mwtotal += arr[i].w;
			mcnt++;
		}

		else if(arr[i].mw == 'W')
		{
			wttotal += arr[i].t;
			wwtotal += arr[i].w;
			wcnt++;
		}

	}
	mtavg = mttotal / mcnt;
	mwavg = mwtotal / mcnt;
	wtavg = wttotal / wcnt;
	wwavg = wwtotal / wcnt;

	printf("M : %d %.1lf %.1lf\n", mcnt, mtavg, mwavg);
	printf("W : %d %.1lf %.1lf\n", wcnt, wtavg, wwavg);
}

void eg_1()
{
	Student arr[SIZE];

	int num;
	char temp;
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++)
	{
		scanf("%d\n", &arr[i].num);
		scanf("%c", &arr[i].mw);
		scanf("%lf", &arr[i].t);
		scanf("%lf", &arr[i].w);
		
	}

	PrintfS(arr, num);
}

enum M
{
	SUN,
	SAT,
	MON,
	TUE,         // ÃÊ±ê°ª ÇÒ´ç
	WED,
	THU,
	FRI,
	
};

enum day
{
	FRI,
	SAT,
	SUN,
	MON,
	TUE,
	WED,
	THU
};


void eg_2()
{
	day may;
	int get;
	scanf("%d", &get);
	get -= 210500;
	get %= 7;
	may = get;
	switch (may)
	{
	case 0:
		printf("FRI\n");
		break;
	case 1:
		printf("SAT\n");
		break;
	case 2:
		printf("SUN\n");
		break;
	case 3:
		printf("MON\n");
		break;
	case 4:
		printf("TUE\n");
		break;
	case 5:
		printf("WED\n");
		break;
	case 6:
		printf("THU\n");
		break;

	default:
		break;
	}
	if (get == 1 || get == 2)
	{
		printf("WEEKEND");
	}
	else
	{
		printf("WEEKDAY");
	}
}
typedef struct Team
{
	char team[100];
	char country[100];
} team;
typedef struct Player
{
	char name[100];
	int age;
	team team;
} player;


void eg_3()
{
	int n;
	char geteam[100] = { 0 };
	player get[100];
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s\n", get[i].name);
		scanf("%d\n", &get[i].age);
		scanf("%s\n", get[i].team.team);
		scanf("%s\n", get[i].team.country);
	}
	while (1)
	{
		gets(geteam);
		if (strcmp(geteam, "exit") == 0)
		{
			break;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (strcmp(get[i].team.team, geteam) == 0)
				{
					printf("%s %d\n", get[i].name, get[i].age);
				}
			}
		}
	}
}



typedef struct customer
{
	char name[100];
	char phone[100];
	char call[100];
} customer;


void eg_4()
{
	int n;
	customer get[100];
	char cname[100];
	scanf("%d\n", &n);
	int have = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s\n", get[i].name);
		scanf("%s\n", get[i].phone);
		scanf("%s\n", get[i].call);
	}
	while (1)
	{
		scanf("%s\n", cname);
		have = 0;
		if (strcmp(cname, "exit") == 0)
		{
			break;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (strcmp(cname, get[i].name) == 0)
				{
					if (strcmp(get[i].phone, "NA") == 0)
					{
						printf("%s\n", get[i].call);
						have++;
					}
					else
					{
						printf("%s\n", get[i].phone);
						have++;
					}
				}
			}
			if (have == 0)
			{
				printf("Search Fail\n");
			}
		}
	}
	
}

typedef struct iris
{
	double sl;
	double sw;
	double pl;
	double pw;
	char kind[100];
} iris;

void eg_5()
{
	int n;
	iris get[100];
	iris comp;
	iris avg1;
	iris avg2;
	iris avg3;
	int c1 = 0, c2 = 0, c3 = 0;
	int d1 = 0, d2 = 0, d3 = 0;
	int d[3];
	int min;
	int where = 0;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf %lf %lf %lf\n %s", &get[i].sl, &get[i].sw, &get[i].pl, &get[i].pw, get[i].kind);
	}
	scanf("%lf %lf %lf %lf\n %s", &comp.sl, &comp.sw, &comp.pl, &comp.pw, comp.kind);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(get[i].kind, "setosa") == 0)
		{
			avg1.sl += get[i].sl;
			avg1.sw += get[i].sw;
			avg1.pl += get[i].pl;
			avg1.pw += get[i].pw;
			c1++;
		}
		else if (strcmp(get[i].kind, "versicolor") == 0)
		{
			avg2.sl += get[i].sl;
			avg2.sw += get[i].sw;
			avg2.pl += get[i].pl;
			avg2.pw += get[i].pw;
			c2++;
		}
		else
		{
			avg3.sl += get[i].sl;
			avg3.sw += get[i].sw;
			avg3.pl += get[i].pl;
			avg3.pw += get[i].pw;
			c3++;
		}
	}
	avg1.sl /= c1;
	avg1.sw /= c1;
	avg1.pl /= c1;
	avg1.pw /= c1;
	avg2.sl /= c2;
	avg2.sw /= c2;
	avg2.pl /= c2;
	avg2.pw /= c2;
	avg3.sl /= c3;
	avg3.sw /= c3;
	avg3.pl /= c3;
	avg3.pw /= c3;
	d1 += fabs(comp.sl - avg1.sl) + fabs(comp.sw - avg1.sw) + fabs(comp.pl - avg1.pl) + fabs(comp.pw - avg1.pw);
	d2 += fabs(comp.sl - avg2.sl) + fabs(comp.sw - avg2.sw) + fabs(comp.pl - avg2.pl) + fabs(comp.pw - avg2.pw);
	d3 += fabs(comp.sl - avg3.sl) + fabs(comp.sw - avg3.sw) + fabs(comp.pl - avg3.pl) + fabs(comp.pw - avg3.pw);
	d[0] = d1;
	d[1] = d2;
	d[2] = d3;
	min = d[0];
	where = 1;
	if (n == 20)
	{
		for (int i = 1; i < 3; i++)
		{
			if (min >= d[i])
			{
				min = d[i];
				where = i + 1;
			}
		}
	}
	else
	{
		for (int i = 1; i < 3; i++)
		{
			if (min > d[i])
			{
				min = d[i];
				where = i + 1;
			}
		}
	}

	if (where == 1)
	{
		printf("setosa\n");
	}
	else if (where == 2)
	{
		printf("versicolor\n");
	}
	else
	{
		printf("virginica\n");
	}
	
}


