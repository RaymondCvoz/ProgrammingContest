#include <bits/stdc++.h>
#define LL long long

const int lens = 2e6 + 7;
LL a[lens],b[lens],n;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for(int i = 1;i <= n;i++) std::cin >> a[i] >> b[i];
    for(int i = 2;i <= n;i++)
    {
        a[1] = std::__gcd(a[i] * b[i],a[1]);
        b[1] = std::__gcd(a[i] * b[i],b[1]);
    }
    a[1] = std::max(a[1],b[1]);
    if(a[1] > 1)
    {
        for(LL i = 2;i * i <= a[1];i++)
        {
            if(a[1] % i == 0){std::cout << i; return 0;}
        }
        std::cout << a[1];
    }
    else std::cout << -1;
    return 0;
}