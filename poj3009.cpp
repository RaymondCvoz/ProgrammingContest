#include <iostream>
#include <algorithm>
#include <cstring>

const int lens = 25;
int map[lens][lens],w,h,tx,ty,ans,sx,sy;

int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
int check(int x,int y)
{
    if(map[x][y] == 0 || map[x][y] == 2) return 1;
    else if(map[x][y] == -1 || map[x][y] == 1) return 2;
    else return 3;
}

void dfs(int x,int y,int step)
{
    //std::cout << "in" << "\n";
    if(x == tx && y == ty || step > 10)
    {
        if(ans > step) ans = step;
    }
    else
    {
        for(int i = 0;i < 4;i++)
        {
            int xx = x;
            int yy = y;
            if(check(xx + dx[i],yy + dy[i]) != 2)
            {

                while(check(xx + dx[i],yy + dy[i]) == 1)
                {
                    xx += dx[i]; yy += dy[i];
                }
                if(map[xx + dx[i]][yy + dy[i]] == 1)
                {
                    map[xx + dx[i]][yy + dy[i]] = 0;
                    step ++;
                    dfs(xx,yy,step);
                    step --;
                    map[xx + dx[i]][yy + dy[i]] = 1;
                }
                else if(map[xx + dx[i]][yy + dy[i]] == 3)
                {
                    step ++;
                    dfs(xx + dx[i],yy + dy[i],step);
                    step --;
                }
            }
        }
    }
}

int main()
{
    std::cin >> w >> h;
    while(w && h)
    {
        memset(map,-1,sizeof(map));
        sx = sy = tx = ty = 0;
        for(int i = 1;i <= h;i++)
        {
            for(int j = 1;j <= w;j++)
            {
                std::cin >> map[i][j];
                if(map[i][j] == 2)
                {
                    sx = i;
                    sy = j;
                }
                if(map[i][j] == 3)
                {
                    tx = i;
                    ty = j;
                }
            }
        }
        ans = 0x7fffffff;
        dfs(sx,sy,0);
        if(ans > 10) std::cout << -1 << "\n";
        else std::cout << ans << "\n";
        std::cin >> w >> h;
    }    
}