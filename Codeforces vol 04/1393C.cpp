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

            ll n;
            scl(n);

            vll test;
            map < ll , ll > mp;
            vector < pair < ll, ll > > v;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  scl(a);
                  mp[a]++;
                  if (mp[a]==1)test.push_back(a);
            }

            for (int i=0 ; i<test.size() ; i++){
                  v.push_back({mp[test[i]] , test[i]});
            }

            rsrt(v);

            ll gap= v[0].first-1 , dis = 0 , cnt = 0;

            for (int i=1  ; i<v.size() ; i++){
                  if (v[i].first>gap)v[i].first = gap;
                  cnt+=v[i].first;
            }

            ll ans = cnt/gap;

            /*

            ll b = 0 , e = n  , A[n+5] , ans = 0;
            while(b<=e){

                  ll mid = (b+e)/2;

                  memset(A,0,sizeof A);

                  ll start = 1;
                  bool sol = true;


                 show(mid);

                  for (int i=0  ;i<v.size() ; i++){
                        ll times = v[i].first;

                        while(A[start]==1)start++;

                        ll id = start;

                        for (int j = 0 ; j<times ; j++){
                              if (id>n){
                                    sol = false;
                                    show(id);
                                    show(times);
                                    show(start);

                                    break;
                              }
                              else{
                                    A[id] = 1;
                                    id = id+mid+1;
                              }
                        }

                        if (sol==false)break;
                  }

                  if (sol == true){
                        ans = max(ans,mid);
                        b = mid+1;
                  }
                  else e = mid-1;
            }
            */

            printf("%I64d\n",ans);
      }


      return 0;
}
