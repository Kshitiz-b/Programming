#include <stdio.h>
#include <math.h>

int getSize(long num)
{
    int size = 0;
    while (num > 0)
    {
        size++;
        num /= 10;
    }
    return size;
}

long max(long x, long y)
{
    if (x >= y)
        return x;
    else
        return y;
}

long karatsuba(long x, long y)
{
    if ((x < 10) || (y < 10))
        return x * y;
    else
    {
        // long x_length = (long)log10(x) + 1;
        // long y_length = (long)log10(y) + 1;
        int n = max(getSize(x), getSize(y));
        int half = n / 2;
        // int rem = pow(10, half);
        long rem = (long)ceil(pow(10, half));

        // long a = x / rem;
        // long b = x % (rem);
        // long c = y / rem;
        // long d = y % (rem);

        long a = (long)floor(x / (double)rem);
        long b = x % rem;
        long c = (long)floor(y / (double)rem);
        long d = y % rem;

        long ac = karatsuba(a, c);
        long bd = karatsuba(b, d);
        long ad_plus_bc = karatsuba(a + b, c + d) - ac - bd;
        long result = (long)(ac * pow(10, (2 * half)) + (ad_plus_bc * rem) + bd);
        //long result = (long)(a * pow(10 * 1l, 2 * n) + b * pow(10 * 1l, n) + c);

        return result;
    }
}

int main()
{
    long x, y;
    scanf("%d %d", &x, &y);

    long ans = karatsuba(x, y);
    printf("%d", ans);
    return 0;
}
