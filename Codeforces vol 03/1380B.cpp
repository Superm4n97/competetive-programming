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

char ff(char ch)
{
      if (ch=='R')return 'P';
      if (ch=='S')return 'R';
      if (ch=='P')return 'S';
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            string s;
            cin >> s;

            ll cnt[5];
            cnt[0] = cnt[1] = cnt[2] = 0;

            for (int i=0 ; i<s.size();i++){
                   ll ch = ff(s[i]);
                   if (ch=='R')cnt[0]++;
                   else if (ch=='P')cnt[1]++;
                   else cnt[2]++;
            }
            char ans;

            if (cnt[0]>=cnt[1]&& cnt[0]>=cnt[2])ans = 'R';
            if (cnt[1]>=cnt[0]&& cnt[1]>=cnt[2])ans = 'P';
            if (cnt[2]>=cnt[1]&& cnt[2]>=cnt[0])ans = 'S';

            for (int i=0 ; i<s.size(); i++)cout << ans;
            cout << endl;
      }


      return 0;
}
