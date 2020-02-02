#include <iostream>
#include <algorithm>

long long n;

int main()
{
    std::cin >> n;
    if(n >= 0)
    {
        std::cout << n;
        return 0;
    }
    n = -n;
    long long tmp = n;
    std::cout << (tmp / 10 > tmp / 100 * 10 + tmp % 10 ? -(tmp / 100 * 10 + tmp % 10) : -(tmp / 10));
    return 0;
}