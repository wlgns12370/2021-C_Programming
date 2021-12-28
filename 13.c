#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define SIZE 100

void ed13_1();
int accumulateSum(int num);
void resetAccumulateSum();
void ed13_2();
void ed13_3();
void ed13_4();
void ed13_5();
void ed13_6();
int main()
{
	//ed13_1();
	//ed13_2();
	//ed13_3();
	//ed13_4();
	//ed13_5();


	ed13_6();
}

static int sum = 0;

int accumulateSum(int num) 
{
	extern sum;
	sum += num;
	return sum;
}

void resetAccumulateSum()
{
	extern sum;
	sum = 0;
}

void ed13_1() 
{
	int value, sum;
	while (1)
	{
		scanf("%d", &value);
		if (value < 0) {
			break;
		}
		else
		{
			sum = accumulateSum(value);
			printf("value : %d, sum : %d\n", value, sum);
		}
	}
	printf("Total sum : %d\n", accumulateSum(0));
}

void ed13_2() {
	int value;
	while (1)
	{
		scanf("%d", &value);
		if (value == 0)
		{
			break;
		}
		else if (value < 0) {
			printf("Total sum : %d\n", accumulateSum(0));
			resetAccumulateSum();
		}
		else {
			accumulateSum(value);
		}

	}
}

void ed13_3()
{
	char* token;
	char string[SIZE] = {"\0"};
	char result[SIZE][SIZE] = { "\0" };
	int ma[SIZE] = { 0 };
	int max1 = 0, max2 = 0,max3 = 0;
	int cnt = 0, i = 0;

	for (int s = 0; s < 3; s++)
	{
		gets(string);

		token = strtok(string, " ");

		while (token != NULL) {

			if (i % 4 != 0)
			{
				strcpy(result[i], token);
				ma[i] = atoi(token);
			}
			else
			{
				strcpy(result[i], token);
			}
			token = strtok(NULL, " ");
			i++;
		}
	}
	cnt++;

	for (int k = 0; k < i; k++)
	{
		if (k % 4 == 1) {
			if (max1 < ma[k])
			{
				max1 = ma[k];
			}
		}
		else if(k % 4 == 2)
		{
			if (max2 < ma[k])
			{
				max2 = ma[k];
			}
		}
		else if(k % 4 == 3)
		{
			if (max3 < ma[k])
			{
				max3 = ma[k];
			}
		}
	}
	for (int k = 0; k < i; k++)
	{
		if (k % 4 == 1) {
			if (max1 == atoi(result[k]))
			{
				strcat(result[k], "(A)");
				printf("%s ", result[k]);
			}
			else
			{
				strcat(result[k], "(-)");
				printf("%s ", result[k]);
			}
		}
		else if (k % 4 == 2)
		{
			if (max2 == atoi(result[k]))
			{
				strcat(result[k], "(A)");
				printf("%s ", result[k]);
			}
			else
			{
				strcat(result[k], "(-)");
				printf("%s ", result[k]);
			}
		}
		else if (k % 4 == 3)
		{
			if (max3 == atoi(result[k]))
			{
				strcat(result[k], "(A)");
				printf("%s\n", result[k]);
			}
			else
			{
				strcat(result[k], "(-)");
				printf("%s\n", result[k]);
			}
		}
		else {
			printf("%s ", result[k]);
		}
	}
}

void ed13_4() 
{
	char result[] = "abcdefghijklmnopqrstuvwxyz";
	char result2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int cnt[26] = { 0 };
	int cnt2[26] = { 0 };
	char string[SIZE] = "\0";

	gets(string);
	
	for (int i = 0; i < strlen(string); i++)
	{
		if ( 65 <= string[i] && string[i] <= 91) {
			
			for (int j = 0; j < 26; j++)
			{
				if (string[i] == result2[j])
				{

					//printf("%c %c\n", string[i], result2[j]);
					cnt2[j]++;
				}
				else {
					//printf("turtle");
				}
			}
		}
		else if(97 <= string[i] && string[i] <= 123)
		{

			for (int j = 0; j < 26; j++)
			{
				if (string[i] == result[j])
				{
					cnt[j]++;
				}
			}
			
		}
	}
	for (int i = 0; i < 26; i++)
		!cnt2[i] ? printf("") : printf("%c:%d\n", 'A' + i, cnt2[i]);
	for (int i = 0; i < 26; i++)
		!cnt[i] ? printf("") : printf("%c:%d\n", 'a' + i, cnt[i]);
	
	/*for (int i = 0; i < strlen(string); i++)
	{
		if (65 < string[i] && string[i] < 91) 
		{
			printf("%c:%d\n", string[i], cnt2[i]);
		}
		else if (97 < string[i] && string[i] < 123)
		{
			printf("%c:%d\n", string[i], cnt[i]);
		}
	}*/
	
}
void ed13_5()
{

	int result[SIZE] = { 0, };
	int result2[SIZE] = { 0, };
	int cnt = 0;
	int num = 0;

	while (1)
	{
		scanf("%d", &num);
		
		if (num == 0)
		{
			break;
		}

		else if (num > 0)
		{
			if (result[num] == 0)
			{
				result[num]++;
			}
			cnt = 0;
			for (int i = 0; i < 50; i++)
			{

				if (result[i] == 1)
				{
					cnt++;
				}
			}
			printf("array[%d] = { ", cnt);
			for (int i = 0; i < 50; i++)
			{
				if (result[i] == 1)
				{
					printf("%d ", i);
				}
			}
			printf("}\n");
		}

		else
		{
			num = abs(num);
			if (result[num] == 1)
			{
				result[num]--;
				cnt--;

			}
			cnt = 0;
			for (int i = 0; i < 50; i++)
			{

				if (result[i] == 1)
				{
					cnt++;
				}
			}
			printf("array[%d] = { ", cnt);
			for (int i = 0; i < 50; i++)
			{
				if (result[i] == 1)
				{
					printf("%d ", i);
				}
			}
			printf("}\n");
		}

		
	}
}

void ed13_6()
{
	
		int result[SIZE] = { 0 };
		int cnt = 0;
		int num = 0;
		int i = 0, check = 0, cnt2 = 0;

		while (1)
		{
			check = 0;
			scanf("%d", &num);
			if (num == 0)
			{
				break;
			}
			else if (num > 0)
			{
				for (i = 0; i < 50; i++)
				{
					if (num == result[i])
					{
						check = 1;
					}
				}
				if (check == 0)
				{
					result[cnt2] = num;
					cnt2++;
				}

			}
			else
			{
				num = abs(num);
				for (i = 0; i < 50; i++)
				{
					if (num == result[i])
					{
						break;
					}
				}
				result[i] = 0;

			}

			cnt = 0;
			for (int i = 0; i < 50; i++)
			{
				if (result[i] != 0)
				{
					cnt++;
				}
			}
			printf("array[%d] = { ", cnt);
			for (int i = 0; i < 50; i++)
			{
				if (result[i] != 0)
				{
					printf("%d ", result[i]);
				}
			}
			printf("}\n");
		}
	}








