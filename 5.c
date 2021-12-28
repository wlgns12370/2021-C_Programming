#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4996)

void ed5_1();
void ed5_2();
void ed5_3();
void ed5_4();

int main(void) {

	ed5_1();

}

void ed5_1()
{
	int num = 0;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
	{
		if (i % 3 == 0) {
			continue;
		}
		else
		{
			if (i % 2 != 0)
			{
				printf("%d ", i);
			}
		}

	}

}
void ed5_2()
{
	int num = 0;
	int num2 = 0;
	int max = 0;
	int total = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &num2);

		if (max < num2)
		{
			max = num2;
		}
		total += num2;
	}

	printf("%d\n", total);
	printf("%d", max);
}
void ed5_3()
{
	int num = 0;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
	{
		for (int k = 1; k <= i; k++)
		{
			printf("%d", k);
		}
		for (int j = 1; j <= num - i; j++) {
			printf("*");
		}
		printf("\n");
	}
}
void ed5_4()
{
	int num = 0;
	double m1 = 0.09;
	double t = 0;
	double sum = 0;
	int case1 = 1000;
	int case2 = 3000;
	int case3 = 4000;

	scanf("%d", &num);

	if (0 <= num && num <= case1) {
		t = num * m1;
		printf("%d * %.2lf = %.0lf\n", num, m1, t);
		printf("= %.0lf", t);
	}
	else if (num <= case2 + case1) {
		num -= case1;
		printf("%d * %.2lf = %d\n", case1, m1, 90);
		t = num * m1 * 2;
		sum = 90 + t;
		printf("%d * %.2lf = %.0lf\n", num, m1 * 2, t);
		printf("= %.0lf", sum);

	}
	else if (num <= case3 + case2 + case1) {

		num -= (case1 + case2);
		printf("%d * %.2lf = %d\n", case1, m1, 90);
		printf("%d * %.2lf = %d\n", case2, m1 * 2, 540);
		t = num * m1 * 3;
		sum = 540 + 90 + t;

		printf("%d * %.2lf = %.0lf\n", num, m1 * 3, t);
		printf("= %.0lf\n", sum);

	}
	else
	{
		num -= (case1 + case2 + case3);
		printf("%d * %.2lf = %d\n", case1, m1, 90);
		printf("%d * %.2lf = %d\n", case2, m1 * 2, 540);
		printf("%d * %.2lf = %d\n", case3, m1 * 3, 1080);
		t = num * m1 * 4;
		sum = 1080 + 540 + 90 + t;
		printf("%d * %.2lf = %.0lf\n", num, m1 * 4, t);
		printf("= %.0lf", sum);
	}
}

