#include <stdio.h>
#include <math.h>

void ed2_1();
void ed2_2();
void ed2_3();
void ed2_4();
void ed2_5();

int main(void)
{
	void ed2_1();
	void ed2_2();
	void ed2_3();
	void ed2_4();
	void ed2_5();
}

void ed2_1()
{
	int CHAR_MAX = pow(2, 7) - 1;
	int CHAR_MIN = -pow(2, 7);
	int SHORT_MAX = pow(2, 15) - 1;
	int SHORT_MIN = -pow(2, 15);
	int INT_MAX = pow(2, 31) - 1;
	int INT_MIN = -pow(2, 31);

	printf("CHAR_MAX : %d\n", CHAR_MAX);
	printf("CHAR_MIN : %d\n", CHAR_MIN);
	printf("SHORT_MAX : %d\n", SHORT_MAX);
	printf("SHORT_MIN : %d\n", SHORT_MIN);
	printf("INT_MAX : %d\n", INT_MAX);
	printf("INT_MIN : %d\n", INT_MIN);

}

void ed2_2()
{
	int UNSIGNED_CHAR_MAX = pow(2, 8) - 1;
	int UNSIGNED_CHAR_MIN = 0;
	int UNSIGNED_SHORT_MAX = pow(2, 16) - 1;
	int UNSIGNED_SHORT_MIN = 0;
	unsigned int UNSIGNED_INT_MAX = pow(2, 32) - 1;
	int UNSIGNED_INT_MIN = 0;

	printf("UNSIGNED_CHAR_MAX : %d\n", UNSIGNED_CHAR_MAX);
	printf("UNSIGNED_CHAR_MIN : %d\n", UNSIGNED_CHAR_MIN);
	printf("UNSIGNED_SHORT_MAX : %d\n", UNSIGNED_SHORT_MAX);
	printf("UNSIGNED_SHORT_MIN : %d\n", UNSIGNED_SHORT_MIN);
	printf("UNSIGNED_INT_MAX : %u\n", UNSIGNED_INT_MAX);
	printf("UNSIGNED_INT_MIN : %d\n", UNSIGNED_INT_MIN);

}

void ed2_3()
{
	double x = 11.3;

	printf("x의 값이 11.3일 때, 다항식의 값은 %lf 입니다.", (3 * pow(x, 3.0) - 7 * pow(x, 2.0) + 9));

}

void ed2_4()
{
	printf("\"이것은 출력제어문자를 이용한 실습예제\"\n");
	printf("\"출력제어문자는 \'\\\'문자를 사용\"");

}
void ed2_5()
{
	int money = 37970;

	printf("37970원은\n");
	printf("만원짜리 %d개\n", money / 10000);
	printf("오천원짜리 %d개\n", money % 10000 / 5000);
	printf("천원짜리 %d개\n", money % 10000 % 5000 / 1000);
	printf("백원짜리 %d개\n", money % 10000 % 5000 % 1000 / 100);
	printf("십원짜리 %d개로 구성됩니다.\n", money % 10000 % 5000 % 1000 % 100 / 10);

}
