#include <bits/stdc++.h>
#define LL long long 

LL q,L,R;

int main()
{
    std::cin >> q;
    while(q--)
    {
        std::cin >> L >> R;
        LL t = R - L + 1;
        if(t & 1)
        {
            LL f = (L & 1 ? -1 : 1) * L;
            std::cout << t / 2 * (L & 1 ? -1 : 1) + f << "\n";
        }
        else 
        {
            std::cout << t / 2 * (L & 1 ? 1 : -1) << "\n";
        }
    }
    return 0;
}