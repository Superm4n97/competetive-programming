#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 15000007

using namespace std;

vector < ll > Prime;
ll mnDiv[maxn] , cnt[maxn] , A[300005];

void LinearSieve()
{
      memset(mnDiv,-1,sizeof mnDiv);

      for (ll i=2 ; i<maxn ; i++){
            if (mnDiv[i]==-1){
                  mnDiv[i] = i;
                  Prime.push_back(i);
            }

            for (ll j = 0 ; j<Prime.size() && Prime[j]*i<maxn ; j++){

                  mnDiv[Prime[j]*i] = Prime[j];

                  if (i%Prime[j]==0)break;
            }
      }
}

int main()
{
      LinearSieve();

      ll  n,GCD;
      cin >> n;

      for (int i=0 ; i<n ; i++){
            cin >> A[i];
            if (i==0)GCD = A[i];
            else GCD = __gcd(A[i],GCD);
      }

      for (int i=0 ; i<n ; i++){

            ll  a = A[i] / GCD;

            while(a>1){

                  ll temp = mnDiv[a];
                  cnt[temp]++;

                  while(a%temp==0)a/=temp;
            }
      }

      ll mx = -1;

      for (int i=2 ; i<maxn ; i++){
            mx = max(cnt[i],mx);
      }

      if (mx==0)cout << -1 <<endl;
      else cout << n-mx << endl;


      return 0;
}

/**
2233 36
33    9
3     3
22    4
**/
