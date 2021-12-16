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

ll A[maxn] , csum[maxn];

ll indexSum(ll l, ll r)
{
      ll a = r*(r+1)/2 , b = max((l-1)*l/2 , 0LL);

      return a-b;
}

ll effortCalculation(ll l, ll r)
{
      return csum[r]-csum[l-1] + (r-l+1) * indexSum(l,r);
}

int main()
{
      ll n,s;
      cin >> n >> s;

      for (int i=1 ; i<=n ; i++){
            scanf("%lld",&A[i]);
            csum[i] = csum[i-1]+A[i];
      }

      ll l=1 , r=1 , ans = 0;

      while(r<=n){
            while(effortCalculation(l,r)>s){
                  l++;
                  if (l>r)break;
            }

            if (l>r)l = r;

            if (effortCalculation(l,r)<=s){
                  ans = max(ans,r-l+1);
            }

            r++;
      }

      cout << ans << endl;



      return 0;
}

/**

*/
