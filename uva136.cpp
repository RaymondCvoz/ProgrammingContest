#include <bits/stdc++.h>

const int num[] = {2,3,5};

int main()
{
    std::priority_queue <long long,std::vector <long long>,std::greater <long long> >q;
    std::set <long long> s;
    q.push(1);
    s.insert(1);
    for(int i = 1;;i++)
    {
        long long x = q.top();q.pop();
        if(i == 1500)
        {
            std::cout << "The 1500'th ugly number is " << x << ".\n"; 
            break;
        }
        for(int j = 0;j < 3;j++)
        {
            long long tmp = x * num[j];
            if(!s.count(tmp))
            {
                s.insert(tmp);
                q.push(tmp);
            }
        }
    }
    return 0;
}
