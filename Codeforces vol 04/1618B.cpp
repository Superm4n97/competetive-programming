#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin >> n;

            n-=2;
            vector<string> v;
            for (int i=0 ; i<n ; i++){
                  string s;
                  cin >> s;
                  v.push_back(s);
            }
            bool paisi = false;
            cout << v[0] ;
            for (int i=1 ; i<n ; i++){
                  if (v[i][0] == v[i-1][1])cout << v[i][1];
                  else {
                        cout << v[i];
                        paisi = true;
                  }
            }
            if (paisi==false)cout << v[n-1][1];

            cout << endl;
      }

      return 0;
}
