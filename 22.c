#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<time.h>

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
	//eg_3();
	//eg_4();
	eg_5();
}

void eg_1()
{
	FILE* fp;
	int* ch;
	char name[SIZE] = { "\0" };
	double avg = 0;
	int total = 0;
	int n = 0;
	int s = 0;
	int random = 0;
	scanf("%s", name);

	fp = fopen(name, "r");
	
	fscanf(fp, "%d %d", &n, &s);
	
	srand(s);
	ch = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		random = rand() % 10;
		ch[i] = random;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ch[i]);
		total += ch[i];
	}
	avg = (double)total / n;
	printf("\n%.1lf", avg);
	
	fclose(fp);


}



void eg_2()
{

	FILE* fp;
	int* ch2;
	char name[SIZE] = { "\0" };
	int min = 0;
	int num = 0;
	int n = 0;
		
	scanf("%s", name);
	scanf("%d", &n);
	
	fp = fopen(name, "w");
	ch2 = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		ch2[i] = num;
	}
	min = ch2[0];

	for (int i = 0; i < n; i++)
	{
		if (min > ch2[i])
		{
			min = ch2[i];
		}
	}
	
	fprintf(fp, "%d", min);
	fclose(fp);
}

void eg_3()
{
	FILE* fp;
	int** ch2;
	char name[SIZE] = { "\0" };
	int min = 0;
	int num = 0;
	int n = 0;

	scanf("%s", name);
	
	fp = fopen(name, "r");
	fscanf(fp,"%d", &n);

	ch2 = (int**)calloc(n, sizeof(int*));

	for (int i = 0; i < n; i++)
	{
		ch2[i] = (int*)calloc(n, sizeof(int));
		for (int j = 0; j < n; j++)
		{
			fscanf(fp, "%d", &ch2[i][j]);
		}
	}

	min = ch2[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (min > ch2[i][j])
			{
				min = ch2[i][j];
			}
		}
	}
	
	printf("%d", min);

	fclose(fp);

	


}
typedef struct
{
	char name[20];
	double midterm;
	double final;
	double quiz;

}student;

typedef struct
{
	int no;
	char name[20];
	double midterm;
	double final;
	double quiz;
	double total;

}score;

void eg_4()
{
	FILE* fp;
	FILE* fp2;
	student* arr;
	score* re;

	int num_student = 0;

	char name[SIZE] = { "\0" };
	char name2[SIZE] = { "\0" };
	int min = 0;
	int num = 0;
	int n = 0;

	scanf("%s", name);
	scanf("%s", name2);

	fp = fopen(name, "rb");
	fp2 = fopen(name2, "w");
	fread(&n,sizeof(int),1,fp);
	arr = (student*)calloc(n, sizeof(student));
	re = (score*)calloc(n, sizeof(score));

	fread(arr, sizeof(student), n, fp);
	for (int i = 0; i < n; i++)
	{
		re[i].no = i + 1;
		strcpy(re[i].name,arr[i].name);
		re[i].midterm = arr[i].midterm;
		re[i].final = arr[i].final;
		re[i].quiz = arr[i].quiz;
		re[i].total = re[i].midterm + re[i].final + re[i].quiz;
	}

	for (int i = 0; i < n; i++)
	{
		fprintf(fp2, "%d %s %.1lf %.1lf %.1lf %.1lf\n", re[i].no, re[i].name, re[i].midterm, re[i].final, re[i].quiz, re[i].total);	
	}

	fclose(fp);
	fclose(fp2);
	free(re);
	free(arr);
}

typedef struct linked_list
{
	double data;
	struct linked_list* next;
}NODE;

NODE* insertHead(NODE* h, double data)
{
	NODE* node;
	node = (NODE*)malloc(sizeof(NODE));
	node->data = data;

	node->next = h;
	h = node;

	return h;
}

void printMinMax(NODE* h)
{
	NODE* p;
	p = h;

	double min = p->data;
	double max = p->data;

	p = p->next;

	while (p != NULL)
	{
		if (p->data < min) {
			min = p->data;
		}

		if (p->data > max) {
			max = p->data;
		}
		p = p->next;
	}
	printf("min:%.1lf\n", min);
	printf("max:%.1lf\n", max);
}

void eg_5()
{
	int i, n;
	double data;
	NODE* header = NULL;
	scanf("%d", &n);
	for ( i = 0; i < n; i++)
	{
		scanf("%lf", &data);
		header = insertHead(header, data);
	}
	printMinMax(header);
}


