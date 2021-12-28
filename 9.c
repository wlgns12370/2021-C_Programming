#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4996)

double ed9_1();
void ed9_2();
void ed9_3();
void ed9_4();
void ed9_5();

int cnt[10] = { 0, };

int checkLastDigit(int arr[], int size, int num) {
	int number = 0, count = 0;
	for (int i = 0; i < size; i++)
	{
		number = arr[i] % 10;
		if (num == number)
		{
			count++;
		}
	}
	return count;
}

long int scoreToGrade(int weight, int velocity) {
	int KE = 0;
	KE = weight * pow(velocity, 2) / 2;
	return KE;
}

char scoreToGrade(int score) {
	if (score >= 90)
	{
		return 'A';
	}
	else if (score >= 80)
	{
		return 'B';
	}
	else if (score >= 70)
	{
		return 'C';
	}
	else if (score >= 60)
	{
		return 'D';
	}
	else if (score < 60)
	{
		return 'F';
	}
}

double findHighest(double d[], int n) {

	double max;
	max = d[0];
	for (int i = 0; i < n; i++)
	{
		if (max <= d[i])
		{
			max = d[i];
		}
	}
	return max;
}

double findLowest(double d[], int n) {
	double min;
	min = d[0];
	for (int i = 0; i < n; i++)
	{
		if (min >= d[i])
		{
			min = d[i];
		}
	}
	return min;

}

void calcScore(double d[], int n) {
	double total = 0;
	double max = 0, min = 0;
	double avg = 0;

	for (int i = 0; i < n; i++)
	{
		total += d[i];
	}
	max = findHighest(d, n);
	min = findLowest(d, n);

	total = total - max - min;
	avg = total / (n - 2);

	printf("%.2lf", avg);

}

double ed9_1() {
	int n = 0;
	double num = 0;
	double a[100] = { 0, };
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &num);
		if (num <= 10.0 && num >= 0.0)
		{
			a[i] = num;
		}
		else {
			i--;
		}
	}
	calcScore(a, n);
}

int main(void) {

	ed9_1();

}


void ed9_2()
{
	int grade = 0;
	char result = 'A';
	while (1)
	{
		scanf("%d", &grade);
		if (grade == -1)
		{
			break;
		}
		else
		{
			result = scoreToGrade(grade);
			printf("%c\n", result);
		}

	}

}
void ed9_3()
{
	int weight = 0, velocity = 0;
	long int result = 0;
	scanf("%d %d", &weight, &velocity);

	result = scoreToGrade(weight, velocity);
	printf("%ld", result);
}
void ed9_4()
{
	int num1 = 0, num2 = 0, result = 0;
	int a[100] = { 0, };
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &num2);
		a[i] = num2;
	}



	for (int k = 0; k < 10; k++)
	{
		num2 = k;
		printf("%d %d\n", k, checkLastDigit(a, num1, num2));
	}
}
void ed9_5()
{
	/*double findHighest(double d[], int n) {

		double max;
		max = d[0];
		for (int i = 0; i < n; i++)
		{
			if (max <= d[i])
			{
				max = d[i];
			}
		}
		return max;
	}

	double findLowest(double d[], int n) {
		double min;
		min = d[0];
		for (int i = 0; i < n; i++)
		{
			if (min >= d[i])
			{
				min = d[i];
			}
		}
		return min;

	}

	void calcScore(double d[], int n) {
		double total = 0;
		double max = 0, min = 0;
		double avg = 0;

		for (int i = 0; i < n; i++)
		{
			total += d[i];
		}
		max = findHighest(d, n);
		min = findLowest(d, n);

		total = total - max - min;
		avg = total / (n - 2);

		printf("%.2lf", avg);

	}

	double getJudgeData() {
		int n = 0;
		double num = 0;
		double a[100] = { 0, };
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &num);
			if (num <= 10.0 && num >= 0.0)
			{
				a[i] = num;
			}
			else {
				i--;
			}
		}
		calcScore(a, n);
	}*/

}

