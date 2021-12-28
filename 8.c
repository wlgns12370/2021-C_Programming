#include<stdio.h>
#define _crt_secure_no_warnings
#pragma warning (disable:4996)
#include<stdlib.h>
#include<string.h>

void ed8_1();
void ed8_2();
void ed8_3();
void ed8_4();
void ed8_5();

int isPrime(int x)
{
    int cnt = 0;
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0) {
            cnt++;
            break;
        }
    }
    if (cnt == 1)
    {
        return 0;
    }
    else {
        return 1;
    }
}

void printStar(int n) {
    int i, j;
    for (int j = 0; j < n; j++)
    {
        for (int i = n - j - 1; i > 0; i--)
        {
            printf(" ");
        }
        for (int i = 0; i < 2 * j + 1; i++)
        {
            printf("*");
        }

        printf("\n");
    }
}


int lcm(int n1, int n2) {

    int gcd = 0;
    int lcm = 0;
    for (int i = 1; i <= n1 && i <= n2; ++i) {

        if (n1 % i == 0 && n2 % i == 0)
            gcd = i;
    }

    lcm = (n1 * n2) / gcd;

    return lcm;
}


int gcd(int a, int b) {

    int n1 = 0, n2 = 0, gcd = 0;

    n1 = a;
    n2 = b;

    while (n1 != n2)
    {
        if (n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    printf("%d\n", n1);

    return 0;

}
int sumMultiple(int start, int end, int x) {

    int i, j;
    int total = 0;
    if (x == 0)
    {
        for (i = start; i < end; i++)
        {
            total += i;
        }
    }

    else {
        for (i = start; i < end; i++)
        {
            if (i % x == 0)
            {
                total += i;
            }
        }
    }

    return total;
}

int main(void) {

	ed8_1();

}

void ed8_1()
{
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);

    gcd(a, b);

}
void ed8_2()
{
    int n = 0;
    scanf("%d", &n);

    printStar(n);
}
void ed8_3()
{

    int x;
    scanf("%d", &x);
    printf("%s\n", isPrime(x) ? "prime" : "not prime");
}
void ed8_4()
{
    int start, end, n, m;
    int result1 = 0;
    int result2 = 0;
    int result3 = 0;
    int result4 = 0;
    int result5 = 0;
    int result6 = 0;
    scanf("%d %d %d %d", &start, &end, &n, &m);

    result1 = sumMultiple(start, end, n);
    printf("%d\n", result1);
    result2 = sumMultiple(start, end, m);
    printf("%d\n", result2);
    result3 = sumMultiple(start, end, n * m);
    printf("%d\n", result3);
    result4 = result1 + result2 - result3;
    printf("%d\n", result4);
    result5 = result4 - result1;
    printf("%d\n", result5);
    result6 = sumMultiple(start, end, 0) - result4;
    printf("%d\n", result6);
}
void ed8_5()
{

    int n1 = 0;
    int n2 = 0;
    int result = 0;
    scanf("%d %d", &n1, &n2);

    result = lcm(n1, n2);
    printf("%d", result);
}

