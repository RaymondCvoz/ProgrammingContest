#include <iostream>
#include <algorithm>

long long n,q;
int main()
{
    std::cin >> n >> q;
    while(q--)
    {
        long long x;
        std::cin >> x;
        while(x % 2 == 0) x += n - x / 2;
        std::cout << x / 2 + 1 << "\n"; 
    }
    return 0;
}