#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll A[maxn] , B[maxn] , H[maxn], D[maxn] , c , n;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            scanf("%lld %lld",&n,&c);
            for (int i=1 ; i<=n ; i++)scanf("%lld",&A[i]);
            for (int i=1 ; i<n ; i++)scanf("%lld",&B[i]);

            H[1] = D[1] = 0;

            for (int i=2 ; i<=n ; i++){
                  ll need = B[i-1]-H[i-1];
                  if (need<=0){
                        D[i] = D[i-1]+1;
                        H[i] = H[i-1]-B[i-1];
                  }
                  else {
                        ll d = ((need+A[i-1]-1)/A[i-1]);
                        D[i] = D[i-1]+d+1;
                        H[i] = H[i-1]+A[i-1]*d - B[i-1];
                  }
            }

            ll ans = c*100;

            for (int i=1 ; i<=n ; i++){
//                  cout << "i:"<<i<<" --D[i]:" << D[i] << " -- H[i]:" << H[i] << endl;
                  ll need = c-H[i];
                  ll d = (need+A[i]-1)/A[i];
                  ans = min(ans,d+D[i]);
//                  show(d+D[i]);
            }
            printf("%lld\n",ans);
      }

      return 0;
}
/*
1
4 15
1 3 10 11
1 2 7

1
4 15
1 3 10 11
5 6 7

1
4 15
10 11 12 13
1 2 3
*/
