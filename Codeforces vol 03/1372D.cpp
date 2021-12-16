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

#define maxn            200005

using namespace std;

ll n;
ll A[maxn] , vis[maxn];
priority_queue < pair < pair < ll , ll > , pair < ll, ll > > >  pq;

int main()
{
      cin >> n;

      for (ll i=1 ; i<=n ; i++){
            cin >> A[i];

            ll lf = i-1 , rg = i+1;
            if (lf==0)lf = n;
            if (rg==n+1)rg = 1;

            pq.push({{A[i]*-1 , i} , {lf,rg}});
      }

      if (n==1){
            cout << A[1] << endl;
            return 0;
      }

      while(pq.size()>1){
            ll num = pq.top().first.first*-1 , id = pq.top().first.second , lf = pq.top().second.first , rg = pq.top().second.first;
            pq.pop();

            if (vis[id]==1)continue;

            ll newNumber =
      }


      return 0;
}
