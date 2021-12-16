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

            ll n,k,z;
            cin >> n >> k >> z;

            ll A[n+5] , csum[n+5];
            csum[0] = 0;

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];
                  csum[i] = csum[i-1]+A[i];
            }

            ll sum = A[1] , ans = A[1];

            for (int i=2 ; i<=n ; i++){
                  sum+=A[i];

                  ll r = i-1;

                  if (r>k)break;

                  if (z+z>=k-r){
                        ll temp = (k-r)/2;


                        ll tut= A[i-1]*temp + A[i]*temp;
                        /*if(i==3){
                              show(temp);
                              show(sum);
                              show(tut);
                        }*/
                        tut+=sum;

                        if((k-r)%2)tut+=A[i-1];

                        ans = max(ans,tut);
                  }
                  else {
                        ll temp = z;
                        ll tut = A[i-1]*temp + A[i]*temp;
                        tut+=sum;

                        ll baki = k-r-z-z;
                        tut+=csum[i+baki] - csum[i];

                        ans = max(ans,tut);
                  }
            }
            cout << ans << endl;
      }


      return 0;
}
