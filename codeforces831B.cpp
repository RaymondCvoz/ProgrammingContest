#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <cstdio>

int main()
{
    std::string s,t,v;
    std::cin >> s >> t >> v;
    for(int i = 0;i < v.length();i++)
    {
        if(isdigit(v[i])) printf("%c",v[i]);
        else for(int j = 0;j < s.length();j++)
        {
            if(tolower(v[i]) == s[j])
            {
                if(islower(v[i])) printf("%c",t[j]);
                else if(isupper(v[i])) printf("%c",toupper(t[j]));
            }
        }
    }
    return 0;
}