#include<stdio.h>

int main(void)
{
	int T;//T is the number of test cases
	scanf("%d",&T);
	while(T--)
	{
		long long x,y,m;
		scanf("%lld %lld %lld\n",&x,&y,&m);

		long long  result = 1;

		x = x%m;
		while(y>0)
		{
			if(y&1)
				result = (result*x)%m;
				y = y/2;
				x = (x*x)%m;
				
		}
		printf("%lld\n", result);
		
	}
	return 0;
}
