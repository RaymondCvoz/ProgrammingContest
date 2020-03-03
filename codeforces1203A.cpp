#include<bits/stdc++.h>
#define LL long long

int p[205];
int main()
{   
    int n,q;
    std::cin >> q;
    while(q--)
    {
        int pos,min = INT_MAX;
        std::cin >> n;
        for(int i = 1;i <= n;i++)
        {
            std::cin >> p[i];
            if(p[i] < min)
            {
                min = p[i];
                pos = i;
            }
        }
        int tot = 0,cnt = pos;
        while(1)
        {
            tot++;
            int next = cnt + 1;
            if(next == n + 1) next = 1;
            if(p[next] != p[cnt] + 1 || tot == n) break;
            cnt ++;
            if(cnt == n + 1) cnt = 1;

        }
        if(tot == n)
        {
            std::cout << "YES" << "\n"; continue;
        }
        tot = 0,cnt = pos;
        while(1)
        {
            tot++;
            int next = cnt - 1;
            if(next == 0) next = n;
            if(p[next] != p[cnt] + 1 || tot == n) break;
            cnt --;
            if(cnt == 0) cnt = n;
        }
        if(tot == n) std::cout << "YES" << "\n";
        else std::cout << "NO" << "\n";
    }
    return 0;
}