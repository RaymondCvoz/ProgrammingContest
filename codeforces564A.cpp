#include <iostream>
#include <algorithm>

int main()
{
    long long k,n,w;
    std::cin >> k >> n >> w;
    std::cout << (n - k * (w * (w + 1)) / 2 < 0 ? -(n - k * (w * (w + 1) / 2)) : 0);
    return 0;
}