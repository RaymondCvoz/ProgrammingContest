#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
const int lens = 26;
std::vector <int> pile[lens];
int n;

void find_block(int a,int &p,int &h)
{
    for(p = 0;p < lens;p++)
    {
        for(h = 0;h < pile[p].size();h++)
        {
            if(pile[p][h] == a) return;
        }
    }
}

void clear_above(int p,int h)
{
    for(int i = h + 1;i < pile[p].size();i++)
    {
        int cnt = pile[p][i];
        pile[cnt].push_back(cnt);
    }
    pile[p].resize(h + 1);
}

void pile_onto(int p,int h,int p2)
{
    for(int i = h;i < pile[p].size();i++)
    {
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}
int main()
{
    int a,b; std::string s1,s2;
    std::cin >> n;
    for(int i = 0;i < lens;i++) pile[i].push_back(i);
    while(std::cin >> s1 >> a >> s2 >> b)
    {
        int pa,ha,pb,hb;
        find_block(a,pa,ha);
        find_block(b,pb,hb);
        if(pa == pb) continue;
        if(s2 == "onto") clear_above(pb,hb);
        if(s1 == "move") clear_above(pa,ha);
        pile_onto(pa,ha,pb);
    }
    for(int i = 0;i < n;i++)
    {
        std::cout << i << ":";
        for(int j = 0;j < pile[i].size();j++)
        {
            std::cout << " " << pile[i][j];
        }
        std::cout << "\n";
    }
    return 0;
}