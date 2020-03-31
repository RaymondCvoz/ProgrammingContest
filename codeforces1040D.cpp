#include <bits/stdc++.h>
#define LL long long

std::string s;
LL n,k;
int main()
{
    srand(time(NULL));
    std::cin >> n >> k;
    LL L = 1,R = n;
    while(1)
    {
        LL x = rand() % (R - L + 1) + L;
        LL M = L + R >> 1;
        if(R - L <= 5 * k)
        {
            std::cout << x << " " << x << std::endl;
            std::cin >> s;
            if(s == "Bad" || s == "Yes")
            {
                return 0;
            }
            L -= 2 * k; if(L < 1) L = 1;
            R += 2 * k; if(R > n) R = n;
            //L = std::max(1LL,L - 2 * k);
            //R = std::min(n,R + 2 * k);
        }
        else
        {
            std::cout << L << " " << M << std::endl;
            std::cin >> s;
            if(s == "Bad")
            {
                return 0;
            }
            if(s == "Yes")
            {
                L -= k; if(L < 1) L = 1;
                R = M + k; if(R > n) R = n;
                //L = std::max(1LL,L - k);
                //R = std::min(n,M + k);
            }
            if(s == "No")
            {
                L = M + 1 - k; if(L < 1) L = 1;
                R += k; if(R > n) R = n;
                //L = std::max(1LL,M + 1 - k);
                //R = std::min(n,R + k);
            }
        }
    }
    return 0;
}