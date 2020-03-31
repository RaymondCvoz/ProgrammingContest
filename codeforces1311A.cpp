#include <cstdio>

bool isodd(int x)
{
    return x & 1;
}

int main()
{
    int a,b,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(a == b) printf("0\n");
        else if((a > b && !isodd(a - b)) || (a < b && isodd(b - a))) printf("1\n");
        else printf("2\n");
    }
    return 0;
}