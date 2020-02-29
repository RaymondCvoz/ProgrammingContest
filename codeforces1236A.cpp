#include <bits/stdc++.h>
#define LL long long

const int lens = 101;
bool p[lens];

int main()
{
    std::ios::sync_with_stdio(0);
    int t;
    std::cin >> t;
    while(t--)
    {

        int a,b,c,ans = 0;
        std::cin >> a >> b >> c;
        while(c >= 2 && b)
        {
            b -= 1;
            c -= 2;
            ans += 3;
        }
        while(b >= 2 && a)
        {
            a -= 1;
            b -= 2;
            ans += 3;
        }
        std::cout << ans << "\n";
    }
    return 0;
}