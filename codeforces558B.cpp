#include <iostream>
#include <algorithm>

const int lens = 1e6 + 1;
int n;
int a[lens];

struct P
{
    int idx,val,L,R,vis;
}num[lens];

bool cmp(P a,P b)
{
    return a.val > b.val || (a.val == b.val && a.R - a.L < b.R - b.L);
}

int main()
{
    int flag = 0,max = -1,tot = -1;
    std::cin >> n;
    //for(int i = 0;i < lens;i++) num[i].idx = i;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> a[i];
        num[a[i]].val ++;
        if(!num[a[i]].vis)
        {
            num[a[i]].L = i;
            num[a[i]].vis = 1;
        }
        num[a[i]].R = std::max(num[a[i]].R,i);
        max = std::max(a[i],max);
    }
  //  std::cout << num[1].val << " " << num[2].val << "\n";
    std::sort(num + 1,num + max + 1,cmp);
    std::cout << num[1].L  << " " <<  num[1].R;
    return 0;
}