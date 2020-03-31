#include <iostream>

int main()
{
    int a,b,c,d;
    std::cin >> a >> b >> c >> d;
    if((!a && !d && c) || (a != d)) std::cout << 0;
    else std::cout << 1;
    return 0;
}