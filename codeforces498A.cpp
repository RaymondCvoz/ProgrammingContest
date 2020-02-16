#include <bits/stdc++.h>

int main()
{
    long long x1,y1,x2,y2,n,a,b,c,ans = 0;
    std::cin >> x1 >> y1 >> x2 >> y2 >> n;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> a >> b >> c;
        if((a * x1 + b * y1 + c > 0 && a * x2 + b * y2 + c < 0) || (a * x1 + b * y1 + c < 0 && a * x2 + b * y2 + c > 0)) ans ++;
    }
    std::cout << ans;
    return 0;
}