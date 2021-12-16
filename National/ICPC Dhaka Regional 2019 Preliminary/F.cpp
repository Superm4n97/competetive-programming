#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define ll long long int
#define maxn 100005

using namespace std;

ll H[maxn] , n;

ll position(ll id, ll tme)
{
      ll h = H[id] , mod = H[id]*2;
      tme %= mod;
      if (tme<=h)return tme;
      return mod - tme;
}

ll direction(ll id, ll tme)
{
      ll h = H[id] , mod = H[id]*2;
      tme %= mod;
      if (tme==0)return 1;
      if (tme==h)return 0;
      if (tme<h)return 1;
      return 0;
}

int main()
{
      int tc;
      cin >> tc;

      for (int _t = 1 ; _t<=tc; _t++){
            cin >> n;
            for (int i=1 ; i<=n ; i++)cin >> H[i];

            ll ans = 0 , id = 1;
            while(id<n){
                  ll p1 = position(id,ans),p2 = position(id+1,ans);
                  ll d1 = direction(id,ans),d2 = direction(id+1,ans);

                  if (p1>=p2){
                        ans++;
                        id++;
                  }
                  else {
                        if (d2==1){
                              ans += H[id+1] - p2;
                              if (H[id+1]>H[id]){
                                    ans+=(H[id+1]-H[id]);
                              }
                        }
                        else {
                              if (d1==0){
                                    ans += p1;
                              }
                              else {
                                    ll temp = (p2-p1+1)/2;
                                    ans+=temp;
                              }
                        }
                  }
            }
            cout << "Case "<<_t<<": " << ans << "\n";
      }
}
