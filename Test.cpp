#include<bits/stdc++.h>

using namespace std;

int A[] = {8,7,6,5,4,3,2,1} , n = 8;

int getPartition(int l, int r)
{
      int p = r , i = l, j = r-1;

      while(i<=j){
            while(A[i]<=A[p] && i<=j)i++;
            while(A[j]>=A[p] && j>=i)j--;
            if (i<=j)swap(A[i],A[j]);
      }
      if (A[i]>=A[p]){
            swap(A[i],A[p]);
            p = i;
      }
      return p;
}

void quickSort(int l,int r)
{
      if (l>=r)return;
      int pivot = getPartition(l,r);
      quickSort(l,pivot-1);
      quickSort(pivot+1,r);
}


int main()
{
      quickSort(0,n-1);
      for (int i=0 ; i<n ; i++)cout << A[i] << " ";
      cout << endl;
}
