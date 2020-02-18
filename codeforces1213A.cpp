#include <bits/stdc++.h>
#define LL long long
const int lens = 1e6;

int main()
{
    int n,odd = 0,even = 0;
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int tmp;
        std::cin >> tmp;
        if(tmp % 2) even++;
        else odd ++;
    }
    std::cout << (even > odd ? odd : even);
    return 0;
}
