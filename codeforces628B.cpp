#include <bits/stdc++.h>
#define LL long long

int c[(int)1e6];
int main()
{
    std::ios::sync_with_stdio(0);
    std::string s;
    std::cin >> s;
    LL ans = 0;
    for(int i = s.length() - 1;i >= 0;i--)
    {
        if((s[i] - '0') % 4 == 0) ans += 1;
        if(i - 1 != -1)
        {
            if(((s[i - 1] - '0') * 10 + s[i] - '0') % 4 == 0) ans += i;
        }
    }
    std::cout << ans;
    return 0;
}