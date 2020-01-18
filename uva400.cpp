#include <iostream>
#include <algorithm>
#include <string>

const int maxcol = 60;
const int lens = 100 + 5;
std::string filename[lens];

void print(const std::string &s,int len,char extra)
{
    std::cout << s;
    for(int i = 0;i < len - s.length();i++)
    {
        std::cout << extra;
    }
}

int main()
{
    int n;
    while(std::cin >> n)
    {
        int m = 0;
        for(int i = 0;i < n;i++)
        {
            std::cin >> filename[i];
            m = std::max(m,(int)filename[i].length());
        }
        int cols = (maxcol - m) / (m + 2) + 1, rows = (n - 1) / cols + 1;
        print("",60,'-');
        std::cout << "\n";
        std::sort(filename,filename + n);
        for(int r = 0;r < rows;r++)
        {
            for(int c = 0;c < cols;c++)
            {
                int idx = c * rows + r;
                if(idx < n) print(filename[idx],c == cols - 1 ? m : m + 2,' ');
            }
            std::cout << "\n";
        }
    }
    return 0;
}