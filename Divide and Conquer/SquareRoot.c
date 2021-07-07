#inlcude<math.h>
#include<stdio.h>
#define PR 0.0000001
int main(void)
{
  float n,ans,l,r,mid;
  printf("Please enter a positive number!");
  scanf("%f",&n);
  if(n>1)
  {
     l =1,r=n;
     mid = (l+r)/2;   
     while(fabs(mid*mid-n)>PR)
     {
          ((mid*mid-n)>0)?r=mid:l=mid;
     }
      ans=mid;
  }
  else
  {
    
     l =1,r=n;
     mid = (l+r)/2;   
     while(fabs(mid*mid-n)>PR)
     {
          ((mid*mid-n)>0)?l=mid:r=mid;
     }
      ans=mid;
  }
  printf("The square root of %f is %f\n",n,ans);
  return 0;
}
