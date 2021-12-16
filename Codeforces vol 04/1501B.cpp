#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >>tc;

      while(tc--){
            ll n;
            cin >> n;

            ll A[n+5] ,cnt[n+5];
            memset(cnt,0,sizeof cnt);

            for (ll i=1 ; i<=n ; i++){
                  cin >> A[i];
                  if (A[i]>0){
                        cnt[max(1LL,i-A[i]+1)] += 1;
                        cnt[i+1]--;
                  }
            }
            for (int i=1 ; i<=n ; i++){
                  cnt[i] += cnt[i-1];
                  if (cnt[i]>0)cout << "1 ";
                  else cout << "0 ";
            }
            cout << endl;
      }

      return 0;
}
