#include <iostream>
#include <climits>
const int lens = 105;
int a[lens],b[lens],n,t;

int main()
{
    std::cin >> n >> t;
    for(int i = 1; i <= n; i++) std::cin >> a[i] >> b[i];
    int min = INT_MAX, id = -1;
    for (int i = 1; i <= n; i++)
    {
        while(a[i] < t)
        {
            a[i] += b[i];
        }
        if(min > a[i])
        {
            min = a[i];
            id = i;
        }
    }
    std::cout << id << '\n';
    return 0;
}