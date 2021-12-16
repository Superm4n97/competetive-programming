#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){

            ll n;
            cin >> n;
            ll A[n+5] , cnt[n+5];
            vector <ll> v;

            memset(cnt,0,sizeof cnt);

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];
                  v.push_back(A[i]);
            }

            ll x = 1 , y = n , ans = n;

            sort(v.begin(),v.end());
            bool temp = true;
            for (int i=1 ; i<n ; i++){
                  if (v[i]!=v[i-1]+1){
                        temp = false;
                  }
            }
            if (v[0]!=1)temp = false;

            if (v[0]==1)cnt[n] = 1;
            if (temp)cnt[1] = 1;

            ll k = 1;

            while(x<=y){
                  if (A[x]==k && A[y]==k){
                        ans = k;
                        break;
                  }
                  else if (A[x]==k){
                        x++;
                        k++;
                  }
                  else if (A[y]==k){
                        y--;
                        k++;
                  }
                  else {
                        ans = k;
                        break;
                  }
            }

            for (int i=1 ; i<n ; i++){
                  if (v[i]==v[i-1]){
                        ans = min(ans,v[i]);
                        break;
                  }
            }

            for (int i=2 ; i<n ; i++)cnt[i] = 1;
            ll lim = n-ans;
            for (int i=2 ; i<=lim ; i++)cnt[i] = 0;

            for (int i=1 ; i<=n ; i++)cout << cnt[i] ;
            cout << "\n";
      }

      return 0;
}
