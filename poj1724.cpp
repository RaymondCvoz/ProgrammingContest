#include <iostream>
#include <algorithm>

const int lens = 1e4 + 1;

int head[lens],num,n,m,k,ans = 1e9,min[101][10001];
bool vis[lens];

class E
{
    public:
    int toll,weight,next,to;   
}edge[lens];

void add(int from,int to,int weight,int toll)
{
    num ++;
    edge[num].to = to;
    edge[num].weight = weight;
    edge[num].toll = toll;
    edge[num].next = head[from];
    head[from] = num;
}

void dfs(int remain,int cnt,int dis)
{
    if(cnt == n)
    {
        ans = std::min(ans,dis);
        return;
    }

    for(int i = head[cnt];i;i = edge[i].next)
    {
        if(!vis[edge[i].to] && remain >= edge[i].toll && dis + edge[i].weight < ans && min[edge[i].to][remain - edge[i].toll] > dis + edge[i].weight)
        {
            vis[edge[i].to] = 1;
            min[edge[i].to][remain - edge[i].toll] = dis + edge[i].weight;
            dfs(remain - edge[i].toll,edge[i].to,dis + edge[i].weight);
            vis[edge[i].to] = 0;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin >> k >> n >> m;
    for(int i = 1;i <= m;i++)
    {
        int u,v,w,t;
        std::cin >> u >> v >> w >> t;
        add(u,v,w,t);
    }
    for(int i = 0;i <= 100;i++)
        for(int j = 0;j <= 10000;j++)
            min[i][j] = 1e9;

    dfs(k,1,0);
    std::cout << ans;
    return 0;    
}