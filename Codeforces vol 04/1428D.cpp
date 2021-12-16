#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

ll n,row , A[maxn] , up[maxn];
queue<ll> three , two;
vector <pair<ll,ll> > ans;
bool sol = true;

int main()
{
      scanf("%I64d",&n);
      row = n;

      for (int i=1 ; i<=n ; i++)scanf("%I64d",&A[i]);

      for (ll i=n ; i>=1 ; i--){
            if (A[i]==1){
                  ans.push_back({row,i});
                  up[i] = row;
                  row--;
                  two.push(i);
            }
            else if (A[i]==2){
                  if (two.empty())sol = false;
                  else {
                        ll u = two.front();
                        two.pop();

                        ans.push_back({up[u],i});
                        three.push(i);
                  }
            }
            else if (A[i]==3){
                  if (!three.empty()){

                        ll u = three.front();
                        three.pop();

                        ans.push_back({row,i});
                        ans.push_back({row,u});

                        row--;
                        three.push(i);
                  }
                  else if (!two.empty()){
                        ll u = two.front();
                        two.pop();

                        ans.push_back({row,i});
                        ans.push_back({row,u});

                        row--;
                        three.push(i);
                  }
                  else sol = false;
            }
      }

      if (!sol)cout << -1 << endl;
      else {
            cout << ans.size() << endl;
            for (int i=0 ; i<ans.size() ; i++)cout << ans[i].first << " " << ans[i].second << endl;
      }

      return 0;
}
