#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(w) scanf("%I64d",&w)

using namespace std;

int main()
{
      ll n,m;
      scl(n);
      scl(m);

      ll A[n+5] , B[m+5] , g , X , mn;

      for (int i=0 ; i<n ; i++)scl(A[i]);

//      for (int i=0 ; i<n;  i++)cout << A[i] << " ";
//      cout << endl;

      for (int i=0 ; i<n ; i++){

            if (i==0){
                  X = A[i];
                  mn = A[i];
            }
            else {
                  X = __gcd(X,A[i]);
                  mn = min(mn,A[i]);
            }

            if (i>=1){
                  ll temp = abs(A[i]-A[i-1]);
                  if (i==1)g = temp;
                  g = __gcd(g,temp);
            }
      }

      for (int i=0 ; i<m ; i++){
            scl(B[i]);

            if (n==1)B[i] += A[0];
            else B[i]=__gcd(g,B[i]+mn);
      }
      for (int i=0 ; i<m ; i++)cout << B[i] << " ";
      cout << endl;

      return 0;
}
