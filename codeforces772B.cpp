#include <bits/stdc++.h>

const int lens = 1e4 + 1;
class E
{
    public:
    double st_x,st_y,mid_x,mid_y,ed_x,ed_y;
}edge[lens];

double dis(double x1,double y1,double x2,double y2,double x0,double y0)
{
    return sqrt(pow((x0 - x1) * (y2 - y1) + (y0 - y1) * (x1 - x2),2) / ((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1)));
}

int main()
{
    int n;
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> edge[i].st_x >> edge[i].st_y;
        edge[i - 1].ed_x = edge[i].st_x;
        edge[i - 1].ed_y = edge[i].st_y;
    }
    edge[n].ed_x = edge[1].st_x; edge[n].ed_y = edge[1].st_y;
    
    for(int i = 1;i <= n;i++) 
    {
        edge[i].mid_x = (edge[i].st_x + edge[i].ed_x) / 2;
        edge[i].mid_y = (edge[i].st_y + edge[i].ed_y) / 2;
    }
    //std::cout << (dis(1,0,0,1,-1,-1)) << "\n";
    double ans = 1e9;
    for(int i = 2;i <= n;i++)
    {
        ans = std::min(ans,dis(edge[i - 1].mid_x,edge[i - 1].mid_y,edge[i].mid_x,edge[i].mid_y,edge[i].st_x,edge[i].st_y));
    }
    ans = std::min(ans,dis(edge[1].mid_x,edge[1].mid_y,edge[n].mid_x,edge[n].mid_y,edge[1].st_x,edge[1].st_y));
    printf("%.8lf",ans);
}