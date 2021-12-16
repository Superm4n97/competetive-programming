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

ll A[305][305] , n,m;
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

void clean()
{
      for (int i=0 ; i<n+2 ; i++){
            for (int j = 0 ; j<=m+5 ; j++)A[i][j] = 0;
      }
}

bool check(ll x, ll y)
{
      if (x<=n && x>=1 && y<=m && y>=1)return true;
      return false;
}

int main()
{
      int tc = 1;
      cin >> tc;

      while(tc--){

            cin >> n >> m;

            clean();


            bool solution = true;


            for (int i=1 ; i<=n ; i++){
                  for (int j = 1 ; j<=m ; j++)cin  >> A[i][j];
            }

            for (int i=1 ; i<=n; i++){
                  for (int j = 0 ; j<=m ; j++){

                        ll aroundCell = 0 ;

                        for (int k = 0 ;k<4 ; k++){

                              ll x = i+dx[k] , y = j+dy[k];
                              if (check(x,y)){

                                    aroundCell++;
                              }
                        }

                        if (aroundCell<A[i][j])solution = false;
                        A[i][j] = aroundCell;
                  }
            }

            if (!solution)cout << "NO" << endl;
            else {
                  cout << "YES" << endl;
                  for (int i = 1;  i<=n;i++){
                  for (int j=1 ; j<=m ; j++)cout << A[i][j] << " ";
                  cout << endl;
            }
            }
      }


      return 0;
}
