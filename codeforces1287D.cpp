#include <bits/stdc++.h>

const int lens = 1e4;
int vis[lens],ans[lens],n,root,flag = 1;

class node
{
    public:
    int to,c;
    public:node(int to,int c)
    {
        this -> to = to;
        this -> c = c;
    }
};

std::vector <node> v[lens];
std::vector <int> find(int cnt,int anc)
{
    std::vector <int> node;
    for(int i = 0;i < v[cnt].size();i++)
    {
        if(v[cnt][i].to != anc)
        {
            std::vector <int> tmp = find(v[cnt][i].to,cnt);
            for(int i = 0;i < tmp.size();i++) node.push_back(tmp[i]);
        }
    }
    if(vis[cnt] <= node.size()) node.insert(node.begin() + vis[cnt],cnt);
    else flag = 0;
    return node;
}

int main()
{
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int c,p;
        std::cin >> p >> c;
        vis[i] = c;
        if(!p) root = i;
        else
        {
            v[i].push_back(node{p,c});
            v[p].push_back(node{i,c});
        }
    }
    std::vector <int> res = find(root,-1);
    if(!flag)
    {
        std::cout << "NO"; return 0;
    }
    int num = 0;
    for(int i = 0;i < res.size();i++) 
    {
        num ++;
        ans[res[i]] = num;
    }
    std::cout << "YES" << "\n";
    for(int i = 1;i <= n;i++) std::cout << ans[i] << " ";
    return 0;
}