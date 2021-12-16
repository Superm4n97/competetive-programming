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

            ll n,k;
            cin >> n >> k;

            ll A[4][n+5] , mx1 = -inf , mx2 = -inf;

            for (int i=1 ; i<=n ; i++){

                  cin >> A[0][i];
                  mx1 = max(mx1,A[0][i]);
            }

            for (int i=1 ; i<=n; i++){

                  A[1][i] = mx1 - A[0][i];
                  mx2 = max(mx2,A[1][i]);
            }

            for (int i=1 ; i<=n ; i++){

                  A[2][i] = mx2 - A[1][i];
            }

            if (k%2)for (int i=1 ; i<=n ;i++)cout << A[1][i] << " ";
            else for (int i=1;i<=n ; i++)cout << A[2][i] << " ";
            cout << endl;
      }


      return 0;
}
