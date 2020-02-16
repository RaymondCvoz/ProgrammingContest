#include <bits/stdc++.h>

std::string s[120];

int main()
{
    int n,m;
    std::cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        std::cin >> s[i];
    }

    for(int i = 0;i < n;i++)
    {
        int tot = 0,x = -1,y = -1;
        for(int j = 0;j < m;j++)
        {
            if(s[i][j] == 'B')
            {
                if(x == -1){x = j ,y = i;};
                tot++;
            }
        }
        if(x != -1)
        {
            std::cout << y + tot / 2 + 1<< " " << x + tot / 2 + 1;
            return 0;
        }
    }
}