#include <bits/stdc++.h>
#define LL long long

const int lens = 101;
bool p[lens];

int main()
{
    std::ios::sync_with_stdio(0);
    int n,m;
    std::cin >> n >> m;
    while(n--)
    {
        int a,b;
        std::cin >> a >> b;
        for(int i = a;i < b;i++) p[i] = 1;
    }
    for(int i = 0;i < m;i++)
    {
        if(!p[i])
        {
            std::cout << "NO"; return 0;
        }
    }
    std::cout << "YES";
    return 0;
}