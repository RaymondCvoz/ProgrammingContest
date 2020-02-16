#include <bits/stdc++.h>

std::string s,t;
int main()
{
    int a,b; std::cin >> a >> b;
    std::cin >> s >> t;
    if(s.length() > t.length() + 1)
    {
        std::cout << "NO"; return 0;
    }
    bool flag = 0;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '*')
        {
            flag = 1; break;
        }
    }
    if(!flag && s.length() < t.length())
    {
        std::cout << "NO"; return 0;
    }
    int ptr = 0;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '*') break;
        if(s[i] != t[ptr])
        {
            std::cout << "NO"; return 0;
        }
        ptr++;
    }
    ptr = t.length() - 1;
    for(int i = s.length() - 1;i >= 0;i--)
    {
        if(s[i] == '*') break;
        if(s[i] != t[ptr])
        {
            std::cout << "NO"; return 0;
        }
        ptr--;
    }
    std::cout << "YES";
    return 0;
}