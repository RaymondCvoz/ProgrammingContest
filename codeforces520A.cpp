#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string s;
int ans[26];

int main()
{
    int x;
    std::cin >> x;
    std::cin >> s;
    for(int i = 0;i < s.length();i++)
    {
        s[i] = tolower(s[i]);
        if(!ans[s[i] - 'a']) ans[s[i] - 'a'] = 1;
    }
    for(int i = 0;i < 26;i++)
    {
        if(!ans[i])
        {
            std::cout << "NO"; return 0;
        }
    }
    std::cout << "YES"; return 0;
}