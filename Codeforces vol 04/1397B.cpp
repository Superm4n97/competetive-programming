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

ll n;
vector < ll > v;

int main()
{
      cin >> n;
      inputll(v,n);
      srt(v);

      ll ans = 0;

      for (int i=0 ; i<n; i++)ans += v[i]-1;

      //show(ans);

      for (ll p=2 ; p<1000000 ; p++){
            ll pw = 1 , temp = 0 , ese = 0;

            for (ll i=0 ; i<n ; i++){

                  temp += abs(pw-v[i]);
                  if (temp>ans)break;

                  ese++;
                  pw*=p;
            }

            if (ese==n)ans = min(ans,temp);
      }

      cout << ans << endl;


      return 0;
}

/**

*/
