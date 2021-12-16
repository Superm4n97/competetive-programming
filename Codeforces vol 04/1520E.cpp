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
            string s;
            cin >> s;

            ll L[n+5] , R[n+5];
            L[0] = R[n-1] = 0;
            if (s[0]=='*')L[0] = 1;
            if (s[n-1]=='*')R[n-1] = 1;

            for (int i=1 ; i<n ; i++){
                  if (s[i]=='*')L[i] = L[i-1]+1;
                  else L[i] = L[i-1];
            }
            for (int i=n-2 ; i>=0 ; i--){
                  if (s[i]=='*')R[i] = R[i+1]+1;
                  else R[i] = R[i+1];
            }

//            for (int i=0 ; i<n ; i++)cout << L[i] << " ";
//            cout << endl;
//            for (int i=0 ; i<n ; i++)cout << R[i] << " ";
//            cout << endl;

            ll ans = 0;
            for (int i=0 ; i<n ; i++){
//                  cout << L[i] << R[i] << endl;
                  if (s[i]=='.'){
                        ans+=min(L[i],R[i]);
                  }
            }
            cout <<ans << "\n";
      }


      return 0;
}
