#include <iostream>

const int lens = 1e5 + 1;
int num[lens];
int main()
{
    int n,q;
    std::cin >> n >> q;
    for(int i = 1;i <= n;i++) num[i] = i;
    int L = 1,R = n;
    int cnt = 1;
    while(q--)
    {
        if(cnt & 1) 
        {
            std::cout << num[L] << " ";
            L++;
        }
        else
        {
            std::cout << num[R] << " ";
            R--;
        }
        cnt++;
    }
    if(cnt & 1) for(int i = R;i >= L;i--) std::cout << num[i] << " ";
    else for(int i = L;i <= R;i++) std::cout << num[i] << " ";
    return 0;
}