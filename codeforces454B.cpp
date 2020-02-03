#include <iostream>
#include <algorithm>

const int init_min = 1e6;
const int init_max = -1;

int max1 = init_max;
int min1 = init_min;
int max2 = init_max;
int min2 = init_min;
int flag = 0,x = 0,n;


int main()
{
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int tmp;
        std::cin >> tmp;
        if(!flag)
        {
            if(tmp >= max1)
            {
                min1 = std::min(min1,tmp);
                max1 = tmp;
            }
            else 
            {
                flag = 1;
                x = i - 1;
                min2 = tmp;
                max2 = tmp;
            }
        } 
        else 
        {
            if(tmp >= max2)
            {
                min2 = std::min(min2,tmp);
                max2 = tmp;
            }
            else
            {
                std::cout << -1;
                return 0;
            }
        }
    }
    //std::cout << min1 << " " << max1 << " " << min2 << " " << max2 << "\n";
    //std::cout << x << "\n";
    if((min2 > min1 || max2 > min1) && (min2 != init_min && max2 != init_max)) std::cout << -1;
    else 
    std::cout << (x == 0 ? 0 : n - x);
    return 0;
}