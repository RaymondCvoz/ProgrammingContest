#include <iostream>
#include <algorithm>
#include <string>

#define lens 105
std::string land[lens];
int n,m;

void dfs(int x,int y)
{
	land[x][y] = '.';
	for(int dx = -1;dx <= 1;dx++)
	{
		for(int dy = -1;dy <= 1;dy++)
		{
			int nx = x + dx,ny = y + dy;
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && land[nx][ny] == 'W')
			{
				dfs(nx,ny);
			}
		}
	}
	return;
}

int solve()
{
	int res = 0;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			if(land[i][j] == 'W')
			{
				dfs(i,j);
				res ++;
			}
		}
	}
	return res;
}
int main()
{
	std::cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		std::cin >> land[i];
	}
	std::cout << solve() << std::endl;
	return 0;
}