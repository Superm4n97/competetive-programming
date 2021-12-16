#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1005

using namespace std;

ll n,k;
vector < string > vs[maxn] , v;
vector < ll > G[1000];
int mp[1000][1000] , inDegree[1000];
set<ll> st;

int main()
{
      cin >> n >> k;

      for (int t = 0 ; t<n ; i++){
            ll a;
            cin >> a;

            for (int i=0 ; i<k ; i++){
                  string s;
                  cin >> s;

                  vs[a].push_back(s);
            }
      }

      for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<k ; j++)v.push_back(vs[i][j]);
      }

      vector < ll > numbers;

      for (int i=1 ; i<v.size() ; i++){
            for (int j=0 ; j<min(v[i].size(),v[i-1].size()) ; j++){

                  if(v[i][j]!=v[i-1][j]){

                        ll a = v[i-1][j] , b = v[i][j];

                        if (mp[a][b]==0){
                              G[a].push_back(b);
                              mp[a][b] = 1;
                              inDegree[b]++;
                              st.insert(i);
                              numbers.push_back(a);
                        }

                        break;
                  }
            }
      }

      ll cnt = 0;

      queue<ll> q;
      for (int i=0 ; i<numbers.size() ; i++){
            if (inDegree[numbers[i]]==0){
                  q.push(numbers[i]);
                  cnt++;
                  inDegree[numbers[i]] = -1;
            }
      }

      vector <

      while(!q.empty()){

            ll u = q.front();
            q.pop();

            for (int i=0 ; i<G[u].size() ; i++){

                  ll v = G[u][i];
                  inDegree[v]--;

                  if (inDegree[v]==0){
                        q.push(v);
                        cnt++;
                        inDegree[v] = -1;
                  }
            }
      }

      if (cnt==st.size())

      return 0;
}
