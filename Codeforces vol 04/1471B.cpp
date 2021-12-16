#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n , x;
            scl(n) , scl(x);

            ll A[n+5] , t[n+5] , mn = 1000000000012 , id = 1;
            memset(t,0,sizeof t);

            ll ans = 0;
            for (int i = 1 ; i<=n ; i++){
                  scl(A[i]);
                  ll temp = A[i];
                  ans+=A[i];
                  while(temp%x==0){
                        t[i]++;
                        temp/=x;
                  }
                  if (t[i]<mn){
                        mn = t[i];
                        id = i;
                  }
            }


            for (int i=1 ; i<=n ; i++){
                  if (i<id){
                        t[i]=mn+1;
                  }
                  else t[i] = mn;
                  ans+=(A[i]*t[i]);
            }

            cout << ans << endl;
      }

      return 0;
}
