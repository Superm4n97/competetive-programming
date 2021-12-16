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

            ll n , ans = 0;
            cin >> n;
            ll _mp[2*n+5];
            memset(_mp , 0 , sizeof _mp);

            vll v;

            for (int i = 1 ; i<=n ; i++){
                  ll a;
                  cin >> a;
                  v.pb(a);

                  _mp[a]++;
            }

            ll mp[2*n+5];
            memset(mp,0,sizeof mp);

            for (int s = 2 ; s<=2*n ; s++){
                  for (int j=0 ; j<=n ; j++)mp[j] = _mp[j];

                  ll cnt = 0;

                  for (int i = 0 ; i<n ; i++){

                        if (mp[v[i]]){
                              mp[v[i]]--;

                              ll rem = s - v[i];

                              if (rem>0 && rem<=n && mp[rem]){

                                    mp[rem]--;
                                    cnt++;

                                    //show(s);
                                    //show(rem);
                              }
                              else {
                                    mp[v[i]]++;
                              }
                        }
                  }

                  //cout << endl;

                  ans = max(ans,cnt);
            }

            cout << ans << endl;
      }


      return 0;
}
