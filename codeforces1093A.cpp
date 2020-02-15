#include <bits/stdc++.h>
#define LL long long

int main()
{   
    int t;
    std::cin >> t;
    while(t--)
    {
        int x;
        std::cin >> x;
        if(x % 7 == 0)
        {
            std::cout << x / 7 << "\n";
        }
        else
        {
            std::cout << x / 7 + 1 << "\n";
        }
    }
    return 0;
}