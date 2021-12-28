#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define SIZE 100

void eg_1();
void eg_2();
void eg_3();
void eg_4();
void eg_5();
int mySwap(int* a, int* b);
void print1DArray(int d[], int n);
void findSum(int data[], int n, int* sum);
void minMax(int data[], int n, int* min, int* max);
void sortWithoutDuplication(int ary[], int* size);

int main()
{
	//eg_1();
	//eg_2();
	//eg_3();
	//eg_4();
	eg_5();
}

void eg_1() {

	int x, y;
	scanf("%d %d", &x, &y);

	mySwap(&x, &y);
	printf("%d %d\n", x, y);
}
int mySwap(int* a, int* b)
{
	int temp = 0;
	temp = *b;
	*b = *a;
	*a = temp;
}

void eg_2()
{
	int ary[SIZE] = { 0 };
	int num = 0;
	int num2 = 0;

	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &num2);
		ary[i] = num2;
	}
	print1DArray(ary, num);
}

void print1DArray(int d[], int n)
{
	for (int i = n - 1; i < 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			printf("%d ", d[j]);
		}
		printf("\n");
	}
}
void eg_3()
{
	int data[SIZE] = { 0 };
	int num = 0;
	int sum = 0;
	int num2 = 0;

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &num2);
		data[i] = num2;
	}

	findSum(data, num, &sum);
	printf("%d", sum);

}
void findSum(int data[], int n, int* sum)
{
	for (int i = 0; i < n; i++)
	{
		*sum += data[i];
	}
}
void eg_4()
{
	int data[SIZE] = { 0 };
	int num = 0;
	int num2 = 0;

	int min, max = 0;

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &num2);
		data[i] = num2;
	}

	min = data[0];
	max = data[0];
	minMax(data, num, &min, &max);
	printf("%d %d", max, min);

}

void minMax(int data[], int n, int* min, int* max)
{
	for (int i = 0; i < n; i++)
	{
		if (data[i] < *min)
		{
			*min = data[i];
		}

		if (data[i] > *max)
		{
			*max = data[i];
		}
	}
}

void eg_5()
{
	int data[SIZE] = { 0 };
	int size = 10;
	int num2 = 0;


	for (int i = 0; i < size; i++)
	{
		scanf("%d", &num2);
		data[i] = num2;
	}

	sortWithoutDuplication(data, &size);

	for (int i = 0; i < size + 1; i++)
	{
		printf("%d ", data[i]);
	}
}

void sortWithoutDuplication(int ary[], int* size)
{
	int cnt[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		cnt[i] = 0;
	}
	int j = 0;
	int k = 0;
	for (int i = 0; i < *size; i++)
	{
		k = ary[i];
		cnt[k]++;
	}

	for (int i = 0; i < SIZE; i++)
	{
		if (cnt[i] > 0)
		{
			ary[j] = i;
			j++;
		}
	}

	*size = j - 1;
}