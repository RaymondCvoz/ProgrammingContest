#include <bits/stdc++.h>

int cnt,num[2005],n,sum,L,R;
int main()
{
    std::cin >> n;
    n *= 2;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> num[i];
        sum += num[i];
        if(i <= n / 2) L += num[i];
        else R += num[i];
    }
    if(L != R)
    {
        for(int i = 1;i <= n;i++) std::cout << num[i] << " ";
        return 0;
    }
    if(sum & 1)
    {
        std::cout << -1 ; return 0;
    }
    else
    {
        for(int i = 1;i <= n / 2;i++)
        {
            for(int j = n / 2 + 1;j <= n;j++)
            {
                if(num[i] != num[j])
                {
                    std::swap(num[i],num[j]);
                    for(int i = 1;i <= n;i++)
                    {
                        std::cout << num[i] << " "; 
                    }
                    return 0;
                }
            }
        }
    }
    std::cout << -1; return 0;
}a