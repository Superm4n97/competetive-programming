#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n,k;
            cin >> n >> k;

            string a,b;
            cin >> a >> b;

            ll need[30] , have[30];
            memset(need,0,sizeof need);
            memset(have,0,sizeof have);

            for (int i=0 ; i<n ; i++){
                  ll temp = b[i] - 'a';
                  need[temp]++;
            }

            for (int i=0 ; i<n ; i++){
                  ll temp = a[i] - 'a';
                  have[temp]++;
            }

            bool sol = true;

            for (int i=0 ; i<=25 ; i++){
                  if (need[i]>have[i]){
                        sol = false;
                        break;
                  }

                  have[i]-=need[i];

                  if (have[i]%k!=0){
                        sol = false;
                        break;
                  }

                  have[i+1]+=have[i];
            }

            cout << (sol?"Yes":"No") << "\n";
      }

      return 0;
}
