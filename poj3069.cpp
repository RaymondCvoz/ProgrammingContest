#include <iostream>
#include <algorithm>
#include <cstring>
int pos[1001];
int main()
{
    int n,r;
    std::cin >> r >> n;
    while(n != -1 && r != -1)
    {
        memset(pos,0,sizeof(pos));
        for(int i = 1;i <= n;i++)
        {
            std::cin >> pos[i];
        }
        std::sort(pos + 1,pos + n + 1);
        int cnt = 1,res = 0;
        int border = 0;
        while(cnt <= n)
        {
            border = pos[cnt];
            cnt++;
            while(cnt <= n && pos[cnt] <= border + r) cnt++;
            int p = pos[cnt - 1];
            while(cnt <= n && pos[cnt] <= p + r) cnt++;
            res++;
        }
        std::cout << res << std::endl;
        std::cin >> r >> n;
    }
}