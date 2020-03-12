#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue <int, vector <int>, greater <int> > q;
int n;
int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
    long long res = 0;
    while(q.size() != 1)
    {
        int a = q.top();q.pop();
        int b = q.top();q.pop();
        res += (a + b);
        q.push(a + b);
    }
    std::cout << res;
    return 0;
}