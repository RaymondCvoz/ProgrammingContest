#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::string s;
    long long n,res = 0;
    std::cin >> n >> s;
    for(int i = 0;i < s.length();i++)
    {
        if((s[i] - '0') % 2 == 0)
        {
            res += i + 1;
        }
    }    
    std::cout << res;
    return 0;
}