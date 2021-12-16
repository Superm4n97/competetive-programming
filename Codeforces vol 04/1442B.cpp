#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ll n , k;
            cin >> n >> k;

            ll A[n+5] , F[n+5] , mp[n+5] , B[n+5];
            memset(F,0,sizeof F);
            memset(A,0,sizeof A);
            memset(mp,0,sizeof mp);
            F[0] = F[n+1] = 1;

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];
                  mp[A[i]] = i;
            }

            for (int i=1 ; i<=k ; i++){
                  ll a;
                  cin >> B[i];

                  F[B[i]] = 1;
            }

            ll ans = 1;

            for(int i=1 ; i<=k ; i++){

                  ll id = mp[B[i]];
                  ll x = A[id-1] , y = A[id+1];

                  ll cnt = 0;
                  if (F[x]==0)cnt++;
                  if (F[y]==0)cnt++;
                  F[B[i]] = 0;

                  ans*=cnt;
                  ans%=998244353;
            }

            cout << ans << endl;
      }


      return 0;
}
