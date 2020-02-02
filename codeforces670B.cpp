#include <iostream>
#include <algorithm>
#include <vector>

const int lens = 1e6 + 1;
long long v[lens],sum[lens];

int main()
{
    std::ios::sync_with_stdio(false);
    long long n,k;
    std::cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> v[i];
    }
    long long res = 0;
    for(long long i = 1;i <= 100000;i++)
    {
        sum[i] = i * (i + 1) / 2;
    }
    //std::cout << sum[1000000] << "\n";
    long long it = std::lower_bound(sum + 1,sum + 100001,k) - sum;
    int t = k - sum[it - 1];
    //std::cout << it - 1 << " " << sum[it - 1] << "\n";
    int i = 1;
    while(1)
    {
        t--;
        if(!t)
        {
            std::cout << v[i]; return 0;
        }
        i++;
        if(i == n + 1) i = 1;
    }
    return 0;
}