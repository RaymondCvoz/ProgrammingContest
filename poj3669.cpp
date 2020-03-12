#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

const int lens = 50005;
int map[305][305];
bool vis[305][305],flag;
int dx[5] = {1,0,-1,0,0},dy[5] = {0,1,0,-1,0};

struct node
{
    int x,y,t;
};

int m;

std::queue <node> q;

bool check(int a,int b)
{
    return (a >= 0 && b >= 0);
}

int bfs()
{
    memset(vis,0,sizeof(vis));
    node st;
    st.x = 0;
    st.y = 0;
    st.t = 0;
    q.push(st);
    vis[st.x][st.y] = 1;
    while(!q.empty())
    {
        node cnt = q.front();
        q.pop();
        if(map[cnt.x][cnt.y] == -1) return cnt.t;

        //vis[cnt.x][cnt.y] = 1;
        for(int i = 0;i < 4;i++)
        {
            node inq;
            inq.x = cnt.x + dx[i];
            inq.y = cnt.y + dy[i];
            inq.t = cnt.t + 1;
            if((inq.x >= 0 && inq.y >= 0) && !vis[inq.x][inq.y])
            {
                if(map[inq.x][inq.y] == -1) return inq.t;
                if(map[inq.x][inq.y] > inq.t)
                {
                    vis[inq.x][inq.y] = 1;
                    q.push(inq);
                }
            }
        }
    }
    return -1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(std::cin >> m)
    {
        memset(map,-1,sizeof(map));
        while(m--)
        {
            int x,y,t;
            std::cin >> x >> y >> t;
            for(int i = 0;i < 5;i++)
            {
                int nx = x + dx[i],ny = y + dy[i];
                if(nx >= 0 && ny >= 0)
                {
                    if(map[nx][ny] == -1) map[nx][ny] = t;
                    else map[nx][ny] = std::min(map[nx][ny],t);
                }
            }
        }
        std::cout << bfs() << std::endl;
    }
    return 0;
}