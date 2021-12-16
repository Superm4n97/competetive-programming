#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll mind(ll a)
{
      ll res = 10;
      while(a){
            ll x = a%10;
            res = min(x,res);
            a/=10;
      }
      return res;
}
ll maxd(ll a)
{
      ll res = 0;
      while(a){
            ll x = a%10;
            res = max(x,res);
            a/=10;
      }
      return res;
}

int main()
{
      int tc = 1;
      cin >> tc;

      while(tc--){

            ll n,k;
            cin >> n >> k;

            vector < ll > v;
            v.push_back(n);

            while(true){

                  ll temp = n + mind(n)*maxd(n);
                  if (temp==n)break;
                  else {
                        v.push_back(temp);
                        n = temp;
                  }
            }
            //show(v.size());


            k--;

            if (k<v.size())cout << v[k] << endl;
            else {
                  ll m = v.size()-1;
                  cout << v[m] << endl;
            }
      }

      return 0;
}
