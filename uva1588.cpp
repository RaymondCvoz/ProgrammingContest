#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::string s,t;
    while(std::cin >> s >> t)
    {
        if(s.length() < t.length()) std::swap(s,t);
        std::string x = ""; unsigned long ans = 0x7fffffff;
        for(int i = 0;i < t.length();i++)
        {
            x += "0";
        }
        s = x + s;
        s = s + x;
        //std::cout << s << "\n";
        for(int i = 0;i < s.length();i++)
        {
            for(int j = 0;j < t.length();j++)
            {
                if((s[i + j] - '0') + (t[j] - '0') > 3) break;
                if(j == t.length() - 1)
                {
                    //std::cout << "cnt : " << ans << " " << i << "\n";
                    ans = std::min(ans,std::max(s.length() - 2 * x.length(),i < t.length() ? s.length() - i - x.length() : i));
                }
            }
        }
        ans = std::min(ans,s.length() - x.length());
        std::cout << ans << "\n";
    }
    return 0;
}