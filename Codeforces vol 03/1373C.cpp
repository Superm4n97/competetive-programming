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
#define show(x) cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            1000006

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            string s;
            cin >> s;
            ll n = s.size() , ans = 0;
            ll level[n+4];
            map < ll , ll > mp;
            memset(level,0,sizeof level);

            for (int i=0 ; i<s.size() ; i++){
                  if (s[i]=='-')level[i] = -1;
                  else level[i] = 1;

                  if (i!=0)level[i]+=level[i-1];

                  mp[level[i]]++;

                  if (level[i]<0 && mp[level[i]]==1){
                        ans+=i+1;
                  }
            }

            cout << ans+n << endl;
      }


      return 0;
}
