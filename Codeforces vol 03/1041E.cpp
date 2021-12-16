#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1005

using namespace std;

ll n,cnt[maxn];
vector < pair < ll,ll > > ans;

int main()
{
      cin >> n;

      bool sol = true;

      for (int i=1 ; i<n ; i++){

            ll a, b;
            cin >> a >> b;

            if (b!=n)sol = false;
            cnt[a]++;
      }

      if (!sol){
            cout << "NO" << endl;
            return 0;
      }

      queue < ll > q;

      for (int i=1 ; i<n ; i++)
            if (cnt[i]==0)q.push(i);

      for (int i=1 ; i<n ; i++){
            if (cnt[i]){

                  if (q.size() < cnt[i]-1){

                        sol = false;
                        break;
                  }

                  ll pre = i;

                  for (int j = 1 ; j<cnt[i] ; j++){
                        if (q.front()>i){

                              sol = false;
                              break;
                        }

                        ans.push_back({pre , q.front()});
                        pre = q.front();
                        q.pop();
                  }
                  ans.push_back({pre,n});
            }
      }

      if (!sol)cout << "NO" << endl;
      else {
            cout << "YES" << endl;
            for (int i=0 ; i<ans.size() ; i++)cout << ans[i].first << " " << ans[i].second << endl;
      }


      return 0;
}
/**

**/
