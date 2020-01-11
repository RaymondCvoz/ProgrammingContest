#include <cstdio>
#include <cstring>
#include <cctype>

const char *rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *msg[] = {"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};

char r(char ch)
{
    if(isalpha(ch)) return rev[ch - 'A'];
    return rev[ch - '0' + 25];
}

int main()
{
    char s[40];
    while (scanf("%s",s) == 1)
    {
        int lens = strlen(s);
        int p = 1,m = 1;
        for(int i = 0;i < (lens + 1) / 2;i++)
        {
            if(s[i] != s[lens - 1 - i]) p = 0;
            if(r(s[i]) != s[lens - 1 - i]) m = 0;
        }
        printf("%s -- is %s.\n\n",s,msg[m * 2 + p]);
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
const int lens = 1010;
int n,a[lens],b[lens];

int main()
{
    std::cin >> n; int cal = 0;
    while(n)
    {
        cal++;
        for(int i = 1;i <= n;i++)
        {
            std::cin >> a[i];
        }
        std::cout << "Game " << cal << ":\n";
        int judge = 0;
        while(1)
        {
            for(int i = 1;i <= n;i++)
            {
                std::cin >> b[i]; 
                if(b[i]) judge = 1;
            }
            int same = 0,num1[10],num2[10];
            if(judge)
            {
                memset(num1,0,sizeof(num1)); memset(num2,0,sizeof(num2));
                for(int i = 1;i <= n;i++)
                {
                    if(a[i] == b[i]) same ++;
                    num1[a[i]] ++; num2[b[i]] ++;
                }
            }
            else break;
            int res = 0;
            for(int i = 0;i <= 9;i++) res += std::min(num1[i],num2[i]); res -= same;
            std::cout << "    (" << same << "," << std::max(res,0) << ")\n";
            judge = 0;
        }
        std::cin >> n;
    }
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

const int lens = 1e5 + 1;

class Data
{
    public:
    int x,y,id,ans;
}a[lens];

bool cmp1(const Data &a, const Data &b) {return a.x < b.x;}
bool cmp2(const Data &a, const Data &b) {return a.y < b.y;}
bool cmp3(const Data &a, const Data &b) {return a.id < b.id;}

int vis[lens];
std::vector <int> G[lens];
int n,ans;

void dfs(int x)
{
    if(!vis[x]) ans ++;
    vis[x] = 1;
    for(int i = 0;i < G[x].size();i++)
    {
        if(vis[G[x][i]]) continue;
        dfs(G[x][i]);
    }
}

int main()
{
    freopen("codecoder.in","r",stdin);
    freopen("codecoder.out","w",stdout);
    std::cin >> n;
    for(int i = 1;i <= n;i++)
    {
        std::cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    std::sort(a + 1,a + n + 1,cmp1);
    for(int i = 2;i <= n;i++) G[a[i].id].push_back(a[i - 1].id);
    std::sort(a + 1,a + n + 1,cmp2);
    for(int i = 2;i <= n;i++) G[a[i].id].push_back(a[i - 1].id);

    for(int i = 1;i <= n;i++)
    {
        dfs(a[i].id);
        a[i].ans = ans - 1;
    }
    std::sort(a + 1,a + n + 1,cmp3);
    for(int i = 1;i <= n;i++) std::cout << a[i].ans << "\n";
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

int upper,lower,digit,n;
std::string s;
int main()
{
    std::cin >> n;
    while (n--)
    {
        upper = lower = digit = 0;
        std::cin >> s;
        for(int i = 0;i < s.length();i++)
        {
            if(isupper(s[i])) upper ++;
            else if(islower(s[i])) lower ++;
            else if(isdigit(s[i])) digit ++;
        }
        //std::cout << upper << " " << lower << " " << digit << "\n";
        for(int i = 0;i < s.length();i++)
        {
            if(!upper || !lower || !digit)
            {
                if(isupper(s[i]) && upper > 1)
                {
                    if(!lower)
                    {
                        s[i] = 'a'; upper --; lower ++;
                    }
                    else if(!digit)
                    {
                        s[i] = '1'; upper --; digit ++;
                    }
                }
                else if(islower(s[i]) && lower > 1)
                {
                    if(!upper)
                    {
                        s[i] = 'A'; lower --; upper ++;
                    }
                    else if(!digit)
                    {
                        s[i] = '1'; lower --; digit ++;
                    }
                }
                else if(isdigit(s[i]) && digit > 1)
                {
                    if(!upper)
                    {
                        s[i] = 'A'; digit --; upper ++;
                    }
                    else if(!lower)
                    {
                        s[i] = 'a'; digit --; lower ++;
                    }
                }
            }
        }
        std::cout << s << "\n";
    }
    return 0;
}

#include <iostream>
#include <algorithm>

const int maxn = 1e5 + 6;
int ans[maxn << 1],n;

int main()
{
    for(int i = 1;i <= maxn - 1;i++)
    {
        int x = i,y = i;
        while(x)
        {
            y += x % 10; x /= 10;
        }
        if(ans[y] > i || ans[y] == 0) ans[y] = i;
    }
    std::cin >> n;
    while(n--)
    {
        int x;
        std::cin >> x;
        std::cout << ans[x] << "\n";
    }
    return 0;
}

#include <iostream>
#include <string>

std::string s;

bool less(std::string s,int p,int q)
{
    int n = s.length();
    for(int i = 0;i < s.length();i++)
    {
        if(s[(p + i) % n] != s[(q + i) % n])
            return s[(p + i) % n] < s[(q + i % n)];
    }
    return false;
}

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        std::cin >> s;
        int ans = 0;
        for(int i = 0;i < s.length();i++)
        {
            if(less(s,i,ans)) ans = i;
        }
        for(int i = 0;i < s.length();i++)
        {
            std::cout << s[(ans + i) % s.length()];
        }
        std::cout << "\n";
    }
}

#include <iostream>
#include <algorithm>
#include <string>

std::string s;
int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {    /* code */
        std::cin >> s;
        int cnt = 1,ans = 0;
        for(int i = 0;i < s.length();i++)
        {
            if(s[i] == 'O')
            {
                ans += cnt; cnt ++;
            }
            else cnt = 1;
        }
        std::cout << ans << "\n";
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <iomanip>
#include <cstdio>

std::string s;
int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {    /* code */
        std::cin >> s;
        double ans = 0;
        for(int i = 0;i < s.length();i++)
        {
            if(isalpha(s[i]))
            {
                int j = i;
                double res = 0;
                if(j == s.length() - 1 || isalpha(s[j + 1])) res = 1;
                else
                {
                    while(isdigit(s[j + 1]))
                    {
                        res *= 10; res += s[j + 1] - '0'; j += 1;
                    }
                }
                if(s[i] == 'C') ans += res * 12.010;
                if(s[i] == 'O') ans += res * 16.000;
                if(s[i] == 'N') ans += res * 14.010;
                if(s[i] == 'H') ans += res * 1.008;
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
int n;
int ans[10];

int main()
{
    std::cin >> n;
    while(n--)
    {
        std::string s = "";
        memset(ans,0,sizeof(ans));
        int cnt; std::cin >> cnt;
        for(int i = 1;i <= cnt;i++)
        {
            std::stringstream ss; std::string tmp = "";
            ss << i;
            ss >> tmp;
            s += tmp;
        }
        for(int i = 0;i < s.length();i++)
        {
            ans[s[i] - '0'] += 1;
        }
        for(int i = 0;i <= 8;i++) std::cout << ans[i] << " "; std::cout << ans[9];
        std::cout << "\n";
    }
    return 0;
}

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

    #include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
const int lens = 100;

int left,chance;
char s[lens],s2[lens];
int win,lose;

void guess(char ch)
{
    int bad = 1;
    for(int i = 0;i < strlen(s);i++)
    {
        if(s[i] == ch)
        {
            left --;
            s[i] = ' ';
            bad = 0;
        }
    }
    if(bad) chance --;
    if(!chance) lose = 1;
    if(!left) win = 1;
}

int main()
{
    int rnd;
    while(scanf("%d%s%s",&rnd,s,s2) == 3 && rnd != -1)
    {
        printf("Round %d\n",rnd);
        win = lose = 0;
        left = strlen(s);
        chance = 7;
        for(int i = 0;i < strlen(s2);i++)
        {
            guess(s2[i]);
            if(win || lose) break;
        }
        if(win) printf("You win.\n");
        else if(lose) printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

const int lens = 25;
int vis[lens],m,n,k;


int main()
{
    while(scanf("%d%d%d",&n,&k,&m) == 3 && n && m && k)
    {
        memset(vis,-1,sizeof(vis));
        int left = n,cnt_a = -1,cnt_b = n;
        while (left > 0)
        {
            int t = k;
            while(t)
            {
                if(vis[(cnt_a + 1) % n] == -1) t--;
                cnt_a = (cnt_a + 1) % n;
            }
            t = m;
            while(t)
            {
                if(vis[(cnt_b - 1 + n) % n] == -1) t--;
                cnt_b = (cnt_b - 1 + n) % n;
            }
            vis[cnt_a] = 0;
            vis[cnt_b] = 0;
            if(cnt_b == cnt_a)
            {
                left -= 1;
                printf("%3d",cnt_a + 1);
            }
            else
            {
                left -= 2;
                printf("%3d%3d",cnt_a + 1,cnt_b + 1);
            }
            if(left != 0) printf(",");
        }
        puts("");
    }
    return 0;
}