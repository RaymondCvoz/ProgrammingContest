#include <iostream>
#include <algorithm>

int main()
{
    int n,a,b;
    std::cin >> n >> a >> b;
    int ans = 0;
    for(int i = 1;i < n;i++)
    {
        ans = std::max(ans,std::min(a / i,b / (n - i)));
    }
    std::cout << ans;
    return 0;
}