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

            vector < ll > pos, neg;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;

                  if (a>=0)pos.push_back(a);
                  else neg.push_back(a);
            }

            sort(pos.rbegin(),pos.rend());
            sort(neg.begin(),neg.end());

            ll ans = -1000000000000000018;

            for (int i=0 ; i<=5 ; i++){
                  if (neg.size()>=i){
                        ll temp = 1;
                        if (i%2==0){
                              for (int j=0 ; j<i ; j++){
                                    temp*=neg[j];
                              }
                        }
                        else {
                              for (int j=neg.size()-1 ,k=0 ; k<i ; k++,j--)temp*=neg[j];
                        }

                        ll rem = 5-i;

                        if (pos.size()>=rem){
                              if (temp>0) for (int j=0 ; j<rem ; j++)temp*=pos[j];
                              else {

                                    for (int j = pos.size()-1 , k = 0; k<rem ; k++,j--)temp*=pos[j];
                              }
                              if (temp>ans)ans = temp;
                        }

                  }
            }

            cout << ans << endl;
      }


      return 0;
}
