#include<stdio.h>

int main()
{
      int a,n,x=1;

      scanf("%d",&n);

      for(a=1;a<=n;a=a+1)
      {
            x=x*a;
      }
      printf("%d ",x);

      return 0;
}
