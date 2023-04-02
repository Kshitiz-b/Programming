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
        int n = max(getSize(x), getSize(y));
        int half = n / 2;
        long rem = (long)ceil(pow(10, half));

        long a = (long)floor(x / (long)rem);
        long b = x % rem;
        long c = (long)floor(y / (long)rem);
        long d = y % rem;

        long ac = karatsuba(a, c);
        long bd = karatsuba(b, d);
        long ad_plus_bc = karatsuba(a + b, c + d) - ac - bd;
        long result = (long)(ac * pow(10, (2 * half)) + (ad_plus_bc * rem) + bd);

        return result;
    }
}

int main()
{
    long x, y;
    scanf("%ld %ld", &x, &y);

    long ans = karatsuba(x, y);
    printf("%ld", ans);
    return 0;
}
