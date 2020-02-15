#include <bits/stdc++.h>
#define LL long long

LL a,b,x,w,c,ans;

int main()
{
    std::cin >> a >> b >> w >> x >> c;
    LL L = 0,R = LLONG_MAX - 1;
    while(L <= R)
    {
        LL a1 = a,b1 = b,x1 = x,w1 = w,c1 = c;
        LL mid = (L + R) / 2;
        c1 -= mid;
        b1 -= mid * x1;
        LL tot = b1 < 0 ? (-b1 + w1 - 1) / w1 : 0;
        a1 -= tot;
        if(c1 <= a1) R = mid - 1;
        else L = mid + 1;
    }
    std::cout << R + 1;
    return 0;
}