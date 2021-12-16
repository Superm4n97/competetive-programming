#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      cin >> n;

      map < ll , ll > mp;
      priority_queue <ll> mx;
      ll mn = 1000000000012;

      for (int i=0 ; i<n; i++){

            ll a;
            cin >> a;

            if(mp[a]==0){

                  mx.push(a);
                  mn = min(mn,a);

                  mp[a]++;
            }
      }

      ll ans = 0;

      while(mx.top() != mn){
            ll X = mx.top();
            mx.pop();

            ll a = X - mn;
            if (mp[a]==0){
                  mx.push(a);
                  mp[a]++;
            }

            mn = min(a,mn);

            ans++;
      }

      cout << ans << endl;

      return 0;
}
