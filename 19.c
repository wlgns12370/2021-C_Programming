#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning (disable:4996)
#define SIZE 100
#define MAXBUFSIZE 100

void eg_1();
void eg_2();
void eg_3();
void eg_4();
void eg_5();


int main()
{
	//eg_1();
	//eg_2();
	eg_3();
	//eg_4();
	//eg_5();
	
}

void eg_1()
{
	FILE* fp;
	char ch[SIZE] = {"\0"};
	char s = "\0";

	gets(ch);
	fp = fopen(ch, "r");

	if (fp == NULL)
	{
		printf("파일이 열리지 않습니다.");
		exit(0);
	}
	while ((s = fgetc(fp)) != EOF)
	{
		putchar(s);
	}
	fclose(fp);
}
void eg_2()
{
	FILE* fp_in;
	FILE* fp_out;
	char ich[SIZE/2] = { "\0" };
	char rch[SIZE/2] = { "\0" };
	char result[SIZE] = { "\0" };
	int i = 0;
	char st, ch;

	scanf("%s", ich);
	scanf("%s", rch);

	fp_in = fopen(ich, "r");
	fp_out = fopen(rch, "w");
	

	while ((st = fgetc(fp_in)) != EOF) //문자열 받을때
	{
		ch = toupper(st);
		putchar(ch);
		fprintf(fp_out, "%c", ch);
	}

	fclose(fp_in);
	fclose(fp_out);
}

void eg_3()
{
	FILE* f_in;
	char f_name[SIZE / 2];
	int i = 0;
	int cnt = 0;
	int score = 0;
	char ee[SIZE] = { "\0" };
	int num[SIZE / 2] = {0,};

	scanf("%s", f_name);
	f_in = fopen(f_name, "r");


	if (f_in == NULL)
	{
		printf("파일이 없습니다.\n");
		exit(0);
	}

	while (fscanf(f_in, "%s : %d",&ee,&score ) != EOF)
	{
		if (score >= 90)
		{
			num[i] = score;
			i++;
			cnt++;
		}
	}

	printf("%d\n", cnt);
	for (int k = 0; k < cnt; k++)
	{
		printf("%d\n", num[k]);
	}
	fclose(f_in);
}
void eg_4()
{
	FILE* fp_in;
	FILE* fp_out;
	char ich[SIZE / 2] = { "\0" };
	char rch[SIZE / 2] = { "\0" };
	char result[SIZE] = { "\0" };
	int i = 0;
	char st;

	scanf("%s", ich);
	scanf("%s", rch);

	fp_in = fopen(ich, "r");
	fp_out = fopen(rch, "w");


	while ((st = fgetc(fp_in)) != EOF) //문자열 받을때
	{
		if (st >= '0' && st <= '9')
		{
			fprintf(fp_out, "%c", st);
		}
		
	}

	fclose(fp_in);
	fclose(fp_out);
}


void eg_5()
{
	FILE* fp_in;
	FILE* fp_out;
	char input[50];
	char name[30];
	int score1, score2, score3;
	double avg;

	scanf("%s", input);

	fp_in = fopen(input, "r");

	while ((fscanf(fp_in, "%s", name)) != EOF)
	{
		fscanf(fp_in, "%d %d %d", &score1, &score2, &score3);
		avg = (double)(score1 + score2 + score3) / 3;
		printf("%s\t%d\t%d\t%d\t%.2lf\n", name, score1, score2, score3, avg);
	}

	fclose(fp_in);
}


