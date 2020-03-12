#include <bits/stdc++.h>

int cnt,sum,max,n;
int main()
{
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> cnt; sum += cnt;
        max = std::max(cnt,max);
    }
    std::cout << n * max - sum;
}