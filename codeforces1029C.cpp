#include <bits/stdc++.h>

const int lens = 3 * 1e5 + 5;
class Segment
{
    public:
    int L,R,tag;
}s[lens];

bool cmpL(Segment a,Segment b)
{
    return a.L > b.L;
}

bool cmpR(Segment a,Segment b)
{
    return a.R < b.R;
}

int main()
{
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    int flag = 0;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> s[i].L >> s[i].R;
        s[i].tag = i;
    }
    std::sort(s + 1,s + n + 1,cmpL);
    int cntL = s[1].L,tag = s[1].tag;
    std::sort(s + 1,s + n + 1,cmpR);
    int cntR = s[1].R;
    if(s[1].tag == tag)
    {
        std::sort(s + 2,s + n + 1,cmpL);
        int L = s[2].L;
        std::sort(s + 2,s + n + 1,cmpR);
        int R = s[2].R;
        std::cout << (R - L >= 0 ? R - L : 0);
        return 0;
    }
    int ans1 = s[2].R - cntL >= 0 ? s[2].R - cntL : 0;
    std::sort(s + 1,s + n + 1,cmpL);
    int ans2 = cntR - s[2].L >= 0 ? cntR - s[2].L : 0;
    std::cout << std::max(ans1,ans2);
    return 0;
}