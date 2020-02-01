#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    int a = 0,b = 0,c = 0,count = 0;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '|') count++;
        if(s[i] == '+') {a = count; count = 0;}
        if(s[i] == '=') {b = count; count = 0;}
        c = count;
    }
    if(c == a + b + 2)
    {
        c -= 1;
        a += 1;
        if(c == 0) {std::cout << "Impossible"; return 0;}
    }
    else if(c == a + b - 2)
    {
        c += 1;
        if(a > b) a -= 1;
        else b -= 1;
        if(a == 0 || b == 0) {std::cout << "Impossible"; return 0;}
    }
    else if(c == a + b){}
    else
    {
        std::cout << "Impossible";
        return 0;
    }
    while(a--) std::cout << '|';
    std::cout << '+';
    while(b--) std::cout << '|';
    std::cout << '=';
    while(c--) std::cout << '|';
    return 0;
}