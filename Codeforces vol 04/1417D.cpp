#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            ll A[n+5] , sum = 0;;

            vector < pair<pair<ll,ll>,ll> > vp;

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];

                  sum+=A[i];

                  if (i>1){
                        if (A[i]%i){

                              ll offset = i - A[i]%i;
                              vp.push_back({{1,i},offset});
                              A[1]-=offset;
                              A[i]+=offset;

                              vp.push_back({{i,1},A[i]/i});
                              A[1]+=A[i];
                              A[i] = 0;
                        }
                        else {

                              vp.push_back({{i,1},A[i]/i});
                              A[1]+=A[i];
                              A[i] = 0;
                        }
                  }
            }

            if (sum%n)cout << -1 << endl;
            else {
                  for (int i=2 ; i<=n ; i++){
                        vp.push_back({{1,i},sum/n});
                  }

                  cout << vp.size() << endl;
                  for (int i=0 ; i<vp.size() ; i++)
                        cout << vp[i].first.first << " " << vp[i].first.second << " " << vp[i].second << endl;
            }
      }

      return 0;
}
