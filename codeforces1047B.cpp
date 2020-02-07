#include <iostream>
#include <algorithm>

int x,y;
int main()
{
    int n;
    std::cin >> n;
    while(n--)
    {
        int a,b;
        std::cin >> a >> b;
        if(a + b > x + y)
        {
            x = std::max(a,b);
            y = std::min(a,b);
        }
    }
    std::cout << x + y;
    return 0;
}