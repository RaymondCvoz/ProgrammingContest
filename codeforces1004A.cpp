#include <iostream>

int main()
{
    int n,q,a[101];
    std::cin >> n >> q;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> a[i];
    }
    int ans = 2;
    for(int i = 1;i <= n - 1;i++)
    {
        if(a[i] + q < a[i + 1] - q) ans += 2;
        else if(a[i] + q == a[i + 1] - q) ans += 1;
    }
    std::cout << ans;
    return 0;
}