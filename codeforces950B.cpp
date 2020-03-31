#include <bits/stdc++.h>
#define LL long long 
const int lens = 1e6 + 1;
int s[lens],t[lens];
int n,m;
int main()
{
    std::cin >> n >> m;
    for(int i = 1;i <= n;i++) std::cin >> s[i];
    for(int i = 1;i <= m;i++) std::cin >> t[i];

    int p = 0,sum_s = 0,sum_t = 0,res_s = 0,res_t = 0;
    for(int i = 1;i <= n;i++)
    {
        sum_s += s[i];
        if(sum_s > sum_t)
        {
            while(sum_s > sum_t)
            {
                p++;
                sum_t += t[p];
            }
        }
        if(sum_s == sum_t)
        {
            res_s ++;
            sum_s = sum_t = 0;
        }
    }
    std::cout << res_s;
    return 0;
}