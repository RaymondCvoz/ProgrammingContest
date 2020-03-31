#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>

class node
{
    public:
    int x,y;
    node *f;
    node (int x,int y,node* f)
    {
        this -> x = x;
        this -> y = y;
        this -> f = f;
    }
};

std::queue <node*> q;
int m[5][5],p[5][5],vis[5][5];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool judge(int x)
{
    return x >= 0 && x < 5;
}

int main()
{
    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            std::cin >> m[i][j];
            p[i][j] = 1e9;
        }
    }
    p[0][0] = 1;
    q.push(new node(0,0,NULL));
    node *res = NULL;
    while(!q.empty())
    {
        node *cnt = res = q.front(); 
        q.pop();
        int x = cnt -> x,y = cnt -> y;
        if(x == 4 && y == 4) break;
        for(int i = 0;i < 4;i++)
        {
            if(judge(x + dx[i]) && judge(y + dy[i]) && p[x + dx[i]][y + dy[i]] > p[x][y] + 1 && !vis[x + dx[i]][y + dy[i]] && m[x + dx[i]][y + dy[i]] == 0)
            {
                q.push(new node(x + dx[i],y + dy[i],cnt));
                p[x + dx[i]][y + dy[i]] = p[x][y] + 1;
                vis[x + dx[i]][y + dy[i]] = 1;
            }
        }
    }
    std::stack <node*> s;
    // std::cout << res -> x << " " << res -> y << "\n";
    s.push(new node(res -> x,res -> y,NULL));

    while(res -> f != NULL)
    {
        res = res -> f;
        s.push(new node(res -> x,res -> y,NULL));
        // std::cout << res -> x << " " << res -> y << "\n";
    }
    while(!s.empty())
    {
        printf("(%d, %d)\n",s.top() -> x,s.top() -> y);
        s.pop();
    }
    return 0;
}