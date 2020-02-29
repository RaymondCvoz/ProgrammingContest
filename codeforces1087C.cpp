#include <bits/stdc++.h>

#define LL long long

std::pair <LL,LL> p[4];
std::set <std::pair <LL,LL> > s;
int main()
{
    for(int i = 1;i <= 3;i++) std::cin >> p[i].first >> p[i].second;
    std::sort(p + 1,p + 4);
    LL max = std::max(p[1].second,std::max(p[2].second,p[3].second));
    LL min = std::min(p[1].second,std::min(p[2].second,p[3].second));
    for(int i = min;i <= max;i++)
    {
        s.insert({p[2].first,i});
    }
    for(int i = p[1].first;i <= p[2].first;i++)
    {
        s.insert({i,p[1].second});
    }
    for(int i = p[2].first;i <= p[3].first;i++)
    {
        s.insert({i,p[3].second});
    }
    std::cout << s.size() << "\n";
    for(std::set <std::pair <LL,LL>>::iterator it = s.begin();it != s.end();it++)
    {
        std::cout << it -> first << " " << it -> second << "\n";
    }
    return 0;
}   