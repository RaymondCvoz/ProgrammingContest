#include <iostream>
#include <sstream>
#include <string>
#include <set>

std::set <std::string> dict;

int main()
{
    std::string s,buff;
    while(std::cin >> s)
    {
        for(int i = 0;i < s.length();i++)
        {
            if(isalpha(s[i])) s[i] = tolower(s[i]);
            else s[i] = ' ';
        }
        std::stringstream ss(s);
        while(ss >> buff) dict.insert(buff);
    }
    for(std::set <std::string>::iterator it = dict.begin(); it != dict.end();it++) std::cout << *it << "\n";
    return 0;
}