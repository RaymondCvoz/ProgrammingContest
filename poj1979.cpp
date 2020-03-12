#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <string>
#include <queue>
#include <cstring>

const int lens = 21;
int w,h,num;
char map[lens][lens];
bool vis[lens][lens];
std::string s[lens];
std::pair <int,int> pos;
std::queue <std::pair <int,int> > q;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};

bool valid(int x,int y,int w,int h)
{
    if(x >= 0 && x < h && y >= 0 && y < w && map[x][y] == '.')
    {
        //std::cout << "success ";
        return 1;
    }
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> w >> h;
    while(w && h)
    {
        int tot = 0;
        memset(vis,0,sizeof(vis));
        while(!q.empty()) q.pop();
        int x = 0,y = 0;
        for(int i = 0;i < h;i++)
        {
            std::cin >> s[i];
        }
        for(int i = 0;i < h;i++)
        {
            for(int j = 0;j < w;j++)
            {
                map[i][j] = s[i][j];
                if(map[i][j] == '@')
                {
                    x = i; y = j;
                }
            }
        }
        //std::cout << x << " " << y << std::endl;
        pos.first = x; pos.second = y;
        q.push(pos);
        while(!q.empty())
        {
            tot++;
            pos = q.front();
            q.pop();
            for(int i = 0;i < 4;i++)
            {
                int xx = pos.first + dx[i];
                int yy = pos.second + dy[i];
                if(valid(xx,yy,w,h) && !vis[xx][yy])
                {
                    std::pair <int,int> cnt;
                    cnt.first = xx;
                    cnt.second = yy;
                    vis[cnt.first][cnt.second] = 1;
                    q.push(cnt);
                }
            }
        }
        std::cout << tot << "\n";
        std::cin >> w >> h;
    }
}