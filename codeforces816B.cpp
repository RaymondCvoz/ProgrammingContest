#include <bits/stdc++.h>

const int lens = 200005;
int diff[lens],num[lens],above[lens];
int main()
{
    int n,k,q;
    std::cin >> n >> k >> q;
    for(int i = 1;i <= n;i++)
    {
        int x,y;
        std::cin >> x >> y;
        diff[x] ++;
        diff[y + 1] --;
    }
    for(int i = 1;i < lens;i++)
    {
        num[i] = num[i - 1] + diff[i];
        if(num[i] >= k)
        {
            above[i] = 1;
        }
    }
    for(int i = 1;i < lens;i++)
    {
        above[i] = above[i - 1] + above[i];
    }
    while(q--)
    {
        int a,b;
        std::cin >> a >> b;
        std::cout << above[b] - above[a - 1] << "\n";
    }
    return 0;
}