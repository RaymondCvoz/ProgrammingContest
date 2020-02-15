#include <bits/stdc++.h>
#define LL long long


bool judge(std::string s)
{
    std::string a = s;
    std::reverse(a.begin(),a.end());
    if(a == s) return 1;
    return 0;
}
int main()
{   
    int t;
    std::cin >> t;
    while(t--)
    {
        bool flag = 0;
        std::string s;
        std::cin >> s;
        if(!judge(s))
        {
            std::cout << s << "\n"; continue;
        }
        for(int i = 0;i < s.length() - 1;i++)
        {
            std::swap(s[i],s[i + 1]);
            if(!judge(s))
            {
                flag = 1;
                std::cout << s << "\n"; break;
            }
        }
        if(!flag)
        std::cout << "-1" << "\n";
    }
    return 0;
}