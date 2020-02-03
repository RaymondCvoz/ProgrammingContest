#include <iostream>
#include <algorithm>

const int lens = 1e5 + 1;
int n,a[lens];
int main()
{
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> a[i];
    }
    int flag = 0,x = 0,cnt = 0,t = 0,max = 0,flag2 = 1;
    for(int i = 1;i <= n;i++)
    {
        t = n,cnt = i,max = -1;flag2 = 1;
        while(t--)
        {
            if(a[cnt] >= max) max = a[cnt];
            else 
            {
                flag2 = 0;
                break;
            }
            cnt ++;
            if(cnt == n + 1) cnt = 1;
        }
        if(flag2)
        {
            flag = 1;
            x = cnt; break;
        }
    }
    if(!flag)
    {
        std::cout << -1;
        return 0;
    }
    else
    {
        std::cout << (x == 1 ? 0 : n - x + 1);
        return 0;
    }
}