#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

vector<ll> G[5000006];
ll n , A[5000006];

int main()
{
      scanf("%I64d",&n);
      for (int i=1 ; i<=n ; i++)scanf("%I64d",&A[i]);

      for (ll i=1 ; i<n ; i++){
            for (ll j=i+1 ; j<=n ; j++){
                  ll sum = A[i]+A[j];
                  if (G[sum].empty()){
                        G[sum].push_back(i);
                        G[sum].push_back(j);
                  }
                  else {
                        if (G[sum][0]==i || G[sum][1]==i || G[sum][0]==j || G[sum][1]==j)continue;
                        printf("YES\n%I64d %I64d %I64d %I64d\n",G[sum][0],G[sum][1],i,j);
                        return 0;
                  }
            }
      }

      printf("NO\n");


      return 0;
}
