#include <bits/stdc++.h>
#define LL long long
const int lens = 1e4;

LL cat[lens];

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while(t--)
    {
        LL n,s,k;
        std::set <LL> st;
        st.clear();
        std::cin >> n >> s >> k;
        for(int i = 1;i <= k;i++)
        {
            std::cin >> cat[i];
            st.insert(cat[i]);
        }
        std::sort(cat + 1,cat + k + 1);
        LL ans = LLONG_MAX - 1;
        for(LL i = s;i <= n;i++)
        {
            if(st.find(i) == st.end())
            {
                ans = std::min(ans,i - s); break;
            }
            /*LL cnt = std::lower_bound(cat + 1,cat + k + 1,i) - cat;
            if(i != cat[cnt]) 
            {
                ans = std::min(ans,i - s); break;
            }*/
        }
        //std::cout << ans << "\n";
        for(LL i = s;i >= 1;i--)
        {
            if(st.find(i) == st.end())
            {
                ans = std::min(ans,s - i); break;
            }
            /*LL cnt = std::lower_bound(cat + 1,cat + k + 1,i) - cat;
            if(i != cat[cnt])
            {
                ans = std::min(ans,s - i); break;
            }*/
        }
        std::cout << ans << "\n";
    }
    return 0;
}
