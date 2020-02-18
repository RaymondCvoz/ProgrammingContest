#include <bits/stdc++.h>
#define LL long long
const int lens = 1e6;

int p[lens];
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int n,ans = 0;
        std::cin >> n;
        for(int i = 1;i <= n;i++) std::cin >> p[i];
        int cnt = p[n];
        for(int i = n;i >= 1;i--)
        {
            if(p[i] < cnt) cnt = p[i];
            else if(p[i] > cnt) ans++;
           // std::cout << p[i] << " " << cnt << "\n";
        }
        std::cout << ans << "\n";
    }
    return 0;
}
