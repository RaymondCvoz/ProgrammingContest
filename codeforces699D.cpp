#include<bits/stdc++.h>
#define LL long long

const int lens = 200005;
int ances[lens],node[lens];

int find(int x)
{
    if(ances[x] != x) ances[x] = find(ances[x]);
    return ances[x];
}

int main()
{
    int n,root = -1,ans = 0;
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> node[i];
        ances[i] = i;
        if(node[i] == i && root == -1) root = i;
    }

    for(int i = 1;i <= n;i++)
    {
        if(i == root) continue;
        int a = find(i);
        int b = find(node[i]);
        if(a != b)
        {
            ances[a] = b;
        }
        else
        {
            if(root == -1)
            {
                root = i;
            }
            node[i] = root;
            ans ++;
        }
    }
    std::cout << ans << "\n";
    for(int i = 1;i <= n;i++) std::cout << node[i] << " ";
    return 0;
}