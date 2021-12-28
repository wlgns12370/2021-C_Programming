#include <stdio.h>
#include <math.h>

void ed3_1();
void ed3_2();


int main(void)
{
	void ed3_1();
	void ed3_2();
	
}

void ed3_1()
{
	int input, output;

	scanf("%d", &input);
	output = SQ4(input);

	printf("%d", output);

}

void ed3_2()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d:%d\n", 10000, num / 10000);
	printf("%d:%d\n", 5000, num % 10000 / 5000);
	printf("%d:%d\n", 1000, num % 10000 % 5000 / 1000);
	printf("%d:%d\n", 500, num % 10000 % 5000 % 1000 / 500);
	printf("%d:%d\n", 100, num % 10000 % 5000 % 1000 % 500 / 100);
	printf("%d:%d\n", 50, num % 10000 % 5000 % 1000 % 500 % 100 / 50);
	printf("%d:%d\n", 10, num % 10000 % 5000 % 1000 % 500 % 100 % 50 / 10);
	printf("%d:%d\n", 5, num % 10000 % 5000 % 1000 % 500 % 100 % 50 % 10 / 5);
	printf("%d:%d\n", 1, num % 10000 % 5000 % 1000 % 500 % 100 % 50 % 10 % 5);

}
