#include <bits/stdc++.h>

const int lens = 1e4;

int main()
{
    int t,c = 0;
    while(scanf("%d",&t) == 1 && t)
    {
        printf("Scenario #%d\n",++c);
        std::map <int,int> team;
        for(int i = 0;i < t;i++)
        {
            int n,x;
            scanf("%d",&n);
            while(n--) {scanf("%d",&x); team[x] = i;}
        }

        std::queue <int> q,q2[lens];
        while(1)
        {
            int x;
            std::string cmd;
            std::cin >> cmd;
            if(cmd[0] == 'S') break;
            else if(cmd[0] == 'D')
            {
                int t = q.front();
                printf("%d\n",q2[t].front());
                q2[t].pop();
                if(q2[t].empty())
                {
                    q.pop();
                }
            }
            else if(cmd[0] == 'E')
            {
                scanf("%d",&x);
                int t = team[x];
                if(q2[t].empty()) q.push(t);
                q2[t].push(x);
            }
        }
        puts("");
    }
    return 0;
}