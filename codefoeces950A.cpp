#include <bits/stdc++.h>

int l,r,a;
int main()
{
    std::cin >> l >> r >> a;
    if(l > r) std::swap(l,r);
    if(r - l >= a) 
    {
       l += a;
       a = 0;
    }
    else
    {
        int tmp = r - l;
        l += tmp;
        a -= tmp;
    }
    std::cout << std::min(l,r) * 2 + a / 2 * 2;
    return 0;
}