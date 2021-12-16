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
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define show(x)         cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            10000006

using namespace std;

ll A[maxn] , B[maxn] , n;

int main()
{
      //scanf("%lld",&n);
      cin >> n;
      //show(n);

      A[1] = 1;

      for (ll i=2 ; i<=n;i++)A[i] = 1;

      //show(n);

      for (ll i = 2 ; i<=n;i++){
            if (!B[i]){
                  A[i] = 2;

                  for (ll j = i+i ; j<= n ; j+=i){
                        ll temp = j , cnt = 0;
                        while(temp%i==0){
                              cnt++;
                              temp/=i;
                        }

                        A[j]*=(cnt+1);
                        B[j]=1;
                  }
            }
      }

      for (ll i=2 ; i<=n;i++){
            if (B[i]==0)A[i] = 2;
      }

      ll ans = 0;
      for (ll i=1 ; i<=n;i++){
            ans+=(i*A[i]);

            //show(ans);
      }
      cout << ans << endl;


      return 0;
}

