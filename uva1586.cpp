#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <iomanip>
#include <cstdio>

std::string s;
int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {    /* code */
        std::cin >> s;
        double ans = 0;
        for(int i = 0;i < s.length();i++)
        {
            if(isalpha(s[i]))
            {
                int j = i;
                double res = 0;
                if(j == s.length() - 1 || isalpha(s[j + 1])) res = 1;
                else
                {
                    while(isdigit(s[j + 1]))
                    {
                        res *= 10; res += s[j + 1] - '0'; j += 1;
                    }
                }
                if(s[i] == 'C') ans += res * 12.010;
                if(s[i] == 'O') ans += res * 16.000;
                if(s[i] == 'N') ans += res * 14.010;
                if(s[i] == 'H') ans += res * 1.008;
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}