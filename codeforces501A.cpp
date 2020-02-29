#include <bits/stdc++.h>

long long a,b,c,d;
int main()
{
    std::cin >> a >> b >> c >> d;
    long long x = std::max(3 * a / 10,a - a / 250 * c);
    long long y = std::max(3 * b / 10,b - b / 250 * d);
    if(x > y) std::cout << "Misha";
    else if(x < y) std::cout << "Vasya";
    else std::cout << "Tie";
    return 0;
}