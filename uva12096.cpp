#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

std::map <std::set <int>,int> IDcache;
std::vector <std::set <int>> Setcache;

int ID(std::set <int> x)
{
    if(IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;
}

int main()
{
    std::set <int> k;
    std::stack <int> s;
    int n,t;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n;
        while(n--)
        {
            std::string ope;
            std::cin >> ope;
            if(ope[0] == 'P') s.push(ID(std::set <int> ()));
            else if(ope[0] == 'D') s.push(s.top());
            else
            {
                std::set <int> x1 = Setcache[s.top()]; s.pop();
                std::set <int> x2 = Setcache[s.top()]; s.pop();
                std::set <int> x;
                if(ope[0] == 'U') std::set_union(ALL(x1),ALL(x2),INS(x));
                else if(ope[0] == 'I') std::set_intersection(ALL(x1),ALL(x2),INS(x));
                else if(ope[0] == 'A')
                {
                    x = x2; x.insert(ID(x1));
                }
                s.push(ID(x));
            }
            std::cout << Setcache[s.top()].size() << "\n";
        }
        IDcache.clear();
        Setcache.clear();
        std::cout << "***\n";
    }
    return 0;
}

