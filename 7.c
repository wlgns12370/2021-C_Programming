#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4996)

void ed7_1();
void ed7_2();
void ed7_3();
void ed7_4();
void ed7_5();

int main(void) {

	ed7_1();

}

void ed7_1()
{
	int count = 0;
	int num = 0;
	int arr[100] = { 0 };

	while (1) {
		scanf("%d", &num);

		if (num == 0)
		{
			break;
		}
		else
		{
			arr[count] = num;
		}
		count++;
	}

	printf("%d\n", count);
	for (int i = count - 1; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}

}
void ed7_2()
{
	int count = 0;
	double num = 0.0, total = 0.0, avg = 0.0;
	double arr[50] = { 0.0, };

	while (1) {
		scanf("%lf", &num);

		if (num == 0.0)
		{
			break;
		}
		else
		{
			arr[count] = num;
		}
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		total += arr[i];
	}
	avg = total / count;
	printf("%.1lf\n", avg);
	for (int i = 0; i < count; i++)
	{
		if (arr[i] < avg)
		{
			printf("%.1lf ", arr[i]);
		}
	}
}
void ed7_3()
{
	int i;
	int j = 0;
	int arr[5] = { 0, };
	int arr2[5] = { 0, };

	for (j = 0; j < 5; j++)
	{
		scanf("%d", &arr[j]);
	}
	for (j = 0; j < 5; j++)
	{
		scanf("%d", &arr2[j]);
	}

	for (i = 0; i < 5; i++)
	{
		if (arr[i] != arr2[i])
		{
			printf("not same");
			break;
		}
	}
	if (i >= 5)
	{
		printf("same");
	}
}
void ed7_4()
{
	int i;
	int cnt = 0;
	int num = 0;
	int arr[100] = { 0, };
	int s = 0;


	while (1)
	{
		scanf("%d", &num);

		if (num == 0)
		{
			break;
		}
		else
		{
			arr[cnt] = num;
		}
		cnt++;
	}

	for (int i = 0; i < cnt; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if (arr[i] > arr[j])
			{
				s = arr[i];
				arr[i] = arr[j];
				arr[j] = s;
			}
		}

	}
	for (int i = 0; i < cnt; i++)
	{
		printf("%d ", arr[i]);
	}
}
void ed7_5()
{
	int i;
	int cnt = 0;
	int num = 0;
	int arr[100] = { 0, };
	int s = 0;


	while (1)
	{
		scanf("%d", &num);

		if (num == 0)
		{
			break;
		}
		else
		{
			arr[cnt] = num;
		}
		cnt++;
	}

	for (int i = 0; i < cnt; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if (arr[i] > arr[j])
			{
				s = arr[i];
				arr[i] = arr[j];
				arr[j] = s;
			}
		}

	}
	printf("%d %d", arr[cnt - 1], arr[0]);
}

