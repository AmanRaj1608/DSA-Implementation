//Gives solutions to Recursive Functions of form Fn = a*Fn-1 + b*Fn-2 with F(0)=c and F(1)=d. (Consider 0 base indexing)

#include <stdio.h>

long long m[2][2];
long long ans[2][2];
void mul();
void poww();
long long a,b,c,d;

void mul(void)
{
    long long b[2][2] = {0};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                b[i][j] += ((ans[i][k])*(m[k][j]));
            }
        }
    }
    ans[0][0] = b[0][0];
    ans[0][1] = b[0][1];
    ans[1][0] = b[1][0];
    ans[1][1] = b[1][1];
}

void poww(void)
{
    long long b[2][2] = {0};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                b[i][j] += ((m[i][k])* (m[k][j]));
            }
        }
    }
    m[0][0] = b[0][0];
    m[0][1] = b[0][1];
    m[1][0] = b[1][0];
    m[1][1] = b[1][1];
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long n;
        printf("Please enter n ,a ,b, c, d!");
        scanf("%lld %lld %lld %lld %lld", &n,&a,&b,&c,&d);
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = 1;
        m[1][1] = 0;
        ans[0][0] = a;
        ans[0][1] = b;
        ans[1][0] = 1;
        ans[1][1] = 0;
        if (n == 0)
            printf("%d\n",a);
        else if (n == 1)
            printf("%d\n",b);
        else
        {
            while (n > 0)
            {
                if (n & 1 == 1)
                    mul();
                n = n >> 1;
                poww();
            }

            printf("%lld\n", ans[1][1]);
        }
    }
    return 0;
}

