#include <iostream>
#include <string>

int main()
{
    int n; std::string s;
    std::cin >> n >> s;
    int ans = n;
    for(int i = 1;i <= n;i++)
    {
        if(i + i <= n && s.substr(0,i) == s.substr(i,i)) ans = n - i + 1;
    }
    std::cout << ans;
    return 0;
}