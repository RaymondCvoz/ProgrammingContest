#include <bits/stdc++.h>

long long n,h,a,b,k;

int main()
{
    std::cin >> n >> h >> a >> b >> k; 
    while(k--)
    {
        long long sn,sh,tn,th;
        std::cin >> sn >> sh >> tn >> th;
        long long x = 0,tot = 0;
        if(sn == tn)
        {
            std::cout << abs(sh - th) << "\n";
            continue;
        }
        if(sh >= a && sh <= b) x = sh;
        else if(sh < a)
        {
            tot += a - sh;
            x = a;
        }
        else if(sh > b)
        {
            tot += sh - b;
            x = b;
        }
        std::cout << tot + abs(sn - tn) + abs(x - th) << "\n";
    }
    return 0;
}