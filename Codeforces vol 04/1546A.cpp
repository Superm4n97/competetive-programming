#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n;
            scl(n);

            ll A[n+5] , B[n+5];
            vector<ll> in,de;

            for (int i=1 ; i<=n ; i++)scl(A[i]);
            for (int i=1 ; i<=n ; i++)scl(B[i]);

            for (int i=1 ; i<=n ; i++){
                  ll df = A[i]-B[i];
                  if (df>0){
                        for (int j=0 ; j<df ; j++)de.push_back(i);
                  }
                  if (df<0){
                        for (int j=0 ; j<-df ; j++)in.push_back(i);
                  }
            }
            if (in.size() != de.size())printf("-1\n");
            else {
                  cout << in.size() << endl;
                  for (int i=0 ; i<in.size() ; i++)printf("%lld %lld\n",de[i],in[i]);
            }
      }

      return 0;
}
