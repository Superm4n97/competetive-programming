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

char opposit(char ch)
{
      return '0'+'1' - ch;
}

int main()
{
      ll tc = 1;
      scl(tc);

      while(tc--){

            ll n;
            cin >> n;
            string a,b;

            cin >> a >> b;

            string s = a;

            vector < ll > ans;

            ll x = 0 , y = n-1 , i = n-1 , mark = 0;

            for (ll i=n-1 ; i>=0 ; i--){

                  char rev;

                  //show(n-i);

                  if ((n-i)%2){
                        rev = opposit(a[x]);
                       // show(x);
//                        show(i);
                        x++;
                  }
                  else {
                        rev = a[y];
                        //show(y);
                        y--;
                  }

                  if (rev!=b[i]){
                        ans.pb(1);
                        ans.pb(i+1);
                  }
                  else {
                        ans.pb(i+1);
                  }
            }

            cout << ans.size() << " ";
            for (int i=0 ; i<ans.size() ; i++)cout << ans[i] << " ";
            cout << endl;

      }


      return 0;
}

