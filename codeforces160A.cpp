#include <iostream>
#include <algorithm>

const int lens = 1e6;
int a[lens];

bool cmp(int a,int b)
{
    return a > b;
}

int main()
{
    int n,sum = 0;
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> a[i];
        sum += a[i];
    }
    std::sort(a + 1,a + n + 1,cmp);
    int cnt = 0,ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if(cnt <= (sum) / 2)
        {
            ans ++;
            cnt += a[i];
        }
    }
    std::cout << ans;
    return 0;
}