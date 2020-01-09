#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
int n;
int ans[10];

int main()
{
    std::cin >> n;
    while(n--)
    {
        std::string s = "";
        memset(ans,0,sizeof(ans));
        int cnt; std::cin >> cnt;
        for(int i = 1;i <= cnt;i++)
        {
            std::stringstream ss; std::string tmp = "";
            ss << i;
            ss >> tmp;
            s += tmp;
        }
        for(int i = 0;i < s.length();i++)
        {
            ans[s[i] - '0'] += 1;
        }
        for(int i = 0;i <= 8;i++) std::cout << ans[i] << " "; std::cout << ans[9];
        std::cout << "\n";
    }
    return 0;
}