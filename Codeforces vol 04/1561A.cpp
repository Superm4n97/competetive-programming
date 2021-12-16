#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

vector<ll> v;
ll n;

bool isSorted()
{
      for (int i=1 ; i<n ; i++){
            if(v[i]<v[i-1])return false;
      }
      return true;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            v.clear();
            scanf("%lld",&n);
            for (int i=0 ; i<n ; i++){
                  ll a;
                  scanf("%lld",&a);
                  v.push_back(a);
            }

            ll cnt = 0;
            for (int i=0 ; i<n ; i++){
                  if (isSorted())break;
                  cnt++;
                  ll type = i%2;
                  for (int j=type ; j<n-1 ; j+=2){
                        if (v[j]>v[j+1]){
                              swap(v[j],v[j+1]);
                        }
                  }
            }
            cout << cnt << "\n";
      }

      return 0;
}
