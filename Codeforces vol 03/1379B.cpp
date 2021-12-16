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
      ll tc = 1;
      scl(tc);

      while(tc--){
            ll l,r,m;
            scll(l,r);
            scl(m);

            ll offset = r-l;
            ll lft = m - offset , rgt = m+offset;

            ll ans_a , ans_b, ans_c;

            for (ll i=l ; i<=r ; i++){

                  ll temp = rgt/i;
                  ll val = temp*i;

                  if (val>=lft && val <=rgt){

                        ans_a = i;
                        ll n = temp;

                        ll tut = m - val;

                        if (tut<0){
                              ans_c = r;
                              ans_b = r+tut;
                        }
                        else {
                              ans_b = r;
                              ans_c = r - tut;
                        }

                        break;
                  }
            }

            cout << ans_a << " " << ans_b << " " << ans_c << endl;
      }


      return 0;
}

