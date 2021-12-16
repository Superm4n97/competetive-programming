#include<bits/stdc++.h>
using namespace std;

int A[] = {1,2,4,4,5,6,8,8,8,8,9};

int BinarySearch(int val)
{
      int b = 0 , e = 10;
      while(b<=e){
            int mid = (b+e)/2;

            if (A[mid]==val){
                  return mid;
            }
            else if (A[mid]>val){
                  e = mid-1;
            }
            else {
                  b = mid+1;
            }
      }
      return -1;
}

int main()
{
      int num = 8;
      if (BinarySearch(num) != -1)printf("%d found at %d\n",num,BinarySearch(num));
      else printf("%d not found\n",num);
}
