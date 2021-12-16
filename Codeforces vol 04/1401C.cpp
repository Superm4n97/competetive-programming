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


int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n , mn = inf;
            scl(n);

            vll v , u;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  scl(a);

                  v.push_back(a);
                  mn = min(mn,a);
            }

            u = v;

            ll mp[n+5];
            memset(mp,0,sizeof mp);

            for (int i=0 ; i<n ; i++){
                  if(v[i]%mn==0)mp[i] = 1;
            }

            srt(v);

            bool sol = true;

            for (int i=0 ; i<n ; i++){

                  if (u[i]!=v[i] && mp[i]==0)sol = false;
            }

            cout << (sol?"YES":"NO") << "\n";
      }



      return 0;
}

/**

*/
