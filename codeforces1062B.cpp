#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

int n;
std::vector <std::pair <int,int> > v;

void factor(int x)
{
    for(int i = 2;i * i <= x;i++)
    {
        int cnt = 0;
        while(x % i == 0)
        {
            x /= i;
            cnt++;
        }
        if(cnt) v.emplace_back(i,cnt);
    }
    if(x > 1) v.emplace_back(x,1);
}

int main()
{
    std::cin >> n;
    factor(n);
    int ans = 1,max = 0,flag = 0;
    for(int i = 0;i < v.size();i++)
    {
        int a = v[i].first,b = v[i].second;
        if((i > 0 && v[i - 1].second != b) || (b & (b - 1)) != 0 || b == 1) flag = 1;
        ans *= a;
        max = std::max(max,b);
    }

    int cnt = 0;
    if(max > 1)
    {
        cnt += (int)ceil(log2(max));
        cnt += flag;
    }

    printf("%d %d\n",ans,cnt);
    return 0;
}