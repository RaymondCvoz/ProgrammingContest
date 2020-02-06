#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
    int a,b;
    std::cin >> a >> b;
    if(a == b)
    {
        std::cout << "infinity"; return 0;
    }
    int ans = 0,num = 0;
    int tmp = a - b;
    for(int i = 1;i <= sqrt(tmp);i++)
    {
        if(tmp % i == 0)
        {
            int x = tmp / i;
            if(x != i)
            {
                if(x > b) ans ++;
                if(i > b) ans ++;
            }
            else
            {
                if(x > b) ans ++;
            }
        }
    }
    std::cout << ans;
    return 0;
}