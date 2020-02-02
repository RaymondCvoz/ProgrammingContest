#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    int a = n / 7;
    int b = n % 7;
    int c = 0;
    if(b == 6) c = 1;
    if(b > 2) b = 2;
    std::cout << a * 2 + c << " " << a * 2 + b;
    return 0;
}