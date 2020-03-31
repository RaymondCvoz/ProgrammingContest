#include <bits/stdc++.h>

int t;
std::string p,n;

int main()
{
    std::cin >> t;
    while(t--)
    {
        bool flag = 0;
        std::cin >> p >> n;
        std::sort(p.begin(),p.end());
        for(int i = 0;i + p.length() - 1 < n.length();i++)
        {
            std::string tmp = n.substr(i,p.length());
            std::sort(tmp.begin(),tmp.end());
            if(tmp == p)
            {
                flag = 1;
                std::cout << "YES" << "\n";
                break;
            }
        }
        if(!flag) std::cout << "NO" << "\n";
    }
    return 0;
}