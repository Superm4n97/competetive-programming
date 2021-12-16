#include<bits/stdc++.h>
using namespace std;

int A[] = {1,2,4,4,5,6,8,8,8,8,9};

int UpperBound(int val)
{
      int b = 0 , e = 10, ret = -1;
      while(b<=e){
            int mid = (b+e)/2;

            if (A[mid]==val){
                  if (ret<mid)ret = mid;
                  b = mid+1;
            }o
            else if (A[mid]>val){
                  e = mid-1;
            }
            else{
                  b = mid+1;
            }
      }
      return ret;
}

int main()
{
      int num = 5;
      if (UpperBound(num)!=-1)printf("Upper Bound of %d is at %d\n",num,UpperBound(num));
      else printf("%d not found\n",num);
}
