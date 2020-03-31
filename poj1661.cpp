#include <iostream>
#include <algorithm>
#include <climits>

class B
{
    public:
    int L,R,H,LM,RM;//左端点，右端点，高度，左端点下落最短时间，右端点下落最短时间
    bool operator < (const B &rhs) const //重载<使sort按H从小到大排序
    {
        return this -> H < rhs.H;
    }
}b[1005];
int n,t,x,y,max;

int main()
{
    std::ios::sync_with_stdio(false);//输入量较大，加速cin
    std::cin >> t;

    while(t--)
    {
        std::cin >> n >> x >> y >> max;
        for(int i = 1;i <= n;i++)
        {
            std::cin >> b[i].L >> b[i].R >> b[i].H;
            b[i].LM = b[i].RM = 1e9;
        }

        std::sort(b + 1,b + n + 1);//按H从小到大排序

        b[0].LM = b[0].RM = 0,b[0].L = -1e9,b[0].R = 1e9,b[0].H = 0;//地板记为b[0]
        b[n + 1].L = b[n + 1].R = x,b[n + 1].LM = b[n + 1].RM = 1e9,b[n + 1].H = y;//初始位置记为b[n+1]

        for(int i = 1;i <= n + 1;i++)//从低向高递推
        {
            for(int j = i - 1;j >= 0;j--)//更新左端点，每块板从高度和它最接近的高度小于等于它的板子往下找
            {
                if(b[j].L <= b[i].L && b[j].R >= b[i].L && b[i].H - b[j].H <= max)//如果当前板左端点下方找到一块板并且高度差合适
                {
                    if(j == 0) b[i].LM = b[i].H;//如果是地板直接把时间更新成高度
                    else b[i].LM = std::min(b[j].LM + b[i].L - b[j].L,b[j].RM + b[j].R - b[i].L) + b[i].H - b[j].H;//不是地板，计算时间
                    break;//找到一块板了，不能坐穿这块板子往下跳，该退出了
                }
            }
            for(int j = i - 1;j >= 0;j--)//更新右端点，方法同上
            {
                if(b[j].L <= b[i].R && b[j].R >= b[i].R && b[i].H - b[j].H <= max)
                {
                    if(j == 0) b[i].RM = b[i].H;
                    else b[i].RM = std::min(b[j].LM + b[i].R - b[j].L,b[j].RM + b[j].R - b[i].R) + b[i].H - b[j].H;
                    break;
                }
            }
        }
        std::cout << b[n + 1].RM << "\n";//起点的最短下落时间,LM RM都一样
    }
    return 0;
}