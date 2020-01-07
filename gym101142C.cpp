#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

const int lens = 1e5 + 1;

class Data
{
    public:
    int x,y,id,ans;
}a[lens];

bool cmp1(const Data &a, const Data &b) {return a.x < b.x;}
bool cmp2(const Data &a, const Data &b) {return a.y < b.y;}
bool cmp3(const Data &a, const Data &b) {return a.id < b.id;}

int vis[lens];
std::vector <int> G[lens];
int n,ans;

void dfs(int x)
{
    if(!vis[x]) ans ++;
    vis[x] = 1;
    for(int i = 0;i < G[x].size();i++)
    {
        if(vis[G[x][i]]) continue;
        dfs(G[x][i]);
    }
}

int main()
{
    freopen("codecoder.in","r",stdin);
    freopen("codecoder.out","w",stdout);
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    std::sort(a + 1,a + n + 1,cmp1);
    for(int i = 2;i <= n;i++) G[a[i].id].push_back(a[i - 1].id);
    std::sort(a + 1,a + n + 1,cmp2);
    for(int i = 2;i <= n;i++) G[a[i].id].push_back(a[i - 1].id);

    for(int i = 1;i <= n;i++)
    {
        dfs(a[i].id);
        a[i].ans = ans - 1;
    }
    std::sort(a + 1,a + n + 1,cmp3);
    for(int i = 1;i <= n;i++) std::cout << a[i].ans << "\n";
    return 0;
}