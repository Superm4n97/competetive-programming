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

string t = "abacaba";


ll recheck(string s , ll n)
{
      ll cnt = 0;
      for (int i=0 ; i+6<n ; i++){
                  bool check = true;

                  for (int j = 0 ; j<7 ; j++){
                        if (s[i+j] !=t[j]){
                              check = false;
                              //show(j);
                        }
                  }
                  if (check)cnt++;
      }
      return cnt;
}

int main()
{
      int tc = 1;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;
            string s;
            cin >> s;

            ll cnt = recheck(s,n);

            bool sol = false;

            if (cnt>1){
                  cout << "NO" << endl;
            }
            else if (cnt==1){
                  for (int i=0 ; i<n ; i++){
                        if (s[i]=='?')s[i] = 'z';
                  }

                  cout << "YES" << endl << s << endl;
            }
            else {
                  for (int i=0 ; i+6<n ; i++){

                        bool check = true;
                        string st = s;

                        for (int j = 0 ; j<7 ; j++){
                              if (st[i+j]=='?')st[i+j] = t[j];
                        }
                        if (recheck(st,n)==1){

                              for (int j = 0 ; j<n ; j++){
                                    if (st[j]=='?')st[j] = 'z';
                              }
                              sol = true;
                              s = st;
                              break;
                        }
                  }
            if (sol)cout << "YES" << endl << s << endl;
            else cout << "NO" << endl;
            }

      }


      return 0;
}
