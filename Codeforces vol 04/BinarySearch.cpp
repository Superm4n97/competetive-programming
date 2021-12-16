#include<bits/stdc++.h>

using namespace std;

int A[] = {0,0,0,1,2,2,4,5,6,6,8,8,8,8,8,9,9};
int n = 17;

int BinarySearch(int val)
{
      int b = 0 , e = 16;
      while(b<=e){

            int mid = (b+e)/2;

            if(A[mid]>val){
                  e = mid-1;
            }
            else if (A[mid]<val){
                  b = mid+1;
            }
            else return mid;
      }
      return -1;
}

int main()
{
      int id = BinarySearch(7);

      if (id==-1)cout << "Not found" << endl;
      else cout << "Found in index : " << id << endl;



      return 0;
}
