#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

int primefactor[maxn] , sol[maxn][13];

void sieve()
{
      for (ll i=2 ; i<maxn ; i++){
            if (primefactor[i]==0){
                  for (ll j=i ; j<maxn ; j+=i)primefactor[j]++;
            }
      }
      sol[1][0] = 1;
      for (int i=2 ; i<maxn ; i++){
            sol[i][primefactor[i]]++;
            for (int j=0 ; j<=11 ; j++)sol[i][j] += sol[i-1][j];
      }

      return;
}

int main()
{
      sieve();

      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll a,b,n;
            scanf("%lld %lld %lld",&a,&b,&n);

            printf("%d\n",sol[b][n]-sol[a-1][n]);
      }


      return 0;
}
