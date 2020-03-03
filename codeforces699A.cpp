#include<bits/stdc++.h>
#define LL long long

int p[200005];
char d[200005];
int main()
{   
    int n,a = -1,ans = INT_MAX;
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> d[i];
    }
    for(int i = 1;i <= n;i++)
    {
        std::cin >> p[i];
    }
    for(int i = 1;i <= n;i++)
    {
        if(d[i] == 'L' && a != -1)
        {
            ans = std::min(ans,(p[i] - p[a]) / 2);
            a = -1;
        }
        else if(d[i] == 'R') a = i;
    }
    if(ans ==  INT_MAX) std::cout << -1;
    else std::cout << ans;
    return 0;
}