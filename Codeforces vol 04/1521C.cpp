#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            int n;
            scanf("%d",&n);

            int A[n+5][2];
            memset(A,0,sizeof A);

            for (int i=2 ; i<=n ; i+=2){
                  printf("? 1 %d %d %d\n",i-1,i,n-1);
                  fflush(stdout);
                  scanf("%d",&A[i][1]);

                  printf("? 2 %d %d 1\n",i-1,i);
                  fflush(stdout);
                  scanf("%d",&A[i][0]);

                  cout << A[i][0] << " "<< A[i][1] << endl;
            }
            for (int i=2 ; i<=n ; i+=2){
                  if (A[i][0]==A[i][1]){
                        if (A[i][0]==2)A[i][0] = 1;
                        if (A[i][1]==n-1)A[i][1] = n;
                  }
            }
            for (int i=2 ; i<n ; i+=2){
                  printf("? 1 %d %d %d\n",i,i+1,n-1);
                  fflush(stdout);

                  int a;
                  scanf("%d",&a);

                  if (a==A[i])

            }
      }
}
/*
1 2  3 4  5 6  7 8  9

*/
