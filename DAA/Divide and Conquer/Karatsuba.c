#include <stdio.h>
#include <math.h>

int max(int x, int y)
{
    if (x >= y)
        return x;
    else
        return y;
}

int karatsuba(int x, int y)
{
    if ((x < 10) || (y < 10))
        return x * y;
    else
    {
        int x_length = (int)log10(x) + 1;
        int y_length = (int)log10(y) + 1;
        int n = max(x_length, y_length);
        int half = n / 2;
        int rem = pow(10, half);
        int a = x / rem;
        int b = x % (rem);
        int c = y / rem;
        int d = y % (rem);

        int ac = karatsuba(a, c);
        int bd = karatsuba(b, d);
        int ad_plus_bc = karatsuba(a + b, c + d) - ac - bd;
        int result = ac * pow(10, (2 * half)) + (ad_plus_bc * rem) + bd;
        return result;
    }
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    int ans = karatsuba(x, y);
    printf("%d", ans);
    return 0;
}
