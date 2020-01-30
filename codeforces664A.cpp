#include <iostream>
#include <algorithm>
#include <string>

std::string a,b;
int main()
{
    std::cin >> a >> b;
    if(a == b)
    {
        std::cout << a;
        return 0;
    }
    else 
    {
        std::cout << 1;
        return 0;
    }
}