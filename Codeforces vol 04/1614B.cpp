#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll finalResult[200006];

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;

            vector<pair<ll,ll> > listOfVis;

            for (int i=1 ; i<=n ; i++){
                  ll a;
                  cin >> a;
                  listOfVis.push_back({a,i});
            }

            sort(listOfVis.rbegin(),listOfVis.rend());

            ll l = -1, r = 1 , cost = 0;

            for (int i=0 ; i<n ; i++){
                  if (i%2){
                        finalResult[listOfVis[i].second] = r;
                        r++;
                  }
                  else {
                        finalResult[listOfVis[i].second] = l;
                        l--;
                  }
                  cost += abs(listOfVis[i].first)*abs(finalResult[listOfVis[i].second])*2;
            }
            cout << cost << endl;
            cout << 0 << " ";
            for (int i=1 ; i<=n ; i++)cout << finalResult[i] << " ";
            cout << endl;
      }

      return 0;
}
