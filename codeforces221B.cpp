#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

int vis[10];
int main()
{
    int n,ans = 0;
    std::cin >> n;
    for(int i = 1;i <= sqrt(n);i++)
    {
        if(n % i == 0)
        {
            memset(vis,0,sizeof(vis));
            int a = n / i;
            int b = n / a;
            int cnt = n;
            while(cnt)
            {
                vis[cnt % 10] = 1;
                cnt /= 10;
            }
            while(a)
            {
                if(vis[a % 10] == 1)
                {
                    ans ++;
                    break;
                }
                a /= 10;
            }
            if(a != b)
            {
                while(b)
                {
                    if(vis[b % 10] == 1)
                    {
                        ans ++;
                        break;
                    }
                    b /= 10;
                }
            }
        }
    }
    std::cout << ans;
    return 0;
}