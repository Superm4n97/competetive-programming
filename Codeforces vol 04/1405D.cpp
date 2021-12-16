#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define ll long long int
#define maxn 100005

using namespace std;

vector <ll> G[maxn];
ll n , A,B , da , db , vis[maxn];

void clean()
{
      for (int i=0 ; i<n+2 ; i++){
            G[i].clear();
      }
}

ll dis(ll u, ll p , ll d)
{
      ll ret = 0;

      if (u==B)return d;

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];
            if (v!=p){
                  ret = max(ret,dis(v,u,d+1));
            }
      }

      return ret;
}

pair <ll,ll> maxdis(ll u, ll p, ll d)
{
      pair <ll,ll> ret = make_pair(d,u);

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];

            if (v!=p){
                  pair < ll , ll > p  = maxdis(v,u,d+1);
                  if (p.first>ret.first)ret = p;
            }
      }

      return ret;
}

ll diameter()
{
      ll ff = maxdis(1,0,0).second;
      ll ss = maxdis(ff,0,0).first;

      return ss;
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            cin >> n >> A >> B >> da >> db;
            clean();

            for (int i=1;  i<n ; i++){

                  ll a, b;
                  cin >> a >> b;

                  G[a].push_back(b);
                  G[b].push_back(a);
            }

            ll coverA = 2*da;

            if (db<=coverA){
                  cout << "Alice" << endl;
                  continue;
            }

            ll temp = dis(A,0 , 0);

            if (temp<=da){
                  cout << "Alice" << endl;
                  continue;
            }

            ll mx = diameter();



            if (mx<=coverA)cout << "Alice" << endl;
            else cout << "Bob" << endl;
      }


      return 0;
}
