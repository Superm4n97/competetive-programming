#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

string s;
vector<ll> awin,alose,bwin,blose;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            cin >> s;
            awin.clear();
            bwin.clear();
            alose.clear();
            blose.clear();

            for (int i=0 ; i<10 ; i++){
                  if (i%2==0){
                        if (s[i]=='0' || s[i]=='1'){
                              ll temp  = s[i] - '0';
                              alose.push_back(temp);
                              awin.push_back(temp);
                        }
                        else {
                              alose.push_back(0);
                              awin.push_back(1);
                        }
                  }
                  else {
                        if (s[i]=='0' || s[i]=='1'){
                              ll temp  = s[i] - '0';
                              blose.push_back(temp);
                              bwin.push_back(temp);
                        }
                        else {
                              blose.push_back(0);
                              bwin.push_back(1);
                        }
                  }
            }

            for (int i=1 ; i<5 ; i++){
                  awin[i]+=awin[i-1];
                  bwin[i]+=bwin[i-1];
                  alose[i]+=alose[i-1];
                  blose[i]+=blose[i-1];
            }

            int ans = 10;

            for (int i=1 ; i<=10 ; i++){
                  ll a = (i+1)/2, b = i/2;

//                  if (i==5){
//                  show(a);
//                  show(b);
//                  show(awin[a]);
//                  show(b-blose[b]);
//                  }
                  if (awin[a-1]+(b-blose[b-1])==6 || (a-alose[a-1])+bwin[b-1]==6)ans = min(ans,i);
            }
            cout << ans << "\n";
      }

      return 0;
}
