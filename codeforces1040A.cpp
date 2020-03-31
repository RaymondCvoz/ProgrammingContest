#include <bits/stdc++.h>
#define LL long long

int p[21],n,a,b;
int main()
{
    std::cin >> n >> a >> b; 
    int c = std::min(a,b),ans = 0;
    for(int i = 1;i <= n;i++) std::cin >> p[i];
    bool flag = 1;
    if(n & 1 && p[n / 2 + 1] == 2) ans += c; 
    for(int i = 1;i <= n / 2;i++)
    {
        if(p[i] == 1)
        {
            if(p[n - i + 1] == 2) ans += b;
            if(p[n - i + 1] == 0) flag = 0;
        }
        if(p[i] == 2)
        {
            if(p[n - i + 1] == 1) ans += b;
            if(p[n - i + 1] == 0) ans += a;
            if(p[n - i + 1] == 2) ans += c * 2;
        }
        if(p[i] == 0)
        {
            if(p[n - i + 1] == 2) ans += a;
            if(p[n - i + 1] == 1) flag = 0;
        }
    }
    if(!flag) std::cout << -1;
    else std::cout << ans;
}