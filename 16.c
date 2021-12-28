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

void add_array(double source1[], double source2[], double target[], int num);
int sumAry1D(int ary[], int size);


void print1DArray2(int a[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}


int main()
{
	//eg_1();
	//eg_2();
	//eg_3();
	//eg_4();
	eg_5();
}


void print1DArray(int d[], int n)
{
	int i, k;

	for (i = 0; i < n; i++) {
		for (k = i; k < n; k++) {
			printf("%d ", d[k]);
		}
		printf("\n");
	}
}

void eg_1() {

	int n, m, i, j;
	int d[SIZE][SIZE] = { 0 };

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &d[i][j]);
		}
	}

	for (i = 0; i < n; i++) {
		print1DArray(d[i], m);
	}

}


int findMin1D(int ary[], int size, int initMin)
{
	int i, min;

	min = initMin;
	for (i = 0; i < size; i++)
	{
		if (ary[i] < min)
		{
			min = ary[i];
		}
	}
	return min;
}
void eg_2()
{
	int low, col;
	int ary[SIZE][SIZE] = { 0 };
	int num = 0;
	int k = 0;
	scanf("%d %d", &low, &col);

	for (int i = 0; i < low; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &num);
			ary[i][j] = num;
		}
	}
	k = ary[0][0];
	for (int i = 0; i < low; i++)
	{
		k = findMin1D(ary[i], col, k);
	}
	printf("%d", k);
}
void eg_3()
{
	int n, i;
	double arry[50] = { 0 };
	double arry1[50] = { 0 };
	double sum[50] = { 0 };

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%lf", &arry[i]);
	}

	for (i = 0; i < n; i++) {
		scanf("%lf", &arry1[i]);
	}

	add_array(arry, arry1, sum, n);

	for (i = 0; i < n; i++)
	{
		printf("%.2lf ", sum[i]);
	}
}
void add_array(double source1[], double source2[], double target[], int num)
{
	int i;

	for (i = 0; i < num; i++)
	{
		target[i] = source1[i] + source2[i];
	}
}
void eg_4()
{
	int n, m, i, j, sum = 0;
	int arry[50][50] = { 0 };

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &arry[i][j]);
		}
	}

	for (i = 0; i < n; i++) {
		sum += sumAry1D(arry[i], m);
		printf("%d\n", sumAry1D(arry[i], m));
	}
	printf("%d\n", sum);
}

int sumAry1D(int ary[], int size)
{
	int i, sum = 0;

	for (i = 0; i < size; i++)
		sum += ary[i];

	return sum;
}
void eg_5()
{
	int i, j;
	int* p[4] = { NULL, };
	int a[4][5];

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0; i < 4; i++) {
		if (i < 2)
			p[i] = a[2 * i + 1];
		else
			p[i] = a[2 * i - 4];
	}

	for (i = 0; i < 4; i++)
		print1DArray2(p[i], 5);
}