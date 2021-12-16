#include<bits/stdc++.h>
#define ll long long int
#define maxn 1000006

using namespace std;

ll n , P[30] , A[maxn];

ll maximumXOR()
{
      P[0] = 1;
      for (ll i=1 ; i<20 ; i++)P[i] = P[i-1]*2;

      ll cnt = 1;

      for (ll i=10 ; i>=0 ; i--){

            ll mx = -1 , id = cnt;
            for (ll j = cnt ; j<=n ; j++){

                  if (A[j]&P[i] && A[j]>mx){
                        id = j;
                        mx = A[j];
                  }
            }

            if (mx==-1)continue;

            swap(A[cnt],A[id]);
            id = cnt;

            for (ll j = 1 ; j<=n ; j++){
                  if (j!=id && A[j]&P[i]) A[j] = A[j]^A[id];
            }

            cnt++;
      }

      ll ret = 0;

      for (int i=1 ; i<=n ; i++)ret = ret^A[i];

      return ret;
}

int main()
{
      cin >> n;
      for (int i=1 ; i<=n ; i++)scanf("%lld",&A[i]);

      cout << maximumXOR() << endl;

      return 0;
}
