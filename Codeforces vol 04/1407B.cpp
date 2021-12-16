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

            ll A[n+5] , mx  = 0, id;

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];

                  if (A[i]>mx){
                        mx = A[i];
                        id = i;
                  }
            }

            vector < ll  > v;
            v.push_back(mx);

            A[id] = 0;

            for (int k =2 ; k<=n ; k++){

                  ll new_mx = 0 , new_id;

                  for (int i=1 ; i<=n ; i++){
                        if (A[i]){
                              if (__gcd(mx,A[i])>new_mx){
                                    new_id = i;
                                    new_mx = __gcd(mx,A[i]);
                               }
                        }
                  }

                  v.push_back(A[new_id]);
                  A[new_id] = 0;
                  mx = new_mx;
            }

            for (int i=0 ; i<v.size() ; i++)cout << v[i] << " ";
            cout << endl;
      }


      return 0;
}
