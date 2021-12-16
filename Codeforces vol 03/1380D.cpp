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

ll n,m,x,k,y,A[maxn],B[maxn] , fix[maxn] , mx[maxn];

ll solve(ll cnt , ll mark)
{
      if (cnt==0)return 0;

      ll sz = v.size();

      if (k*y<=x){
            if (cnt<k){
                  if (mark==0)return -1;
                  return
            }
      }
      else {

      }
}

int main()
{
      cin >> n >> m;
      cin >> x >> k >> y;

      for (int i=1 ; i<=n ; i++)cin >> A[i];
      for (int i=1 ; i<=m ; i++)cin >> B[i];

      bool sol = false;
      ll i = 1 , j = 1;

      while(i<=n && j<=m){
            if (A[i]==B[j]){
                  fix[i] = 1;
                  i++ , j++;
            }
            else i++;
      }

      if (j<=m){
            cout << -1 << endl;
      }
      else {
            fix[n+1] = 1;
            ll cnt = 0 , ans = 0;


            for (int i=n ; i>=1 ; i++)mx[i] = max(mx[i+1],A[i]);


            for (int i=1 ; i<=n+1 ; i++){

                  if (fix[i]==1){
                        ll type = 0;
                        if (mx[i]>A[i-1])type = 1;

                        ll temp = solve(cnt , type);

                        if (temp==-1){
                              cout << -1 << endl;
                              return 0;
                        }

                        ans+=temp;

                        cnt = 0;
                  }
                  if (fix[i]==0)cnt++;
            }
      }


      return 0;
}
