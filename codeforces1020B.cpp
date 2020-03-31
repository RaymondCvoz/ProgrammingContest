#include <bits/stdc++.h>
const int lens = 1e3 + 1;
int p[lens],a[lens],hole[lens];

void dfs(int x,int i)
{
    if(hole[x] == 1)
    {
        a[i] = x; return;
    }
    hole[x] = 1;
    dfs(p[x],i);
}

int main()
{
    int n;
    std::cin >> n;
    for(int i = 1;i <= n;i++) std::cin >> p[i];
    for(int i = 1;i <= n;i++)
    {
        memset(hole,0,sizeof(hole));
        hole[i] = 1;
        dfs(p[i],i);
    }
    for(int i = 1;i <= n;i++) std::cout << a[i] << " ";
    return 0;
}