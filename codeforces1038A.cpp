#include <bits/stdc++.h>
#define LL long long

int num[27];
int main()
{   
    int n,k;
    std::string s;
    std::cin >> n >> k >> s;
    for(int i = 0;i < s.length();i++)
    {
        num[s[i] - 'A'] ++;
    }
    int ans = 1e9;
    for(int i = 0;i < k;i++)
    {
        //if(num[i] == 0) continue;
        ans = std::min(ans,num[i]);
    }
    std::cout << ans * k;
    return 0;
}