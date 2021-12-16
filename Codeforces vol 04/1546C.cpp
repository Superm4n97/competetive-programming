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

            vector<ll>A;
            vector<ll>ev,od,s_ev,s_od;
            for (int i=0 ; i<n ; i++){
                  ll a;
                  scl(a);
                  A.push_back(a);
                  if (i&1)od.push_back(a);
                  else ev.push_back(a);
            }
            sort(A.begin() , A.end());
            sort(ev.begin() , ev.end());
            sort(od.begin() , od.end());

            for (int i=0 ; i<n ; i++){
                  if (i&1)s_od.push_back(A[i]);
                  else s_ev.push_back(A[i]);
            }

            if (od==s_od && ev==s_ev)printf("YES\n");
            else printf("NO\n");
      }


      return 0;
}
