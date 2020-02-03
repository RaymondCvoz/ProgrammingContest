#include <iostream>
#include <algorithm>
#include <cstdio>

const int lens = 1005;

class building
{
    public:
    int id;
    double x,y,w,d,h;
    bool operator < (const building &rhs) const
    {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
}b[lens];

int n;
double x[lens * 2];

bool cover(int i,double mx)
{
    return b[i].x <= mx && b[i].x + b[i].w >= mx;
}

bool visible(int i,double mx)
{
    if(!cover(i,mx)) return false;
    for(int k = 0;k < n;k++)
    {
        if(b[k].y < b[i].y && b[k].h >= b[i].h && cover(k,mx)) return false;
    }
    return true;
}

int main()
{
    int cnt = 0;
    while(std::cin >> n && n)
    {
        for(int i = 0;i < n;i++)
        {
            std::cin >> b[i].x >> b[i].y >> b[i].w >> b[i].d >> b[i].h;
            x[i * 2] = b[i].x;
            x[i * 2 + 1] = b[i].x + b[i].w;
            b[i].id = i + 1;
        }
        std::sort(b,b + n);
        std::sort(x,x + n * 2);
        int m = std::unique(x,x + n * 2) - x;

        if(cnt++) std::cout << "\n";
        printf("For map #%d, the visible buildings are numbered as follows:\n%d",cnt,b[0].id);
        for(int i = 1;i < n;i++)
        {
            bool vis = 0;
            for(int j = 0;j < m - 1;j++)
            {
                if(visible(i,(x[j] + x[j + 1]) / 2))
                {
                    vis = 1;
                    break;
                }
            }
            if(vis) std::cout << " " << b[i].id;
        }
        std::cout << "\n";
    }
    return 0;
}