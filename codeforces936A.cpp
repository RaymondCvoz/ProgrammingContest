#include <bits/stdc++.h>
#define LL long long

LL k,d,t;

int main()
{
    std::cin >> k >> d >> t;
    LL span = ((k - 1) / d + 1) * d;
    double v = k + (span - k) * 0.5;
    LL tot = t / v;
    double ans = span * tot;
    double remain = t - tot * v;
    if(remain < k) ans += remain;
    else ans += k + (remain - k) * 2;
    printf("%.10lf",ans);
}