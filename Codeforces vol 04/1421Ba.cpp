#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define maxn  206

using namespace std;

char rev(char ch)
{
      if (ch=='0')return '1';
      return '0';
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){

            ll n;
            cin >> n;

            vector <string> s;

            for (int i=0 ; i<n ; i++){
                  string ss;
                  cin >> ss;

                  s.push_back(ss);
            }

            vector < pair <ll,ll > > vp;

            if (s[0][1]==s[1][0]){
                  if (s[n-1][n-2]==s[0][1])vp.push_back({n-1,n-2});
                  if (s[n-2][n-1]==s[0][1])vp.push_back({n-2,n-1});
            }
            else if (s[n-1][n-2]==s[n-2][n-1]){
                  if (s[0][1]==s[n-1][n-2])vp.push_back({n-1,n-2});
                  if (s[0][1]==s[n-2][n-1])vp.push_back({n-2,n-1});
            }
            else {
                  if (s[n-1][n-2]=='0')vp.push_back({n-1,n-2});
                  if (s[n-2][n-1]=='0')vp.push_back({n-2,n-1});
                  if (s[1][0]=='1')vp.push_back({1,0});
                  if (s[0][1]=='1')vp.push_back({0,1});
            }

            if (vp.empty()){
                  cout << 0 << endl;
                  continue;
            }

            cout << vp.size() << endl;
            for (int i=0 ; i<vp.size() ;i++)cout << vp[i].first+1 << " " << vp[i].second+1 << endl;
      }

      return 0;
}
