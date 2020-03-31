#include <iostream>
#include <algorithm>
const int lens = 105;

int n,m;
int h[lens][lens],f[lens][lens];//h -> 高度，f -> 以i，j为起点的最长路径长度
int dx[4] = {0,1,0,-1};//方向数组，用来枚举四个方向
int dy[4] = {1,0,-1,0};

int dfs(int x,int y)
{
    if(f[x][y]) return f[x][y];//如果被计算过，直接返回答案
    int max = 1;//记录以当前点为起点的最长路径长，至少是1
    for(int i = 0;i < 4;i++)//枚举上下左右每个方向
    {
        int xx = x + dx[i],yy = y + dy[i];
        if(xx >= 1 && xx <= n && yy >= 1 && yy <= m)//判断在不在地图内
        {
            if(h[xx][yy] > h[x][y])//高度比当前高
            {
                max = std::max(dfs(xx,yy) + 1,max);//向这个方向继续搜索，并更新max
            }
        }
    }
    f[x][y] = max;//将结果存下来
    return max;
}

int main()
{

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            std::cin >> h[i][j];
        }
    }
    int res = -1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            res = std::max(res,dfs(i,j));//以每个点作为起点进行搜索，并更新答案
        }
    }
    std::cout << res;
    return 0;
}