#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdio>
#define LL long long
const int lens = 1e6 + 1;
LL x[lens];
LL n,c;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n >> c;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> x[i];
    }
    std::sort(x + 1,x + n + 1);
    LL L = 0,R = x[n] - x[1] + 1;
    while(L <= R)
    {
        LL M = L + R >> 1;
        LL tot = 1;
        LL cnt =  x[1];
        for(int i = 2;i <= n;i++)
        {
           if(x[i] - cnt >= M)
           {
               cnt = x[i];
               tot++;
           }
        }
        if(tot >= c)
        {
            L = M + 1;
        }
        else
        {
            R = M - 1;
        }
    }
    std::cout << L - 1;
    return 0;
}