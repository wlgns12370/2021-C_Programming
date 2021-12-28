#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4996)

#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 200

void ed10_1();
void ed10_2();
void ed10_3();
void ed10_4();
void ed10_5();

int main(void) {

	ed10_1();

}

void ed10_1()
{
	char str[SIZE];
	char temp[SIZE];
	char* ptoken;
	int i, count = 0;

	gets(str);

	ptoken = strtok(str, " ");

	while (ptoken != NULL) {

		for (i = strlen(ptoken) - 1; ptoken[i] != NULL && i >= 0; i--) {
			printf("%c", ptoken[i]);
		}
		printf(" ");
		ptoken = strtok(NULL, " ");

	}

}
void ed10_2()
{
	char str[SIZE];
	char* ptoken;
	int num = 0;

	gets(str);

	printf("%s+15=%d\n", str, (atoi(str) + 15));
}
void ed10_3()
{
	char* ptoken;
	int num = 0, num2;
	char ch[SIZE];
	char ch2[SIZE];

	while (1) {

		gets(ch);
		num = strlen(ch);
		if (num < 5 || num > 10)
		{
			printf("Retry\n");
			continue;
		}
		else {
			gets(ch2);
			num2 = strlen(ch);

			if (strcmp(ch, ch2) != 0)
			{
				printf("Retry\n");
				continue;
			}
			else
			{
				printf("Done\n");
				break;
			}
		}
	}
}
void ed10_4()
{
	int cnt = 0;
	char ch[SIZE] = "\0";
	char ch2[SIZE] = "\0";
	char ch3[SIZE] = "\0";

	gets(ch);
	gets(ch2);
	gets(ch3);

	for (int i = 0; i < strlen(ch); i++)
	{
		if (ispunct(ch[i]) != 0) {
			cnt++;
		}
		else
		{
			continue;
		}
	}
	for (int i = 0; i < strlen(ch2); i++)
	{
		if (ispunct(ch2[i]) != 0) {
			cnt++;
		}
		else
		{
			continue;
		}
	}
	for (int i = 0; i < strlen(ch3); i++)
	{
		if (ispunct(ch3[i]) != 0) {
			cnt++;
		}
		else
		{
			continue;
		}
	}
	printf("%d ", cnt);

	for (int i = 0; i < strlen(ch); i++)
	{
		if (ispunct(ch[i]) != 0) {
			printf("%c", ch[i]);
		}
		else
		{
			continue;
		}
	}
	for (int i = 0; i < strlen(ch2); i++)
	{
		if (ispunct(ch2[i]) != 0) {
			printf("%c", ch2[i]);
		}
		else
		{
			continue;
		}
	}
	for (int i = 0; i < strlen(ch3); i++)
	{
		if (ispunct(ch3[i]) != 0) {
			printf("%c", ch3[i]);
		}
		else
		{
			continue;
		}
	}
}
void ed10_5()
{

	char input[SIZE];
	char input2[SIZE];
	char input3[SIZE];
	char delimiter[] = " .,!\t\n";
	char* ptoken = "\0";
	char* ptoken2 = "\0";
	int maxlen = 0, cnt = 0;

	gets(input);
	gets(input2);
	gets(input3);
	strcat(input, " ");
	strcat(input, input2);
	strcat(input, " ");
	strcat(input, input3);

	ptoken = strtok(input, delimiter);
	while (ptoken != NULL) {
		cnt++;
		if (maxlen < strlen(ptoken)) {
			maxlen = strlen(ptoken);
			ptoken2 = ptoken;
		}
		ptoken = strtok(NULL, delimiter);
	}
	printf("%d ", cnt);
	printf("%s", ptoken2);
}

