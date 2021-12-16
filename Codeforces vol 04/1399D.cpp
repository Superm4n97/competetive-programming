#include <bits/stdc++.h>
#define ll              long long int
#define show(x)         cout << #x << " : " << x << endl
#define maxn            1000006

using namespace std;


int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            stack < ll> zero, one;
            ll n;
            cin >> n;

            vector < ll > v[n];

            string s;
            cin >> s;

            ll nw = 0 , ans[n+4];

            for (int i=0; i<n ; i++){
                  if(s[i]=='0'){
                        if(one.empty()){
                              zero.push(nw);
                              v[nw].push_back(i);
                              nw++;
                        }
                        else{
                              ll id = one.top();
                              one.pop();
                              v[id].push_back(i);
                              zero.push(id);
                        }
                  }
                  else{
                        if(zero.empty()){
                              one.push(nw);
                              v[nw].push_back(i);
                              nw++;
                        }
                        else{
                              ll id = zero.top();
                              zero.pop();
                              v[id].push_back(i);
                              one.push(id);
                        }
                  }
            }

            for (int i = 0; i<nw ; i++){
                  for(int j = 0; j<v[i].size(); j++){
                        ll u = v[i][j];
                        ans[u] = i+1;
                  }
            }

            cout << nw << endl;

            for (int i = 0 ; i<n; i++)cout << ans[i] << " ";
            cout << endl;

      }

      return 0;
}
/*
1110111011
3
1
3
5
2

1111000
*/
