#include<iostream>
#include<string>
#include<cmath>

long long calc(std::string s)
{
    long long res = 0;
    int lens = s.length();
    for (int i = 0; i < s.length(); i++)
    {
        res += (s[i] - '0') * pow(10, lens - i - 1);
    }
    return res;
}

int main()
{
    std::string s;
    while (std::cin >> s)
    {
        if (s.length() >= 11)
        {
            puts("TAT");
        }
        else
        {
            int cnt = 0;
            long long res = calc(s);
            if (res > 4294967295)
            {
                puts("TAT");
            }
            else
            {
                if (res == 1)
                {
                    puts("1");
                }
                else if (res == 0)
                {
                    puts("TAT");
                }
                else
                {
                    while (res > 1)
                    {
                        res = (int)sqrt(res);
                        cnt++;
                    }
                    printf("%d\n", cnt);
                }
            }
        }
    }
    return 0;
}