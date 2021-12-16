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

#define maxn            4200

using namespace std;

ll P[maxn] , sz[maxn] , n , dp[maxn][2006];
vector < ll > v;

ll findParent(ll a)
{
      if (P[a]==a)return a;

      return P[a] = findParent(P[a]);
}

void makeParent(ll a, ll b)
{
      a = findParent(a);
      b = findParent(b);

      P[b] = a;
      sz[a]++;
      sz[b] = 0;

      return;
}

ll rec(ll pos, ll w)
{
      //show(pos);

      if (dp[pos][w]!=-1)return dp[pos][w];

      if (pos==v.size()){
            if (w==0)return dp[pos][w] = 1;
            else return dp[pos][w] = 0;
      }

      ll t1 = 0 , t2 = 0;

      t1 = rec(pos+1,w);
      if (v[pos]<=w)t2 = rec(pos+1,w-v[pos]);

      return dp[pos][w] = max(t1,t2);
}

int main()
{
      ll tc = 1;
      scl(tc);

      while(tc--){
            cin >> n;
            ll A[n*2+5];

            v.clear();

            for (int i=1 ;i<=2*n ; i++){
                  cin >> A[i];
                  P[i] = i;
                  sz[i] = 1;
            }

            ll mx = 0;

            for (int i=1 ; i<=2*n ; i++){

                  if (A[i]>mx){
                        mx = A[i];
                  }
                  else {
//                        show(mx);
//                        show(A[i]);
//                        cout << endl;

                        makeParent(mx,A[i]);
                  }
            }

            for (int i=0 ; i<=2*n+5 ; i++){
                  for (int j=0 ; j<=n+5 ; j++)dp[i][j] = -1;
            }


            for (int i = 1 ; i<=2*n ; i++){
                  if (findParent(P[i])==i)v.push_back(sz[i]);
            }

//            for (int i=0 ; i<v.size();i++)cout << " " << v[i] ;
//            cout << endl;

            if (rec(0,n))cout << "YES" << endl;
            else cout << "NO" << endl;


      }


      return 0;
}
