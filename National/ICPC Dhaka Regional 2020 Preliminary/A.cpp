#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

vector<ll> primes;

void sve()
{
      show("ok");

      ll maxn = 1000012;
      show(maxn);
      ll cnt[1000012];
      cout << "check" << endl;
      memset(cnt,0LL,sizeof(cnt));

      for (ll i = 2 ; i<maxn ; i++){
            if (cnt[i]==0LL){
                  primes.push_back(i);
                  show(i);
                  for (ll j = i*i ; j<maxn ; j+=i){
                        cnt[j] = 1;
                  }
            }
      }
}

int main()
{
      sve();
      show(primes.size());

      return 0;
}
