#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

class N
{
    public:
    int w,h;
}node[7];

bool cmp(N a,N b)
{
    if(a.w == b.w) return a.h < b.h;
    return a.w < b.w;
}   

int main()
{
    while(1)
    {
        for(int i = 1;i <= 6;i++)
        {
            if(scanf("%d%d",&node[i].w,&node[i].h) != 2) return 0;
            if(node[i].w < node[i].h) std::swap(node[i].w,node[i].h);
        }
        std::sort(node + 1,node + 7,cmp);
        if(node[6].w == node[5].w && node[5].w == node[4].w && node[4].w == node[3].w && node[6].h == node[5].h && node[5].h == node[1].w && node[1].w == node[2].w && node[4].h == node[3].h && node[3].h == node[2].h && node[2].h == node[1].h)
        {
            std::cout << "POSSIBLE\n";
        }
        else std::cout << "IMPOSSIBLE\n";
    }
    return 0;
}

