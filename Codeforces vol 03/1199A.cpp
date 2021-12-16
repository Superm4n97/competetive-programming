#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,x,y;
      cin >> n >> x >> y;

      ll A[n+5];

      for (int i=1;  i<=n ; i++){
            cin  >> A[i];
      }

      ll ans = 0;

      for (int i = 1 ; i<=n ; i++){

            bool sol = true;

            for (int j = 1 ; j<=x ; j++){
                  if (i-j<1)break;
                  if (A[i-j]<A[i])sol = false;
            }
            for (int j = 1 ; j<=y ; j++){
                  if (i+j>n)break;
                  if (A[i+j]<A[i])sol = false;
            }

            if(sol){
                  cout << i << endl;
                  return 0;
            }
      }

      return 0;
}
