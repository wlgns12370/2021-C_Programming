#include<stdio.h>

void eg_1();

void main() {

	eg_1();
}

void eg_1() {
	double x = 5.1247;
	double y = 20.7807;
	double z = 17.34;

	printf("%lf %lf %lf\n", x, y, z);
	printf("%lf\n", x + y + z);
	printf("%lf\n", x - y - z);
	printf("%lf\n", x / y / z);
	printf("%lf\n", (x * y) / z);

}