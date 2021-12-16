#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;scl(tc);

      while(tc--){
            ll n , A[10] , mp[7][7];
            scl(n);
            memset(mp,0,sizeof mp);

            cin >> A[1] >> A[2] >> A[3] >> A[4];

            bool sol = true;

            for (int i=1 ; i<=4 ; i++){
                  ll l = i-1 , r = i+1;
                  if (l==0)l = 4;
                  if (r==5)r = 1;

                  if (A[i]<0)sol = false;

                  if (A[i]==n){
                        A[l]--;
                        A[r]--;
                        A[i]-=2;
                        mp[i][l] = mp[l][i] = mp[i][r] = mp[r][i] = 1;
                        if (A[l]<0 || A[r]<0)sol = false;
                  }
                  else if (A[i]==n-1){

                        if (A[r]>A[l] && mp[i][r]==0 && A[r]>0){
                              A[r]--;
                              A[i]--;
                              mp[i][r] = mp[r][i] = 1;
                        }
                        else if (A[l] && mp[i][l]==0){
                              A[l]--;
                              A[i]--;
                              mp[i][l] = mp[l][i] = 1;
                        }
                        else if (A[r] && mp[i][r]==0){
                              A[r]--;
                              A[i]--;
                              mp[i][r] = mp[r][i] = 1;
                        }
                        else {
                              sol = false;
                        }
                  }
            }

            if (sol)cout << "YES" << endl;
            else cout << "NO" << endl;
      }


      return 0;
}
