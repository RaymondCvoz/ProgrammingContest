#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

const int lens = 1e6 + 7;
const int INF = 1e9;

int anc[lens];

struct E
{
    int from,to,weight;
}edge[lens];

bool cmp(E a,E b)
{
    return a.weight > b.weight;
}


void init(int n)
{
    for(int i = 0;i <= n;i++)
    {
        anc[i] = i;
    }
}

int find(int x)
{
    if(anc[x] != x) anc[x] = find(anc[x]);
    return anc[x];
}

void merge(int a,int b)
{
    a = find(a); b = find(b);
    anc[a] = b;
}

bool judge(int a,int b)
{
    return find(a) == find(b);
}

int main()
{
    int tot;
    scanf("%d",&tot);
    while(tot--)
    {
        int n,m,r;
        scanf("%d%d%d",&n,&m,&r);
        init(n + m + 1);
        for(int i = 1;i <= r;i++)
        {
            scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].weight);
            edge[i].to += n;
        }
        sort(edge + 1,edge + r + 1,cmp);
        long long sum = 0,x = 0;
        for(int i = 1;i <= r;i++)
        {
            if(!judge(edge[i].from,edge[i].to))
            {
                sum += edge[i].weight;
                merge(edge[i].from,edge[i].to);
                x ++;
            }
            if(x == n + m - 1) break;
        }
        printf("%lld\n",(n + m) * 10000 - sum);
    }
    return  0;
}