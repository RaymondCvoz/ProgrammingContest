#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define lens 1000005

int noe,last[lens],dis[lens],n,s,sum;
struct Edge
{
	int next,to,weight;
}edge[lens];

void addedge(int from,int to,int weight)
{
	noe++;
	edge[noe].to = to;
	edge[noe].weight = weight;
	edge[noe].next = last[from];
	last[from] = noe;
}

int bfs(int s)
{
	int max_dis = 0;
	int it = s;
	std::queue <int> q;
	memset(dis,0,sizeof(dis));
	dis[s] = 0;
	q.push(s);

	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		if(dis[x] > max_dis)
		{
			it = x;
			max_dis = dis[x];
		}
		for(int i = last[x];i;i = edge[i].next)
		{
			if(!dis[edge[i].to])
			{
				dis[edge[i].to] = dis[x] + edge[i].weight;
				q.push(edge[i].to);
			}
		}
	}
	return it;
}

int main()
{
	std::cin >> n >> s;
	//memset(last,0,sizeof(last));
	for(int i = 1;i <= n - 1;i++)
	{
		int u,v,d;
		std::cin >> u >> v >> d;
		sum += d;
		addedge(u,v,d);
		addedge(v,u,d);
	}
	std::cout << sum * 2 - dis[bfs(bfs(s))];
	return 0;
}