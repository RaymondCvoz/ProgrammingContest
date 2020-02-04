#include <iostream>
#include <algorithm>

int main()
{
    int n,ans = 0;
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            int k = i ^ j;
            int a[3] = {i,j,k};
            std::sort(a,a + 3);
            if(a[0] + a[1] > a[2] && a[2] - a[1] < a[0] && k <= n)
            {
                ans++;
            }
        }
    }
    std::cout << ans / 6;
    return 0;
}