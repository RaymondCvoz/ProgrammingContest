#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

int main()
{
    int n,k;
    std::string s,ans = "";
    std::cin >> n >> k;
    std::cin >> s;
    ans = s;
    int res = 0;
    for(int i = 0;i < k;i++)
    {
        for(int j = i;j < n;j += k)
        {
            ans[j] = s[i];
        }
        res *= 10;
        res += s[i] - '0';
    }
    if(ans >= s)
    {
        std::cout << n << "\n" << ans; return 0;
    }

    std::cout << n << "\n";
    for(int i = k - 1;i >= 0;i--)
    {
        if(ans[i] == '9') ans[i] = '0';
        else
        {
            ans[i] ++;
            break;
        }
    }
    /*res += 1;
    std::stringstream ss("");
    ss << res;
    ss >> ans;
    //std::cout << ans << "#\n";*/
    int j = 0;
    for(int i = 0;i < n;i++)
    {
        std::cout << ans[j]; j++;
        if(j == k) j = 0;
    }
    return 0;
}