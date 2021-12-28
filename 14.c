#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define SIZE 100

void eg_1();
void eg_2();
void eg_3();
void eg_4();

int GCD(int a, int b);
void reverse(int n);
int checkTwins(int a);
void printBin(int a);
void printFloatBin(double a);
int count = 0;


int main()
{
	//eg_1();
	eg_2();
	//eg_3();
	//eg_4();
}

void eg_1() {

	int a, b;

	while (1) {

		scanf("%d %d", &a, &b);

		if (a == 0 && b == 0)
			break;

		printf("%d\n", GCD(a, b));
	}
}

int GCD(int a, int b) {

	if (a % b == 0)
		return b;

	else
		GCD(b, a % b);

}

void eg_2()
{
	int a;

	scanf("%d", &a);

	reverse(a);
}

void reverse(int n) {

	if (n == 0)
		return;

	printf("%d", n % 10);

	reverse(n / 10);

}

void eg_3()
{
	int input;

	while (1) {
		scanf("%d", &input);

		if (input == 0)
			break;

		if (checkTwins(input) == -1)
			printf("no\n");

		else if (checkTwins(input) == 1)
			printf("yes\n");
	}
}

int checkTwins(int a) {

	int x, y;

	x = a % 10;
	y = a / 10 % 10;

	if (a < 10)
		return 1;

	if (x != y)
		return -1;

	else
		checkTwins(a / 100);

}

void eg_4()
{
	double input, decimal;
	int integer;

	while (1) {

		scanf("%lf", &input);

		if (input == 0)
			break;

		integer = (int)input;
		decimal = input - integer;

		printBin(integer);
		printf(".");
		count = 0;
		printFloatBin(decimal);
		printf("\n");

	}

}

void printBin(int a) {

	if (a > 0) {

		printBin(a / 2);

		printf("%d", a % 2);
	}

}

void printFloatBin(double a) {

	if (a > 0 && a < 1.0 && count < 10) {
		if (a * 2 == 1) {
			printf("1");
			return;
		}

		else if (a * 2 < 1.0) {
			printf("0");
			count++;
			printFloatBin(a * 2);
		}

		else if (a * 2 > 1.0) {
			printf("1");
			count++;
			printFloatBin(a * 2 - 1);
		}
	}

	if (a == 0) {
		printf("0");
		return;
	}

	return;
}

