#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n , d;
            scl(n);
            scl(d);

            vector <ll> v;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  scl(a);

                  v.push_back(a);
            }

            sort(v.begin(),v.end());

            if (v[0]+v[1]<=d || v[n-1]<=d)printf("YES\n");
            else printf("NO\n");
      }

      return 0;
}
