#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int lens = 1e6 + 7;
const int INF = 1e9;
int dis[lens],sec[lens],last[lens],num;

struct node
{
    int dis,num;
    node(int num = 0,int dis = 0)
    {
        this -> num = num;
        this -> dis = dis;
    }
    bool operator () (node a,node b)
    {
        return a.dis > b.dis;
    }
};
priority_queue <node,vector<node>,node> q;

struct E
{
    int next,to,weight;
}edge[lens];

void add(int from,int to,int weight)
{
    num ++;
    edge[num].to = to; edge[num].weight = weight; edge[num].next = last[from]; last[from] = num;
}
void init(int n)
{
    for(int i = 0;i <= n;i++)
    {
        sec[i] = dis[i] = INF;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n,r;
    cin >> n >> r;
    init(n);
    while(r--)
    {
        int u,v,d;
        std::cin >> u >> v >> d;
        add(u,v,d);
        add(v,u,d);
    }
    dis[1] = 0;
    q.push(node(1,0));
    while(!q.empty())
    {
        node cnt = q.top(); q.pop();
        if(cnt.dis > sec[cnt.num]) continue;
        for(int i = last[cnt.num];i;i = edge[i].next)
        {
            int d = cnt.dis + edge[i].weight;
            if(dis[edge[i].to] > d)
            {
                swap(dis[edge[i].to],d);
                q.push(node(edge[i].to,dis[edge[i].to]));
            }
            if(d > dis[edge[i].to] && d < sec[edge[i].to])
            {
                sec[edge[i].to] = d;
                q.push(node(edge[i].to,sec[edge[i].to]));
            }
        }
    }
    cout << sec[n];
    return 0;
}