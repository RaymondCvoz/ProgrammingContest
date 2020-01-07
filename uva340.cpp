#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
const int lens = 1010;
int n,a[lens],b[lens];

int main()
{
    std::cin >> n; int cal = 0;
    while(n)
    {
        cal++;
        for(int i = 1;i <= n;i++)
        {
            std::cin >> a[i];
        }
        std::cout << "Game " << cal << ":\n";
        int judge = 0;
        while(1)
        {
            for(int i = 1;i <= n;i++)
            {
                std::cin >> b[i]; 
                if(b[i]) judge = 1;
            }
            int same = 0,num1[10],num2[10];
            if(judge)
            {
                memset(num1,0,sizeof(num1)); memset(num2,0,sizeof(num2));
                for(int i = 1;i <= n;i++)
                {
                    if(a[i] == b[i]) same ++;
                    num1[a[i]] ++; num2[b[i]] ++;
                }
            }
            else break;
            int res = 0;
            for(int i = 0;i <= 9;i++) res += std::min(num1[i],num2[i]); res -= same;
            std::cout << "    (" << same << "," << std::max(res,0) << ")\n";
            judge = 0;
        }
        std::cin >> n;
    }
}