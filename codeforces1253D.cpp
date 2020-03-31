#include <iostream>
#include <algorithm>

const int lens = 1e5 * 2 + 1;
int anc[lens];

int find(int x)
{
    if(anc[x] != x) anc[x] = find(anc[x]);
    return anc[x];
}

void merge(int a,int b)
{
    a = find(a);
    b = find(b);
    if(a > b) anc[b] = a;
    else anc[a] = b;
}

void init()
{
    for(int i = 0;i < lens;i++) anc[i] = i;
}

int main()
{
    std::ios::sync_with_stdio(0);
    int n,m,res = 0;
    init();
    std::cin >> n >> m;
    for(int i = 1;i <= m;i++)
    {
        int u,v;
        std::cin >> u >> v;
        merge(u,v);
    }

    for(int i = 1;i <= n;i++)
    {
        int cnt = find(i);
        for(int j = i + 1;j < cnt;j++)
        {
            int tmp = find(j);
            if(cnt != tmp)
            {
                if(tmp > cnt) std::swap(tmp,cnt);
                merge(tmp,cnt);
                res++;
            }
        }
        i = cnt;
    }
    std::cout << res;
    return 0;
}