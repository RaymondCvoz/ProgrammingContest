#include <iostream>
#include <algorithm>
#include <string>

std::string s;
int main()
{
    int n,x = 0,y = 0,px = 0,py = 0;
    std::cin >> n >> s;
    int ans = 0;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == 'U')
        {
            if(px > py && y + 1 > x)
            {
                ans ++;   
            }
            px = x; py = y;
            y += 1;
        }
        if(s[i] == 'R')
        {
            if(px < py && x + 1 > y)
            {
                ans ++;
            }
            px = x; py = y;
            x += 1;
        }
    }
    std::cout << ans;
    return 0;
}