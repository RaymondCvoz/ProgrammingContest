#include <iostream>
#include <string>

std::string s;

bool less(std::string s,int p,int q)
{
    int n = s.length();
    for(int i = 0;i < s.length();i++)
    {
        if(s[(p + i) % n] != s[(q + i) % n])
            return s[(p + i) % n] < s[(q + i % n)];
    }
    return false;
}

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        std::cin >> s;
        int ans = 0;
        for(int i = 0;i < s.length();i++)
        {
            if(less(s,i,ans)) ans = i;
        }
        for(int i = 0;i < s.length();i++)
        {
            std::cout << s[(ans + i) % s.length()];
        }
        std::cout << "\n";
    }
}