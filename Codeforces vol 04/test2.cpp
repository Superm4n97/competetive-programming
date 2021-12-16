#include<stdio.h>

int recursion(int n)
{
      if (n==0)return 0;
      return n+recursion(n-1);
}

int main()
{
      int n;
      scanf("%d",&n);
      printf("%d\n",recursion(n));
}
