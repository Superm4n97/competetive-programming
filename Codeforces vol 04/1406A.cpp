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
            ll cnt[200];
            memset(cnt,0,sizeof cnt);

            ll zero = 0 , one = 0;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;

                  cnt[a]++;
            }

            for (int i=0 ; i<=105 ; i++){
                  if (cnt[i]==0){
                        zero = i;
                        break;
                  }
                  else cnt[i]--;
            }

            for (int i=0 ; i<=105 ; i++){
                  if (cnt[i]==0){
                        one= i;
                        break;
                  }
                  else cnt[i]--;
            }

            cout << zero+one << endl;
      }


      return 0;
}
