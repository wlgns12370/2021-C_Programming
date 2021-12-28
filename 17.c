#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define SIZE 100
#define MAXBUFSIZE 100

void eg_1();
void eg_2();
void eg_3();
void eg_4();
void eg_5();
void eg_6();

int main()
{
	//eg_1();
	//eg_2();
	//eg_3();
	//eg_4();
	//eg_5();
	eg_6();
}
struct MovieData
{
	char title[50];
	char master[50];
	int start;
	int time;
};

void eg_1() 
{
	struct MovieData p1;

	char Title[SIZE];
	char Director[SIZE];
	int year = 0;
	int running = 0;

	gets(Title);
	gets(Director);
	scanf("%d", &year);
	scanf("%d", &running);

	strcpy(p1.title,Title);
	strcpy(p1.master, Director);
	p1.start = year;
	p1.time = running;

	printf("Title : %s\n",p1.title);
	printf("Director : %s\n",p1.master);
	printf("Year : %d\n",p1.start);
	printf("RunningTime : %d\n",p1.time);

}

typedef struct
{
	int number;
	char name[SIZE];
	char adress[SIZE];
	int mon;
	double insen;
	double annual;

}employee;

void eg_2()
{	
	employee member[3];
	//printf("%d",sizeof(member));
	for (int i = 0; i < 3; i++)
	{
		scanf("%d\n", &member[i].number);
		gets(member[i].name);
		gets(member[i].adress);
		scanf("%d", &member[i].mon);
		scanf("%lf", &member[i].insen);
		member[i].annual = (double)member[i].mon * (12 + member[i].insen);
	}
	
	for (int i = 0; i < 3; i++)
	{
		printf("%d\t%s\t%s\t%d\t%.0lf%%\t%.1lf", member[i].number, member[i].name, member[i].adress, member[i].mon, member[i].insen * 100, member[i].annual);
		printf("\n");
	}
	
}
typedef struct
{
	int a;
	int b;

}TTosike;
int comTTo(TTosike n1, TTosike n2)
{
	if ((n1.a*n2.b) > (n2.a * n1.b))
	{
		return -1;
	}
	else if ((n1.a * n2.b) < (n2.a * n1.b))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void eg_3()
{
	TTosike arr[2];

	for (int i = 0; i < 2; i++)
	{
		scanf("%d%*c%d", &arr[i].a, &arr[i].b);
	}
	printf("%d", comTTo(arr[0], arr[1]));
}

typedef struct {
	double x;
	double y;
}point;

typedef struct {
	double slope;
	double yintercept;
}line;

double DDuk(point a,point b)
{
	line l;
	
	l.slope = (b.y - a.y) / (b.x - a.x);
	return l.slope;
}
double DDuk2(point a, point b)
{
	line l;
	
	l.slope = (b.y - a.y) / (b.x - a.x);
	l.yintercept = a.y - (l.slope * a.x);
	return l.yintercept;
}
void eg_4()
{
	point s[2];
	double slope = 0;
	double yintersect = 0;
	for (int i = 0; i < 2; i++)
	{
		scanf("%lf %lf", &s[i].x, &s[i].y);
	}

	slope = DDuk(s[0], s[1]);
	yintersect = DDuk2(s[0], s[1]);

	printf("%.1lf %.1lf", slope, yintersect);
	

}

//typedef struct {
//	char fname[100];
//	int calories;
//} Food;
//
//int total(Food arry[], int size) {
//	int i, sum = 0;
//	for (i = 0; i < size; i++) {
//		sum += arry[i].calories;
//	}
//	return sum;
//}
//
//void eg_5() {
//
//	Food food[100];
//	int i = 0;
//
//	while (1) {
//		scanf("%s", &food[i].fname);
//		if (strcmp(food[i].fname, "quit") == 0) {
//			break;
//		}
//		scanf("%d", &food[i].calories);
//		i++;
//	}
//	printf("%d", total(food, i));
//}


typedef struct
{
	char fname[SIZE];
	int calories;

}Food;


int totalCalories(Food ary[], int size)
{
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		total += ary[i].calories;
	}

	return total;
}


void eg_5()
{
	Food ex[SIZE];
	int cnt = 0;
	int result = 0;
	while (1)
	{
		gets(ex[cnt].fname);
		if (strcmp(ex[cnt].fname,"quit") == 0)
		{
			break;
		}
		scanf("%d\n", &ex[cnt].calories);

		cnt++;
	}
	result = totalCalories(ex, cnt);
	printf("%d", result);
}
typedef struct
{
	// 초기값 지정 불가능!
	char menu[SIZE];
	int price;

}Market;
// Market a = {"사과",30}; 이건 가능하다
// Market.a 이런식으로 하는것을 멤버참조!
void PrintM(Market a[] , int size)
{
	printf("현재 등록된 메뉴는\n");
	for (int i = 0; i < size; i++)
	{
		printf("%s : ", a[i].menu);
		printf("%d 원\n", a[i].price);
	}
	printf("입니다");
}

void eg_6()
{
	Market a[5];
	int size = 5;
	//printf("%d", sizeof(Market));

	for (int i = 0; i < size; i++)
	{
		printf("메뉴를 입력해주세요 : ");
		scanf("%s", &a[i].menu);
		printf("가격을 입력해주세요 : ");
		scanf("%d", &a[i].price);
	}

	PrintM(a, size);

}

//struct complex
//{
//	double real; // 실수
//	double img; // 허수
//
//};
//typedef struct complex complex