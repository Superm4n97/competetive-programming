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
      ll tc = 1;
      scl(tc);

      while(tc--){

            ll n,m;
            cin >> n >> m;
            ll cnt[1005];
            memset(cnt,0,sizeof cnt);

            for (int i=0 ; i<n; i++){
                  ll a;
                  cin >> a;

                  cnt[a]=1;
            }

            ll k=0, ans;

            for (int i=0 ; i<m ;i++){
                  ll a;
                  cin >> a;
                  if (cnt[a]==1){
                        k = 1;
                        ans = a;
                  }
            }

            if (k==0)cout << "NO" << endl;
            else {
                  cout << "YES" << endl;
                  cout << 1<< " " << ans << endl;
            }
      }


      return 0;
}