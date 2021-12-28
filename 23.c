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

typedef struct linked_list
{
	int data;
	struct linked_list* next;

}NODE;


NODE* insertHead(NODE* h, int input)
{
	NODE* node ,*curr;

	curr = (NODE *)calloc(1, sizeof(NODE));
	curr->next = NULL;
	curr->data = input;

	if (h == NULL)
	{
		h = curr;
	}
	else
	{
		node = h;
		while (node->next != NULL)
		{
			node = node->next;
		}
		node->next = curr;
	}
	return h;
}

void printeg_1(NODE* h , int r)
{
	NODE* p = NULL;
	p = h;
	int result = 0;
	while (p != NULL)
	{
		if (p->data == r)
		{
			result = 1;
			break;
		}
		p = p->next;
	}

	p ? printf("true") : printf("false");
	
}

void eg_1()
{
	int num = 0;
	NODE *h = NULL;
	int r = 0;
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
		{
			break;
		}
		h = insertHead(h, num);
	}
	scanf("%d", &r);

	printeg_1(h,r);
	
}

void increaseList(NODE* h)
{
	NODE* p = NULL;
	p = h;
	
	while (p != NULL)
	{
		p->data += 10;
		p = p->next;
	}

}
void printLise(NODE* head)
{
	NODE* p = NULL;
	p = head;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}


}

void eg_2()
{
	int num = 0;
	NODE* h = NULL;
	
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
		{
			break;
		}
		h = insertHead(h, num);
	}

	increaseList(h);
	printLise(h);

}
int findMIN(NODE* head)
{
	NODE* p = NULL;
	p = head;
	int min = p->data;

	while (p != NULL)
	{
		if (p->data < min)
		{
			min = p->data;
		}
		printf("%d ", p->data);
		p = p->next;
		
	}
	return min;
}

int findMAX(NODE* head)
{
	NODE* p = NULL;
	p = head;
	int max = p->data;

	while (p != NULL)
	{
		if (p->data > max)
		{
			max = p->data;
		}
		p = p->next;
	}
	return max;
}
void eg_3()
{
	int num = 0;
	NODE* h = NULL;
	int min=0, max = 0;
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
		{
			break;
		}
		h = insertHead(h, num);
	}

	min = findMIN(h);
	max = findMAX(h);
	printf("\n%d %d", min, max);
	
}
int sumlist(NODE* head)
{
	NODE* p = NULL;
	p = head;
	int total = 0;

	while (p != NULL)
	{
		total += p->data;
		p = p->next;
	}
	return total;
}

void eg_4()
{
	int num = 0;
	NODE* h = NULL;
	int t = 0;
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
		{
			break;
		}
		h = insertHead(h, num);
	}
	t = sumlist(h);
	printf("%d",t);

}
NODE* appendList(NODE* h1, NODE* h2)
{
	NODE* p = NULL;
	NODE* p2 =NULL;
	p = h1;

	while (p->next != NULL)
	{
		p = p->next;
	}
	
	p2 = h2;
	
	p->next = p2;
		
	
	return h1;                 
}
void traverseList(NODE* h) {
	NODE* p = NULL;
	p = h;

	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
void eg_5()
{
	int num = 0;
	NODE* h = NULL;
	NODE* h2 = NULL;
	NODE* h3 = NULL;
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
		{
			break;
		}
		h = insertHead(h, num);
	}
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
		{
			break;
		}
		h2 = insertHead(h2, num);
	}
	h3 = appendList(h, h2);
	traverseList(h3);
}


