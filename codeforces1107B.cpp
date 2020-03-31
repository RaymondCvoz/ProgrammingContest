#include <bits/stdc++.h>
#define LL long long

LL n,k,x;
int main()
{
    std::cin >> n;
    while(n--)
    {
        std::cin >> k >> x;
        std::cout << x + (9 * (k - 1)) << "\n";
    }
}