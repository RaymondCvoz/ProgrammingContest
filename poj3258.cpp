#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdio>
#define LL long long
const int lens = 1e6 + 1;
LL x[lens];
LL p,n,t;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin >> p >> n >> t;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> x[i];
    }
    std::sort(x + 1,x + n + 1);
    LL L = 0,R = p + 1;
    while(L <= R)
    {
        LL M = L + R >> 1;
        LL cnt = 0,tot = 0;
        for(int i = 1;i <= n;i++)
        {
            if(x[i] - cnt < M)
            {
                tot++;
            }
            else
            {
                cnt = x[i];
            }
        }
        if(p - cnt < M) tot++;
        if(tot > t)
        {
            R = M - 1;
        }
        else
        {
            L = M + 1;
        }
    }
    std::cout << L - 1;
    return 0;
}