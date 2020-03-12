#include <iostream>
#include <stack>
int a,b,c;
std::stack <int> x,y,z;
int main()
{
    std::cin >> a >> b;
    c = a + b;
    while(a)
    {
        if(a % 10 != 0) x.push(a % 10);
        a /= 10;
    }
    while(b)
    {
        if(b % 10 != 0) y.push(b % 10);
        b /= 10;
    }
    while(c)
    {
        if(c % 10 != 0) z.push(c % 10);
        c /= 10;
    }
    a = b = c = 0;
    while(!x.empty())
    {
        a *= 10; a += x.top(); x.pop();
    }
    while(!y.empty())
    {
        b *= 10; b += y.top(); y.pop();
    }
    while(!z.empty())
    {
        c *= 10; c += z.top(); z.pop();
    }
    if(a + b == c) std::cout << "YES";
    else std::cout << "NO";
    return 0; 
}