#include <stdio.h>

long long m[2][2];
long long ans[2][2];
void mul();
void poww();

void mul(void)
{
    long long a[2][2] = {{1, 1}, {1, 0}};
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
        scanf("%lld", &n);
        m[0][0] = 1;
        m[0][1] = 1;
        m[1][0] = 1;
        m[1][1] = 0;
        ans[0][0] = 1;
        ans[0][1] = 1;
        ans[1][0] = 1;
        ans[1][1] = 0;
        if (n == 0)
            printf("0\n");
        else if (n == 1)
            printf("1\n");
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
