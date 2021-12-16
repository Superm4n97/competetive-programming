#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1005

using namespace std;

ll n,m1,m2;
ll M[maxn] , D[maxn];

ll findParentM(ll a)
{
      if (M[a]==a)return a;
      else return M[a] = findParentM(M[a]);
}

ll findParentD(ll a)
{
      if (D[a]==a)return a;
      else return D[a] = findParentD(D[a]);
}

void makeParentM(ll a, ll b)
{
      a = findParentM(a);
      b = findParentM(b);
      if (a!=b)M[a] = b;
}

void makeParentD(ll a, ll b)
{
      a = findParentD(a);
      b = findParentD(b);
      if (a!=b)D[a] = b;
}

bool checkConnectivity(ll a, ll b)
{
      ll ma = findParentM(a) , mb = findParentM(b);
      ll da = findParentD(a) , db = findParentD(b);
      if (ma==mb || da==db)return false;
      return true;
}

int main()
{
      for (int i=0 ; i<maxn ; i++)M[i] = D[i] = i;

      cin >> n >>m1 >> m2;
      for (int i=0 ; i<m1 ; i++){
            ll a,b;
            cin >> a >> b;
            makeParentM(a,b);
      }
      for (int i=0 ; i<m2 ; i++){
            ll a, b;
            cin >> a >> b;
            makeParentD(a,b);
      }

      ll cnt = 0;
      vector<pair<ll,ll> >v;

      for (int i=1 ; i<=n ; i++){
            for (int j=i+1 ; j<=n ; j++){
                  if (checkConnectivity(i,j)){
                        cnt++;
                        makeParentD(i,j);
                        makeParentM(i,j);
                        v.push_back({i,j});
                  }
            }
      }
      cout << cnt << endl;
      for (int i=0 ; i<cnt ; i++)cout << v[i].first << " " << v[i].second << endl;

      return 0;
}

