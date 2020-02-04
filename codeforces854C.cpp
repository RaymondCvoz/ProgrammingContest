#include <iostream>
#include <algorithm>
#include <queue>

struct Aircraft
{
    long long cargo,t,id;
    bool operator < (const Aircraft & a) const
    {
        return cargo == a.cargo ? t > a.t : cargo < a.cargo;
    }
}plane[300010];

std::priority_queue <Aircraft> seq;
long long order[300010];

int main()
{
    long long n,k;
    std::cin >> n >> k;
    for(long long i = 1;i <= n;i++)
    {
        std::cin >> plane[i].cargo;
        plane[i].t = i;
        plane[i].id = i;
        if(plane[i].t <= k)
        seq.push(plane[i]);
    }

    long long ans = 0;
    for(long long i = k + 1;i <= n;i++)
    {
        if(!seq.empty())
        {
            Aircraft x = seq.top();
            if(plane[i].cargo <= x.cargo)
            {
                ans += x.cargo * (i - x.t);
                seq.pop();   //"goodbye and safe travel"
                order[x.id] = i;
                seq.push(plane[i]);   
            }
            else order[plane[i].id] = i;
        }
        else order[plane[i].id] = i;//"goodbye and safe travel"
    }
    long long i = n + 1;
    while(!seq.empty())
    {
        ans += seq.top().cargo * (i - seq.top().t);
        order[seq.top().id] = i;
        seq.pop();//"goodbye and safe travel"
        i++;
    }
    std::cout << ans << "\n";
    for(long long i = 1;i <= n;i++) std::cout << order[i] << " ";
    return 0;
}