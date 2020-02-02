#include <iostream>
#include <algorithm>
#include <queue>

int main()
{
    std::queue <int> q,game;
    int n,k;
    std::cin >> n >> k;
    int cnt;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> cnt;
        q.push(cnt);
    }
    while(1)
    {
        int tmp = q.front(); 
        q.pop();
        game.push(tmp); 
        q.push(tmp);
        tmp = game.size();
        for(int i = 1;i <= tmp;i++)
        {
            k--;
            if(k == 0)
            {
                std::cout << game.front();
                return 0;
            }
            cnt = game.front();
            game.pop();
            game.push(cnt);
        }
    }
    return 0;
}