//Finding x^y%m efficiently using Divide and Conquer Approach

#include<stdio.h>

int main(void)
{
	int T;  //T is the number of test cases
	scanf("%d",&T);
	while(T--)
	{
		long long x,y,m;
    printf("Enter x,y,m !\n");
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
