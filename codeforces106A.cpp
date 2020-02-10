#include <bits/stdc++.h>

std::string a,b,trump;

int main()
{
    std::cin >> trump >> a >> b;`
    if(a[0] == 'T') a[0] = 'A';
    else if(a[0] == 'J') a[0] = 'B';
    else if(a[0] == 'Q') a[0] = 'C';
    else if(a[0] == 'K') a[0] = 'D';
    else if(a[0] == 'A') a[0] = 'E';
    if(b[0] == 'T') b[0] = 'A';
    else if(b[0] == 'J') b[0] = 'B';
    else if(b[0] == 'Q') b[0] = 'C';
    else if(b[0] == 'K') b[0] = 'D';
    else if(b[0] == 'A') b[0] = 'E';
    if(a[1] == b[1])
    {
        if(a[0] > b[0])
        {
            std::cout << "YES"; return 0;
        }
        else
        {
            std::cout << "NO";  return 0;
        }
    }
    else
    {
        if(a[1] == trump[0]) std::cout << "YES";
        else std::cout << "NO";
        return 0;
    }
}