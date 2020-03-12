#include <bits/stdc++.h>

long long n;
int main()
{
    std::cin >> n;
    long long sum = n * (n + 1) >> 1;
    if(sum & 1) std::cout << 1;
    else std::cout << 0; 
    return 0;
}