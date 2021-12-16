#include<bits/stdc++.h>
#define ll long long int
#define maxn 200005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll mp[maxn] , n,k, mov[maxn] , ans = 1e18;
priority_queue < pair <ll,ll> > pq;

int main()
{
      cin >> n >> k;

      for (int i=0 ; i<n ; i++){
            ll a;
            cin >> a;

            mp[a]++;
            if (mp[a]>=k)ans = 0;

            if (a%2 && a!=1)a--;

            pq.push({a,0});
      }

      if (ans==0){
            cout << ans << endl;
            return 0;
      }

      while(true){

            ll a = pq.top().first , c = pq.top().second;
            pq.pop();

            if (a==0)break;

            a/=2;
            c--;

            mp[a]++;
            mov[a] += (-c);

            if (mp[a]>=k)ans = min(ans,mov[a]);

            if (a%2 && a!=1)a--;
            pq.push({a,c});
      }

      cout << ans << endl;



      return 0;
}
