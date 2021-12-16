#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            map <pair<ll,ll>,ll> mp;
            vector<ll> A,B;

            for (int i=0 ; i<n ; i++){

                  ll a;
                  cin >> a;

                  A.push_back(a);

                  if ((i+1)*2>n){
                        ll id = n-i-1;
                        mp[{min(A[id],A[i]),max(A[id],A[i])}]++;
                  }
            }

            bool sol = true;

            for (int i=0 ; i<n ; i++){

                  ll a;
                  cin >> a;

                  B.push_back(a);

                  if ((i+1)*2>n){
                        ll id = n-i-1;
                        if (mp[{min(B[id],B[i]),max(B[id],B[i])}] <= 0)sol = false;
                        mp[{min(B[id],B[i]),max(B[id],B[i])}]--;
                  }
            }

            sort(A.begin(),A.end());
            sort(B.begin(),B.end());

            if (!sol || A!=B)cout << "no" << endl;
            else cout << "yes" << endl;
      }

      return 0;
}
