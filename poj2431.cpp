#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

std::priority_queue <int> q;
struct STA
{
    int dis,fuel;
}sta[10001];

bool cmp(STA a,STA b)
{
    return a.dis > b.dis;
}

int main()
{
    int n,l,p;
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> sta[i].dis >> sta[i].fuel;
    }
    std::cin >> l >> p;
    std::sort(sta + 1,sta + n + 1,cmp);
    int res = 0;
    for(int i = 1;i <= n;i++)
    {
        if(p >= l - sta[i].dis && sta[i].dis <= l)
        {
            p -= l - sta[i].dis;
            q.push(sta[i].fuel);
            l = sta[i].dis;
        }
        else if(p < l - sta[i].dis && sta[i].dis <= l)
        {
            while(!q.empty() && p < l - sta[i].dis)
            {
                p += q.top();
                //std::cout << q.top() << " ";
                q.pop();
                res++;
            }
            if(q.empty() && p < l - sta[i].dis)
            {
                std::cout << -1;
                return 0;
            }
            p -= l - sta[i].dis;
            q.push(sta[i].fuel);
            l = sta[i].dis;
        }
    }
    int tmp = l;
    l -= p;
    p = 0;
    if(l <= 0)
    {
        std::cout << res;
        return 0;
    }
    else

        while(!q.empty() && l > 0)
        {
            l -= q.top();
            //std::cout << q.top() << " ";
            q.pop();
            res++;
        }
    std::cout << res;
    return 0;
}