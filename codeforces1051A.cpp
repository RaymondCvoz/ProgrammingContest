#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

int upper,lower,digit,n;
std::string s;
int main()
{
    std::cin >> n;
    while (n--)
    {
        upper = lower = digit = 0;
        std::cin >> s;
        for(int i = 0;i < s.length();i++)
        {
            if(isupper(s[i])) upper ++;
            else if(islower(s[i])) lower ++;
            else if(isdigit(s[i])) digit ++;
        }
        //std::cout << upper << " " << lower << " " << digit << "\n";
        for(int i = 0;i < s.length();i++)
        {
            if(!upper || !lower || !digit)
            {
                if(isupper(s[i]) && upper > 1)
                {
                    if(!lower)
                    {
                        s[i] = 'a'; upper --; lower ++;
                    }
                    else if(!digit)
                    {
                        s[i] = '1'; upper --; digit ++;
                    }
                }
                else if(islower(s[i]) && lower > 1)
                {
                    if(!upper)
                    {
                        s[i] = 'A'; lower --; upper ++;
                    }
                    else if(!digit)
                    {
                        s[i] = '1'; lower --; digit ++;
                    }
                }
                else if(isdigit(s[i]) && digit > 1)
                {
                    if(!upper)
                    {
                        s[i] = 'A'; digit --; upper ++;
                    }
                    else if(!lower)
                    {
                        s[i] = 'a'; digit --; lower ++;
                    }
                }
            }
        }
        std::cout << s << "\n";
    }
    return 0;
}