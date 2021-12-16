#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);
      while(tc--){
            ll n;
            cin >> n;

            vector <ll> v;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  v.push_back(a);
            }

            sort(v.rbegin(),v.rend());

            ll A = 0 , B = 0;

            for (int i=0; i<n ; i++){
                  if (i%2==0 && v[i]%2==0)A+=v[i];
                  if (i%2==1 && v[i]%2==1)B+=v[i];
            }
            if (A>B)cout << "Alice" << endl;
            else if (A<B)cout << "Bob" << endl;
            else cout << "Tie" << endl;
      }

      return 0;
}
