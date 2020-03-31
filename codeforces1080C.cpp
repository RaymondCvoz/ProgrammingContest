#include <iostream>
#include <algorithm>

typedef long long LL;
class Rec
{
    public:
    LL x1, y1, x2, y2;
    LL black()
    {
        if (x1 > x2 || y1 > y2)
            return 0;
        LL buf = (x2 - x1 + 1) * (y2 - y1 + 1);
        return buf / 2 + ((x1 + y1) & 1 && (buf & 1));
    }
    LL white()
    {
        if (x1 > x2 || y1 > y2)
            return 0;
        return (x2 - x1 + 1) * (y2 - y1 + 1) - black();
    }
    Rec inter(const Rec &tmp) const
    {
        Rec ret;
        ret.x1 = std::max(x1, tmp.x1), ret.x2 = std::min(x2, tmp.x2);
        ret.y1 = std::max(y1, tmp.y1), ret.y2 = std::min(y2, tmp.y2);
        return ret;
    }
} rec[4];

int main()
{
    int t, n, m, x1, y1, x2, y2;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> m;
        rec[0] = {1, 1, n, m};
        for (int i = 1; i <= 2; i++)
        {
            std::cin >> x1 >> y1 >> x2 >> y2;
            rec[i] = {x1, y1, x2, y2};
        }
        LL white = rec[0].white(), black = rec[0].black();
        rec[3] = rec[1].inter(rec[2]);
        white += rec[1].black() - rec[3].black();
        black -= rec[1].black() - rec[3].black();
        black += rec[2].white();
        white -= rec[2].white();
        std::cout << white << " " << black << "\n";
    }
    return 0;
}