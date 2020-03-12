#include <bits/stdc++.h>

int num[105],n,sum;

int main()
{
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> num[i];
        sum += num[i];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if((sum - num[i]) % 2 == 0) ans ++;
    }
    std::cout << ans;
}