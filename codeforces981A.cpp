#include <bits/stdc++.h>

std::string s;
bool judge(std::string s)
{
    std::string x = s;
    std::reverse(s.begin(),s.end());
    if(x == s) return 1;
    return 0;
}

int main()
{
    std::cin >> s;
    int lens = 0;
    for(int i = 0;i < s.length();i++)
    {
        for(int j = i;j < s.length();j++)
        {
            std::string tmp = "";
            for(int k = i;k <= j;k++)
            {
                tmp += s[k];
            }
            if(!judge(tmp))
            {
                int x = tmp.length();
                lens = std::max(lens,x);
            }
        }
    }
    std::reverse(s.begin(),s.end());
    for(int i = 0;i < s.length();i++)
    {
        for(int j = i;j < s.length();j++)
        {
            std::string tmp = "";
            for(int k = i;k <= j;k++)
            {
                tmp += s[k];
            }
            if(!judge(tmp))
            {
                int x = tmp.length();
                lens = std::max(lens,x);
            }
        }
    }
    std::cout << lens;
    return 0;
}