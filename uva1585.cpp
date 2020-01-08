#include <iostream>
#include <algorithm>
#include <string>

std::string s;
int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {    /* code */
        std::cin >> s;
        int cnt = 1,ans = 0;
        for(int i = 0;i < s.length();i++)
        {
            if(s[i] == 'O')
            {
                ans += cnt; cnt ++;
            }
            else cnt = 1;
        }
        std::cout << ans << "\n";
    }
    return 0;
}