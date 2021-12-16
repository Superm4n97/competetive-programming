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
            string s;
            cin >> s;

            string X[n+5];
            vector<ll> v;
            for (int i=0 ; i<n;  i++){
                  for (int j=0 ; j<n ; j++){
                        if (i==j)X[i].push_back('X');
                        else X[i].push_back('=');
                  }
                  if (s[i]=='2')v.push_back(i);
            }
            ll sol = 1;
            if (v.size()==1 || v.size()==2)sol = 0;
            for (int i=0 ; i<v.size() ; i++){
                  if (i==v.size()-1){
                        X[v[i]][v[0]] = '+';
                        X[v[0]][v[i]] = '-';
                  }
                  else {

                        X[v[i]][v[i+1]] = '+';
                        X[v[i+1]][v[i]] = '-';
                  }
            }
            if(!sol)cout << "NO" << endl;
            else {
                  cout << "YES" << endl;
                  for (int i=0 ; i<n ; i++)cout << X[i] << endl;
            }
      }

      return 0;
}
