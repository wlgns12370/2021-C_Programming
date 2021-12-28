#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4996)
//#include<stdlib.h>
#include<string.h>

#define SIZE 100

void ed11_1();
void ed11_2();
void ed11_3();
void ed11_4();
void ed11_4();

int main(void) {

	ed11_1();

}


void ed11_1()
{
	char name[50] = { "\0" };
	char math[50] = { "\0" };
	char ko[50] = { "\0" };
	char eng[50] = { "\0" };

	int math2 = 0;
	int ko2 = 0;
	int eng2 = 0;
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		scanf("%s %s %s %s", name, ko, eng, math);
		math2 = atoi(math);
		ko2 = atoi(ko);
		eng2 = atoi(eng);
		result = math2 + ko2 + eng2;
		printf("%s %s %s %s %d\n", name, ko, eng, math, result);

	}
}
void ed11_2()
{
	int cnt = 0;
	char ch[SIZE] = "\0";
	char ch2[SIZE] = "\0";
	gets(ch);
	gets(ch2);

	char* token;
	token = strtok(ch, " ,.");   // There are two delimiters here
	while (token != NULL) {
		//printf("%s %d\n", token,strlen(token));


		if (strstr(token, ch2) != NULL) {
			cnt++;
		}

		token = strtok(NULL, " ,.");
	}
	printf("%d\n", cnt);
}
void ed11_3()
{
	//int main(int argc ,char*argv[])
	int cnt = 0;
	int total = 0;
	for (int i = 1; i < argc; i++)
	{
		total += atoi(argv[i]);
		cnt++;
	}

	printf("%d %d\n", cnt, total);
}
void ed11_4()
{
	char* token;
	char string[SIZE];
	int total = 0, cnt = 0, i = 0;
	double result = 0.0;
	while (1)
	{
		gets(string);
		if (strcmp(string, "quit") == 0)
		{
			result = (double)total / cnt;
			printf("avg=%.1lf\n", result);
			break;
		}
		else {
			token = strtok(string, ",");

			while (token != NULL) {

				i++;
				if (i % 3 == 0)
				{
					total += atoi(token);
					printf("%s\n", token);
				}
				else {
					printf("%s\t", token);
				}
				token = strtok(NULL, ",");
			}
			cnt++;
		}
	}
	return 0;
}

