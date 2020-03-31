#include <bits/stdc++.h>
#define LL long long

int main()
{
    LL a,b,t;
    std::cin >> t;
    while(t--)
    {
        std::cin >> a >> b;
        LL diff = abs(a - b);
        if(!diff)
        {
            std::cout << 0 << "\n"; continue; 
        }
        for(LL i = 1;;i++)
        {
            LL sum = i * (i + 1) / 2;
            if(sum >= diff && (sum - diff) % 2 == 0)
            {
                std::cout << i << "\n";
                break;
            }
        }
    }
}