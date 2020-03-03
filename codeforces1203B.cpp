#include<bits/stdc++.h>
#define LL long long

int p[405];
int main()
{   
    int n,q;
    std::cin >> q;
    while(q--)
    {
        std::cin >> n;
        n *= 4;
        for(int i = 1; i <= n;i++)
        {
            std::cin >> p[i];
        }
        std::sort(p + 1,p + n + 1);
        bool f = 1;
        for(int i = 1;i <= n;i++)
        {
            if(i % 2 && p[i] != p[i + 1]) 
            {
                f = 0; break;
            }
        }
        if(!f)
        {
            std::cout << "NO" << "\n"; continue;
        }
        int ptr = n,s = p[1] * p[ptr];
        for(int i = 1;i <= n / 2;i += 2)
        {
            if(s != p[i] * p[ptr]) 
            {
                f = 0; break;
            }
            ptr -= 2;
        }
        if(!f) std::cout << "NO" << "\n";
        else std::cout << "YES" << "\n";
    }
    return 0;
}