#include <iostream>

int n,r[105],b[105];

int main()
{
    std::cin >> n;
    for(int i = 1;i <= n;i++) std::cin >> r[i];
    for(int i = 1;i <= n;i++) std::cin >> b[i];
    int rs = 0,bs = 0;
    for(int i = 1;i <= n;i++)
    {
        if(r[i] && !b[i]) rs ++;
        else if(!r[i] && b[i]) bs++;
    }
    if(!rs)
    {
        std::cout << -1; return 0;
    }
    std::cout << bs / rs + 1; return 0;
}