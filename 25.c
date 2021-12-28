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
	eg_4();
	//eg_5();
}

//int transNumber(char[]);
//
//int transNumber(char s[])
//{
//	int total = 0;
//	for (int i = 0; i < strlen(s); i++)
//	{
//		pritnf("%c", s[i]);
//		if (s[i] > '0' && s[i] < '9')
//		{
//			total += atoi(s[i]);
//		}
//	}
//	return total;
//}
//
//void eg_1() {
//	char str[SIZE];
//	int i, sum = 0;
//	
//	gets(str);
//	sum = transNumber(str);
//	printf("%s\nSum = %d\n", str, sum);
//}

struct linked_list
{
	int data;
	struct linked_list* next;

};
typedef struct linked_list NODE;

NODE* insertSorted(NODE* h, int data)
{
	NODE* p, * q;
	NODE* node = (NODE*)calloc(1, sizeof(NODE));

	node->data = data;

	p = h;
	q = h;
	while (p != NULL)
	{
		if (p->data > data)
			break;
		if (p->data == data) // 2번 문제
		{
			return h;
		}
		q = p; 
		p = p->next;
	}

	if (p == h)
	{
		node->next = h;
		h = node;
	}
	else
	{
		node->next = p;
		q->next = node;
	}

	return h;

}

//void append(NODE*node,)

void PrintNode(NODE* h)
{
	NODE* p = (NODE*)calloc(1, sizeof(NODE));

	p = h;
	
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

void eg_1() 
{
	int i, data;
	NODE* header = NULL;

	while(1)
	{
		scanf("%d", &data);

		if (data == 0)
		{
			break;
		}

		header = insertSorted(header, data);
	}
	PrintNode(header);
}
//
//struct linked_list
//{
//	char *name;
//	struct linked_list* next;
//
//};
//typedef struct linked_list NODE;
//typedef NODE* LINK;
//
//
//LINK Cappend(LINK head,char* name)
//{
//	LINK t, cur;
//	cur = (LINK)calloc(1, sizeof(LINK));
//	
//	cur->name = (char*)calloc(sizeof(name) + 1, sizeof(char));
//	//+1 NULL 문자
//
//	strcpy(cur->name, name);
//	
//	if (head == NULL)
//	{
//		head = cur;
//	}
//	else
//	{
//		t = head;
//		while (t->next != (LINK*)NULL)
//		{
//			t = t->next;
//		}
//		t->next = cur;
//	}
//	return head;
//
//}
//void printNODE(LINK a)
//{
//	LINK d;
//	d = a;
//
//	while (d->next != NULL)
//	{
//		printf("%s", d->name);
//		d = d->next;
//	}
//}
//void eg_2()
//{
//	LINK a = (LINK)calloc(1, sizeof(LINK));
//	a = NULL;
//	char ss[SIZE] = { "\0" };
//	int n = 0;
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s", ss);
//		printf("%s\n", ss);
//		a = Cappend(a,ss);
//	}
//	printNODE(a);
//
//}

void eg_2()
{
	int i, data;
	NODE* header = NULL;

	while (1)
	{
		scanf("%d", &data);

		if (data == 0)
		{
			break;
		}

		header = insertSorted(header, data);
	}
	PrintNode(header);
}
NODE* deleteNode(NODE* h, int data)
{
	NODE* p, * q;
	NODE* node = (NODE*)calloc(1, sizeof(NODE));

	node->data = data;

	p = h;
	q = h;
	while (p != NULL)
	{
		if (p->data == data) // 2번 문제
		{
			break;
		}

		if (p->data > data)
			break;
		
		q = p;
		p = p->next;
	}
	if (p == NULL)
	{
		return h;
	}
	else if (p == h)
	{
		h = h->next;
		free(p);
		return h;
	}

	else
	{
		q->next = p->next;;
		free(p);
		return h;
	}
}

void eg_3()
{
	int i, data;
	NODE* header = NULL;
	int deldata = 0;

	while (1)
	{
		scanf("%d", &data);

		if (data == 0)
		{
			break;
		}

		header = insertSorted(header, data);
	}

	scanf("%d",&data);
	header = deleteNode(header, data);
	PrintNode(header);
}

NODE* deleteNode2(NODE* h, NODE* d)
{
	NODE* p, * q,*r;
	NODE* node = (NODE*)calloc(1, sizeof(NODE));
	int result = 0;

	r = d;
	
	while (r != NULL)
	{
		p = h;
		q = h;

		while (p != NULL)
		{
			if (p->data >= r->data) // 2번 문제
			{
				break;
			}

			q = p;
			p = p->next;
		}
		if (p == NULL)
		{
			continue;
		}
		else if (p == h)
		{
			h = h->next;
			free(p);
		}
	

		else
		{
			q->next = p->next;;
			free(p);
		}

		r = r->next;
	}
	return h;
}

void eg_4()
{
	int i, data;
	NODE* header = NULL;
	NODE* del = NULL;


	while (1)
	{
		scanf("%d", &data);

		if (data == 0)
		{
			break;
		}

		header = insertSorted (header, data);
	}
	while (1)
	{
		scanf("%d", &data);

		if (data == 0)
		{
			break;
		}

		del = insertSorted(del, data);
	}

	header = deleteNode2(header, del);
	PrintNode(header);
	
}
void eg_5()
{
}


