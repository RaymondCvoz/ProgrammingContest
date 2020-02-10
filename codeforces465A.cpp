#include <bits/stdc++.h>

std::string s;

int main()
{
    int n,carry = 0,ans = 0;
    std::cin >> n >> s;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '1')
        {
            carry = 1;
            ans ++;
        }
        else
        {
            ans++;
            break;
        }
    }
    std::cout << ans;
    return 0;
}