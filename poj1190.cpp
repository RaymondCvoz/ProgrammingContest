#include <iostream>
#include <algorithm>
#include <cmath>
int n,m,ans;

const int inf = 1e9;
void dfs(int cnt,int r,int h,int v,int s)
{
    if(s + 2 * v / r > ans) return;
    if(cnt == m)
    {
        if(!v) ans = std::min(ans,s);
        return;
    }

    for(int i = r - 1;i >= m - cnt;i--)
    {
        int k = std::min(h - 1,v / (i * i));
        for(int j = k;j >= m - cnt;j--)
        {
            int res = 0;
            if(cnt == 0) res = i * i + 2 * i * j;
            else res = s + 2 * i * j;
            dfs(cnt + 1,i,j,v - i * i * j,res);
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(0);
    while(std::cin >> n >> m)
    {
        ans = inf;
        dfs(0,sqrt(n) + 1,n + 1,n,0);
        if(ans == inf) std::cout << 0 << "\n";
        else std::cout << ans << "\n";
    }
    return 0;
}