#include <bits/stdc++.h>

#define LL long long

int main()
{
    LL s,a,b,c,t;
    std::cin >> t;
    while(t--)
    {
        std::cin >> s >> a >> b >> c;
        std::cout << (s / c / a) * b + s / c << "\n";
    }
    return 0;
}