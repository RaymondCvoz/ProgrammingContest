#include <iostream>
#include <string>

std::string s;
int n;
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int max = 0;
        std::cin >> n >> s;
        for(int i = 0;i < n;i++)
        {
            if(s[i] == 'A')
            {
                int cnt = i;
                while(cnt + 1 < n && s[cnt + 1] == 'P')
                {
                    max = std::max(max,cnt + 1 - i);
                    cnt++;
                }
            }
        }
        std::cout << max << "\n";
    }
}