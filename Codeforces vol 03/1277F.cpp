#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 400005

using namespace std;

vector < ll > G[maxn] , v2 , mat[maxn] , v3;
vector < pair < ll , ll > > v , vp;
ll n,cnt[maxn] , ans = 0 , ans_a , ans_b , m , depth;
map < ll , ll > mp;

int main()
{
      cin >> n;
      for(int i=0; i<n ; i++){

            ll a;
            cin >> a;
            v2.push_back(a);
            mp[a]++;
      }
      for (int i=0 ; i<n ; i++){

            if (mp[v2[i]])v.push_back({mp[v2[i]],v2[i]});
            mp[v2[i]] = 0;
      }

      sort(v.rbegin(),v.rend());
      m = v.size();

      for (int i=0 ; i<m ; i++){

            ll temp = v[i].first , a = v[i].second;
            depth = max(depth,temp);
            for (int j = 1; j<=temp ; j++){

                  G[j].push_back(a);
            }
      }

      for (int i=depth ; i>=1 ; i--)cnt[i] = cnt[i+1]+G[i].size();

      for (ll i=1 ; i<=n ; i++){

            ll extra = cnt[i+1];
            ll total = n-extra;
            ll column = total/i;

            if (column>=i && i*column>ans){
                  ans = i*column;
                  ans_a = i;
                  ans_b = column;
            }
      }

      queue < ll > q;

      for (int i=1 ; i<=ans_a ; i++){
            if (G[i].size()>ans_b){

                  for (int j = ans_b; j<G[i].size() ; j++){
                        q.push(G[i][j]);
                  }
            }
            else {
                  while(G[i].size()<ans_b){
                        G[i].push_back(q.front());
                        q.pop();
                  }
            }
      }

      mp.clear();

      for (int i=1 ; i<=ans_a ; i++){
            for (int j=0; j<ans_b ; j++){
                  v3.push_back(G[i][j]);
                  mp[G[i][j]]++;
            }
      }

      for (int i=0 ; i<v3.size() ; i++){
            if (mp[v3[i]]){
                  vp.push_back({mp[v3[i]],v3[i]});
                  mp[v3[i]] = 0;
            }
      }

      sort(vp.rbegin(),vp.rend());

      ll nxt = 0;

      for (int i=0 ; i<vp.size() ; i++){

            while(mat[nxt].size()>=ans_b)nxt++;

            for (int j = 0 ; j<vp[i].first ; j++){
                  mat[nxt+j].push_back(vp[i].second);
            }
      }

      for (int i=0 ; i<=ans_a ; i++){
            for (int j=0 ; j<ans_b ; j++)cout << mat[i][j] << " ";
            cout << endl;
      }



      return 0;
}
