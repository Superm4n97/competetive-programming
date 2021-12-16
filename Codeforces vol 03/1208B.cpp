#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 2005

using namespace std;

ll n,A[maxn];

int main()
{
      map < ll , ll > mppp;
      bool sol = true;

      cin >> n;
      for (int i=1 ; i<=n ; i++){
            cin >> A[i];
            mppp[A[i]]++;

            if (mppp[A[i]]>1)sol = false;
      }

      if (sol){
            cout << 0 << endl;
            return 0;
      }

      sol = true;

      ll ans = 0;

      mppp.clear();

      for (int i=0 ; i<=n ; i++){

            map < ll, ll > mp;
            ll cnt = i;

            for (int j = 1 ; j<=i ; j++){
                  mp[A[j]]++;
                  if (mp[A[j]]>1)sol = false;
            }

            if (!sol)break;

            //show(i);

            ll j = n;

            while(true){
                  if (mp[A[j]]==0){
                        mp[A[j]]++;
                        j--;
                        cnt++;
                  }
                  else {
                        break;
                  }
            }
            ans = max(ans,cnt);
      }

      cout << n-ans << endl;


      return 0;
}
