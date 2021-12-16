#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define show(x)         cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            1000006

using namespace std;

vector <ll > G[13];
string s;
ll n;

void clean()
{
      for (int i=0 ; i<=9 ; i++)G[i].clear();
}

ll solve(ll x, ll y)
{
      ll num = 0 , i = 0 , j = 0 , prev = -1;

      while(true){
            while(i<G[x].size() && G[x][i]<=prev)i++;
            if (i>=G[x].size())return num;

            prev = G[x][i];

            while(j<G[y].size() && G[y][j]<=prev)j++;

            if (j>=G[y].size())return num;

            prev = G[y][j];
            num+=2;
      }
}


int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            clean();
            cin >> s;
            n = s.size();

            for (int i=0 ; i<n ; i++){
                  ll temp = s[i]-'0';
                  G[temp].pb(i);
            }

            ll ans = 0;

            for (int i=0 ; i<=9 ; i++){
                  for (int j = 0 ; j<=9 ; j++){
                        if (i==j){
                              //show(i);
                              //show(G[i].size());

                              ll temp = G[i].size();
                              ans = max(temp , ans);

                              //show(ans);
                        }
                        else {
                              if (G[i].empty()|| G[j].empty())continue;
                              ans = max(solve(i,j) , ans);
                        }
                  }
            }

            cout << n-ans << endl;
      }


      return 0;
}
