#include <bits/stdc++.h>
#define LL long long 
const int lens = 200001;
std::string s;
std::vector <int> v[lens];
std::queue <int> zero;
std::queue <int> one;
int main()
{
    std::cin >> s;
    int cnt = 1,tot = 0;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '0')
        {
            if(!one.size())
            {
                v[++tot].push_back(i + 1);
                zero.push(tot);
            }
            else
            {
                int t = one.front();
                v[t].push_back(i + 1);
                zero.push(t);
                one.pop();
            }
        }
        else if(s[i] == '1')
        {
            if(!zero.size())
            {
                std::cout << -1; return 0;
            }
            else
            {
                int t = zero.front();
                v[t].push_back(i + 1);
                one.push(t);
                zero.pop();
            }
        }
    }
    if(one.size())
    {
        std::cout << -1; return 0;
    }
    std::cout << tot << "\n";
    for(int i = 1;i <= tot;i++)
    {
        std::cout << v[i].size() << " ";;
        for(auto x : v[i]) std::cout << x << " ";
        std::cout << "\n";
    }
}