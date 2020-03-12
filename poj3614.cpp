#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>
const int lens = 100005;

std::priority_queue <int,std::vector<int> ,std::greater<int> > q;
std::pair <int,int> cow[lens],scr[lens];
int C,L,res;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> C >> L;
    for(int i = 1;i <= C;i++)
    {
        std::cin >> cow[i].first >> cow[i].second;
    }
    for(int i = 1;i <= L;i++)
    {
        std::cin >> scr[i].first >> scr[i].second;
    }
    std::sort(cow + 1,cow + C + 1);
    std::sort(scr + 1,scr + L + 1);
    int cnt = 1;
    for(int i = 1;i <= L;i++)
    {
        while(cnt <= C && scr[i].first >= cow[cnt].first)
        {
            q.push(cow[cnt].second);
            cnt++;
        }
        while(!q.empty() && scr[i].second > 0)
        {
            if(q.top() >= scr[i].first)
            {
                res++;
                scr[i].second--;
            }
            q.pop();
        }
    }
    std::cout << res;
}