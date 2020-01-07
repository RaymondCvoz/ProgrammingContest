#include <iostream>
#include <algorithm>
#include <cmath>
long long n,a[5000],x = 0,flag = 1;
int main()
{
    long long t;
    std::cin >> t;
    while(t--)
    {
        flag = 1;
        std::cin >> n;
        for(long long i = 1;i <= n;i++)
        {
            std::cin >> a[i] ;
        }
        std::sort(a + 1,a + n + 1);
        if(1 == 1)
        {
            x = a[1] * a[n];
            long long tot = 0;
            for(long long i = 1;i <= n;i++)
            {
                if(x % a[i] != 0)
                {
                    flag = 0;
                }
            }
            for(long long i = 2;i <= sqrt(x);i++)
            {
                if(x % i == 0)
                {
                    tot += 2;
                }
                if(i * i == x) tot--;
            }
            if(tot != n) flag = 0;
        }
        if(flag == 1)
        {
            std::cout << x << std::endl;
        }
        else
        {
            std::cout << -1 << std::endl;
        }
    }
    return 0;
}