#include <bits/stdc++.h>
#define LL long long

std::priority_queue <LL> a,b;
LL ans_a,ans_b;

int main()
{
    LL n;
    std::cin >> n;
    for(LL i = 1;i <= n;i++)
    {
        LL tmp;
        std::cin >> tmp;
        a.push(tmp);
    }
    for(LL i = 1;i <= n;i++)
    {
        LL tmp;
        std::cin >> tmp;
        b.push(tmp);
    }
    LL cnt = 1;
    while(1)
    {

        if(cnt % 2 == 1)
        {
            if(!a.empty())
            {
                if(b.empty())
                {
                    ans_a += a.top(); a.pop();
                }
                else
                {
                    if(a.top() > b.top())
                    {
                        ans_a += a.top(); a.pop();
                    }
                    else
                    {
                        b.pop();
                    }
                }
            }
            else if(!b.empty())
            {
                b.pop();
            }
        }
        else
        {
            if(!b.empty())
            {
                if(a.empty())
                {
                    ans_b += b.top(); b.pop();
                }
                else
                {
                    if(b.top() > a.top())
                    {
                        ans_b += b.top(); b.pop();
                    }
                    else
                    {
                        a.pop();
                    }
                }
            }
            else if(!a.empty())
            {
                a.pop();
            }
        }
        cnt++;
        if(a.empty() && b.empty()) break;
    }
    std::cout << ans_a - ans_b;
    return 0;
}