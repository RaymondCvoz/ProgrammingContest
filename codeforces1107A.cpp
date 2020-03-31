#include <bits/stdc++.h>
#define LL long long

std::string s;
int main()
{
    int q;
    std::cin >> q;
    while(q--)
    {
        int n;
        std::cin >> n >> s;
        if(n == 2 && s[0] >= s[1]) std::cout << "NO\n";
        else
        {
            puts("YES");
            std::cout << 2 << "\n" << s[0] << " " << s.substr(1,s.length() - 1) << "\n";
        }
    }
}