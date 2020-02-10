#include <bits/stdc++.h>
#define LL long long
const LL p = 1e9 + 7;
int main()
{
    std::string s;
    std::cin >> s;
    LL base = 0,num = 0,ans = 0;
    for(LL i = s.length() - 1;i >= 0;i--)
    {
        if(s[i] == 'b') num ++;
        else if(s[i] == 'a' && num)
        {
            ans += num;
            ans %= p;
            //ans += base;
            //ans %= p;
            num = num * 2 % p;
        }
    }
    std::cout << ans;

    return 0;
}