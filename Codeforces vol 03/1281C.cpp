#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000007

using namespace std;

string s;

void make(ll x)
{
      ll id = 0;
      while(s.size()<x){
            ll tms = s[id]-'0';
            ll l = id+1 , r = s.size();
            for (int i=0 ;i<tms-1 ; i++){
                  for (int j = l ; j<r ; j++){
                        s.push_back(s[j]);
                        if (s.size()>x)break;
                  }
                  if (s.size()>x)break;
            }
            if (id==x-1)break;

            id++;
      }
      //show(s);
      //show(s.size());
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll x;
            cin >> x;

            cin >> s;


            ll sz = s.size();

            make(x);

            for (int i=0 ; i<x ; i++){
                  ll tms = s[i]-'0';

                  ll len = (sz-i-1+mod)%mod;
                  len*=tms;
                  len+=i+1;

                  len%=mod;
                  sz = len;
            }
            cout << sz << endl;
      }



      return 0;
}
