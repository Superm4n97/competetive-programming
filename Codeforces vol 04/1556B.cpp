#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 100000000000014

using namespace std;

vector<ll> v;
ll n;

ll solve(ll parity)
{
      ll positions = n/2;
      if (parity==0 && n%2==1)positions++;

      ll ret = inf;
      if (parity==0)ret = min(ret,solve(1));
      if (positions != v.size())return ret;
      ll cnt = 0;
      for (int i=0, id = parity ; i<v.size() ; i++,id+=2){
            cnt+=abs(v[i]-id);
      }
      return min(cnt,ret);
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            v.clear();
            cin >> n;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  if (a%2)v.push_back(i);
            }

            if (n==1)cout << 0 << endl;
            else {
                  ll ans = solve(0);
                  if (ans==inf)cout << -1 << endl;
                  else cout << ans << endl;
            }

      }


      return 0;
}

/*
1 2 3 3 2 3 4 4 5 3 2 1
l r x
*/
