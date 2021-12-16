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
      for (int x = 1 ; x<=10 ; x++){
            for (int y=0 ; y<=x*x ; y++){

                  //while(tc--){

                        ll n = x ,k =y , ans;

                        char G[n+5][n+5];
                        for (int i=0 ; i<=n ; i++){
                              for (int j=0 ; j<=n;j++)G[i][j] = '0';
                        }

                        if (k<=n){
                              if (k==n || k==0)ans = 0;
                              else ans = 2;

                              for (int i=0 ; i<n ; i++){
                                    for (int j=0; j<n ;j++){
                                          if (i==j && k>0){
                                                G[i][j] = '1';
                                                k--;
                                          }
                                    }
                              }
                        }
                        else {
                              ll perRC = k/n , rem = k%n;
                              ll increment = __gcd(n,perRC) , start = 0;

                              for (int i=0 ; i<n ; i++){

                                    for (int j=start , l = 0; l<perRC ;j++,l++){

                                          if (j>=n)j-=n;

                                          G[i][j] = '1';
                                    }

                                    start+=increment;
                                    start%=n;
                              }

                              ll mpr[n+5] , mpc[n+5];
                              memset(mpr,0,sizeof mpr);
                              memset(mpc,0,sizeof mpc);

                              ll p = rem;

                              for (int i=0 ; i<n;i++){
                                    for (int j=0 ; j<n; j++){

                                          if (mpr[i]==0 && mpc[j]==0 && G[i][j]=='0' && p>0){
                                                G[i][j] = '1';
                                                p--;
                                                mpr[i] = 1;
                                                mpc[j] = 1;
                                          }
                                    }
                              }

                              if (rem>0)ans = 2;
                              else ans = 0;
                        }
                  //}

                  ll mxr = 0 , mnr = 1000 , mxc = 0 , mnc = 1000 , tc = 0 , tr = 0;



                  for (int i=0 ; i<n ; i++){
                        ll R = 0 , C = 0;
                        for (int j = 0 ; j<n ; j++){
                              if (G[i][j]=='1')R++ , tr++;
                              if (G[j][i]=='1')C++ , tc++;
                        }
                        mxr = max(R,mxr);
                        mnr = min(R,mnr);

                        mxc = max(mxc,C);
                        mnc = min(C,mnc);
                  }
                  if (tc==k && tr==k){
                        if ((mxc-mnc)*(mxc-mnc) + (mxr-mnr)*(mxr-mnr) == ans)continue;
                        else {
                              show("ERROR");
                              show(n);
                              show(k);
                        }
                  }
                  else {
                        show("ERROR 2");
                        show(n);
                        show(k);
                        show(tc);
                        show(tr);

                        for (int i=0 ; i<n;i++){
                              for (int j=0 ; j<n;j++){
                                    cout << G[i][j];
                              }
                              cout << endl;
                        }
                  }
            }
      }


      return 0;
}
