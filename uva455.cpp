    #include <iostream>
    #include <algorithm>
    #include <string>

    #include <cstdio>

    std::string s;

    inline bool judge(int p)
    {
        if(s.length() % p != 0) return false;
        for(int i = 0;i < s.length() - p;i += p)
        {
            std::string tmp = s.substr(i,p);
            std::string tmp1 = s.substr(i + p,p);
            if(tmp != tmp1) return false;
        }
        return true;
    }


    int main()
    {
     //freopen("test.txt","r",stdin);
        int n;
        std::cin >> n;
        while(n--)
        {
            std::cin >> s;
            bool flag = 1;
            for(int p = 1;p <= s.length();p++)
            {
                if(judge(p))
                {
                    std::cout << p;
                    if(n != 0) std::cout << "\n\n";
                    else std::cout << "\n";
                    flag = 0;
                    break;
                }
                /*else if(judge(p) && n == 0)
                {
                    std::cout << p;
                    flag = 0;
                    break;
                }*/
            }
        }
        return 0;
    }