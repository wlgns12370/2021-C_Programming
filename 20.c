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
void eg_6();

int main()
{
	//eg_1();
	//eg_2();
	eg_3();
	//eg_4();
	//eg_5();
	//eg_6();
}
typedef struct
{
	int std_id;
	char name[30];
	double score[3];
	double total;

}Student;


void eg_1()
{
	Student list[SIZE / 2] = { 0, };
	FILE* fp_i;
	FILE* fp_o;
	char f_in[SIZE / 2] = { "\0" };
	char f_out[SIZE / 2] = { "\0" };
	int i = 0;
	scanf("%s", f_in);
	scanf("%s", f_out);

	fp_i = fopen(f_in, "r");
	fp_o = fopen(f_out, "wb+");

	while (fscanf(fp_i, "%d\t%s\t%lf\t%lf\t%lf", &list[i].std_id, list[i].name, &list[i].score[0], &list[i].score[1], &list[i].score[2]) != EOF)
	{
		list[i].total = list[i].score[0] + list[i].score[1] + list[i].score[2];
		printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", list[i].std_id, list[i].name, list[i].score[0], list[i].score[1], list[i].score[2], list[i].total);
		fwrite(list + i, sizeof(Student), 1, fp_o);
		// list + i == &list[i]
		i++;
	}

	rewind(fp_o);
	fseek(fp_o, 0, SEEK_SET);
	fseek(fp_o, sizeof(Student)*2, SEEK_SET);
	fwrite(list, sizeof(Student), i, fp_o);

	fclose(fp_i);
	fclose(fp_o);

}
void eg_2()
{
	Student list[SIZE / 2] = { 0, };
	FILE* fp_i;
	FILE* fp_o;
	char f_in[SIZE / 2] = { "\0" };
	char f_out[SIZE / 2] = { "\0" };
	char p_in[SIZE / 2] = { "\0" };
	int i = 0;
	scanf("%s", f_in);
	scanf("%s", f_out);
	scanf("%s", p_in);

	fp_i = fopen(f_in, "rb");
	fp_o = fopen(f_out, "wb");

	while (fread(&list[i], sizeof(Student), 1, fp_i))
	{
		list[i].total = list[i].score[0] + list[i].score[1] + list[i].score[2];
		i++;
	}
	int p = 0;
	for (int j = 0; j < i; j++)
	{
		if (strcmp(list[j].name, p_in) == 0)
		{
			printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", list[j].std_id, list[j].name, list[j].score[0], list[j].score[1], list[j].score[2], list[j].total);
			scanf("%lf %lf %lf", &list[j].score[0], &list[j].score[1], &list[j].score[2]);
			list[j].total = list[j].score[0] + list[j].score[1] + list[j].score[2];
			p = j;
		}
	}

	for (int j = 0; j < i; j++)
	{
		printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", list[j].std_id, list[j].name, list[j].score[0], list[j].score[1], list[j].score[2], list[j].total);
		//fwrite(&list[j], sizeof(Student), 1, fp_o);
	}

	fwrite(&list, sizeof(Student), i, fp_o); // À§¿¡²¨¶û ¶È°°À½
	fseek(fp_o, sizeof(Student) * p, SEEK_SET);
	fwrite(&list[p], sizeof(Student), 1, fp_o);

	fclose(fp_i);
	fclose(fp_o);


}
struct account
{
	int accNum;
	char name[30];
	double balance;

};
void eg_3()
{

	struct account a[100] = { 0 };
	FILE* fp;
	char name[10];
	int count = 0, i = 0, num;
	double money, total;

	fp = fopen("bank.bin", "ab+");

	while (fread(&a[count], sizeof(struct account), 1, fp) != 0) {
		count++;
	}

	fclose(fp);

	while (1) {
		scanf("%d", &num);
		if (num == 1) {
			while (1) {
				scanf("%d", &a[count].accNum);
				if (a[count].accNum == -1)
					break;
				scanf("%s", a[count].name);
				scanf("%lf", &a[count].balance);
				count++;
			}
		}
		if (num == 2) {
			scanf("%s", name);
			for (int j = 0; j < count; j++) {
				if (strcmp(name, a[j].name) == 0) {
					printf("%d %s %.2lf\n", a[j].accNum, a[j].name, a[j].balance);
				}
			}
		}

		if (num == 3) {
			scanf("%s %lf", name, &money);
			for (int j = 0; j < count; j++) {
				if (strcmp(name, a[j].name) == 0) {
					a[j].balance += money;
					printf("%d %s %.2lf\n", a[j].accNum, a[j].name, a[j].balance);
				}
			}
		}
		if (num == 4) {
			scanf("%s %lf", name, &money);
			for (int j = 0; j < count; j++) {
				if (strcmp(name, a[j].name) == 0) {
					a[j].balance -= money;
					printf("%d %s %.2lf\n", a[j].accNum, a[j].name, a[j].balance);
				}
			}
		}
		if (num == 5) {
			total = 0;
			for (int j = 0; j < count; j++) {
				total += a[j].balance;
			}
			printf("Total=%.2lf\n", total);
			for (int j = 0; j < count; j++) {
				printf("%d %s %.2lf\n", a[j].accNum, a[j].name, a[j].balance);
			}
		}
		if (num == 6) {
			fp = fopen("bank.bin", "wb");
			for (int k = 0; k < count; k++) {
				fwrite(&a[k], sizeof(struct account), 1, fp);
			}
			fclose(fp);
			break;
		}
	}
}