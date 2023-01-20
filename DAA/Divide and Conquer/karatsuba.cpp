#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

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

long Karatsuba(long x, long y)
{
    if (x < 10 && y < 10)
        return x * y;

    cout << "X:" << x << ", Y:" << y << endl;
    int m = max(getSize(x), getSize(y));
    int n = ceil(m / 2.0);

    long p = (long)ceil(pow(10, n));
    long x1 = (long)floor(x / (double)p);
    long x2 = x % p;
    long y1 = (long)floor(y / (double)p);
    long y2 = y % p;

    cout << "x1=" << x1 << " x2=" << x2 << " y1=" << y1 << " y2=" << y2 << endl << endl;

    long a = Karatsuba(x1, y1);
    long c = Karatsuba(x2, y2);
    long b = Karatsuba(x1 + x2, y1 + y2);

    b = b - a - c;
    cout << "a=" << a << " b=" << b << " c=" << c << endl;

    long result = (long)(a * pow(10 * 1l, 2 * n) + b * pow(10 * 1l, n) + c);
    cout << "xy: " << result << endl << endl;

    return result;
}

int main(void)
{
    long a, b;
    cin >> a >> b;

    long result = Karatsuba(a, b);

    cout << a << " * " << b << " = " << result << endl;

    return 0;
}
