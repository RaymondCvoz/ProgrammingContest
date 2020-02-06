#include <iostream>
#include <algorithm>
#include <cstdio>

int main()
{
    int n;
    std::cin >> n;
    double ans = 0,s = n;
    for(int i = n;i >= 1;i--)
    {
        double t = 1,s = i;
        ans += t / s;
    }
    std::cout << ans;
    return 0;
}