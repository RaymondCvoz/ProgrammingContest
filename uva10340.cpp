#include <iostream>
#include <algorithm>
#include <string>

void print(std::string s,std::string t)
{
    int count = 0,cnt = 0;
    for(int i = 0;i < t.length();i++)
    {
        if(t[i] == s[cnt])
        {
            cnt ++;
        }
    }
    if(cnt == s.length()) std::cout << "Yes\n";
    else std::cout << "No\n";
    return;
}

int main()
{
    std::string s,t;
    while(std::cin >> s >> t)
    {
        print(s,t);
    }
    return 0;
}