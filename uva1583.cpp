#include <iostream>
#include <algorithm>

const int maxn = 1e5 + 6;
int ans[maxn << 1],n;

int main()
{
    for(int i = 1;i <= maxn - 1;i++)
    {
        int x = i,y = i;
        while(x)
        {
            y += x % 10; x /= 10;
        }
        if(ans[y] > i || ans[y] == 0) ans[y] = i;
    }
    std::cin >> n;
    while(n--)
    {
        int x;
        std::cin >> x;
        std::cout << ans[x] << "\n";
    }
    return 0;
}