#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define SIZE 100

void ed1();
int sumArrayOne(int arry[], int size);
int sumMinOne(int arry[], int size);
void ed2();
void ed3();
void ed4();
void ed5();
void ed6();

int main()
{

	//ed1();
	//ed2();
	//ed3();
	//ed4();
	//ed5();
	ed6();
}

void ed1() {

	char code1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char code2[] = "hknopijxyzqfgmvwulastbcrde";

	char s[SIZE] = { "\0", };

	gets(s);

	for (int i = 0; i < strlen(s); i++)
	{
		for (int j = 0; j < strlen(code1); j++)
		{
			if (s[i] == code1[j]) {
				s[i] = code2[j];
			}
		}
	}

	printf("%s\n", s);
}

void ed2() {
	int arr[SIZE][SIZE] = { 0, };
	int num = 0;
	int k = 0;
	int sum = 0;
	int min[SIZE] = { 0, };
	int min2 = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++) {
			scanf("%d", &k);
			arr[i][j] = k;
		}
	}

	min2 = arr[0][0];
	for (int i = 0; i < num; i++)
	{
		sum += sumArrayOne(arr[i], num);
	}

	for (int i = 0; i < num; i++)
	{
		min[i] = sumMinOne(arr[i], num);

		if (min2 > min[i])
		{
			min2 = min[i];
		}
	}

	printf("%d %d", sum, min2);
}

int sumArrayOne(int arry[], int size) {

	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arry[i];
	}
	return sum;
}
int sumMinOne(int arry[], int size) {

	int min = arry[0];
	for (int i = 0; i < size; i++)
	{
		if (min > arry[i])
		{
			min = arry[i];
		}
	}
	return min;
}

void ed3() {
	int arr[SIZE][SIZE] = { 0, };
	int num = 4;
	int k = 0;


	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++) {
			scanf("%d", &k);
			arr[i][j] = k;
		}
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++) {
			printf("%4d", arr[j][i]);
		}
		printf("\n");
	}
}

void ed4() {
	int arr[SIZE][SIZE] = { 0, };
	int num = 4;
	int k = 0;
	int sum = 0;


	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++) {
			scanf("%d", &k);
			arr[i][j] = k;
		}
	}

	for (int i = 0; i < num; i++)
	{
		int row = 0, col = 0;
		for (int j = 0; j < num; j++) {
			row += arr[i][j];
			col += arr[j][i];
		}
		arr[i][num] = row;
		arr[num][i] = col;
		sum += row;
	}

	arr[4][4] = sum;

	for (int i = 0; i < num + 1; i++)
	{
		for (int j = 0; j < num + 1; j++) {

			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
}


void ed5() {
	int arr[SIZE][SIZE] = { 0, };
	int arr2[SIZE][SIZE] = { 0, };
	int num = 3;
	int k = 0;
	int sum = 0;
	int result = 1;


	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++) {
			scanf("%d", &k);
			arr[i][j] = k;
		}
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++) {
			scanf("%d", &k);
			arr2[i][j] = k;
		}
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (arr[i][j] != arr2[i][j])
			{
				result = 0;
				break;
			}
		}
	}

	/*if (result)
	{
		printf("same");
	}
	else {
		printf("not same");
	}*/

	result ? printf("same") : printf("not same");
}

void ed6() {

	char s[SIZE][SIZE] = { "\0", };
	char s2[SIZE] = { "\0" };
	int c = 0;
	while (1) {

		scanf("%s", s2);

		if (strcmp(s2, "quit") == 0)
		{
			break;
		}
		else
		{
			strcat(s[c], s2);
			c++;
		}
	}


	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c - 1; j++)
		{
			char temp[SIZE] = { "\0" };
			if (strcmp(s[j], s[j + 1]) > 0)
			{

				strcpy(temp, s[j + 1]);
				strcpy(s[j + 1], s[j]);
				strcpy(s[j], temp);
			}
		}
	}

	for (int i = 0; i < c; i++)
	{
		printf("%s\n", s[i]);
	}
}