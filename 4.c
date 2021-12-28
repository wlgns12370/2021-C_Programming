#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4996)


void ed4_1();
void ed4_2();
void ed4_3();

int main(void)
{
	void ed3_1();
	void ed3_2();
	
}

void ed4_1()
{
	int num = 75;
	int test1 = 0b100000;
	int test2 = 0b11100;
	int test3 = ~(0b101);
	int test4 = 0b1100;

	printf("%d\n", num & test1);
	printf("%d\n", num | test2);
	printf("%d\n", num & test3);
	printf("%d\n", num ^ test4);


}

void ed4_2()
{
	int x = 0;
	int y = 0;
	scanf("%d %d", &x, &y);

	if (x > 0 && y > 0)
	{
		printf("1");
	}
	else if (x > 0 && y < 0)
	{
		printf("4");

	}
	else if (x < 0 && y < 0)
	{
		printf("3");

	}
	else if (x < 0 && y > 0)
	{
		printf("2");

	}

}
void ed4_3()
{

}