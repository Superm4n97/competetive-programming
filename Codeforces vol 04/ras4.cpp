#include<stdio.h>

int main()
{
      int a,b=0,c=1,x;
      printf("%d ",b);
      printf("%d ",c);
      for(a=0;a<=10;a=a+1 )
      {
            x=b+c;
            b=c;
            c=x;
            printf("%d ",x);
      }

      return 0;
}
