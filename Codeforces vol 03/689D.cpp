#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 10000000000000016
#define maxn 200005

using namespace std;

ll id[maxn*10],SA[20][maxn] , SB[20][maxn] , n , ans = 0;

int main()
{
      for (int i=0 ; i<=18 ; i++){
            for (int j= 0 ; j<maxn ; j++){

                  SA[i][j] = -inf;
                  SB[i][j] = inf;
            }
      }

      cin >> n;
      for (int i=1 ; i<=n ; i++)cin >> SA[0][i];
      for (int i=1 ; i<=n ; i++)cin >> SB[0][i];

      /// sparse table

      for (int i=1 ; i<=18 ; i++){
            for (int j=1 ; j<=n ; j++){

                  ll temp = min(maxn-2 , j + (1 << i-1));
                  SA[i][j] = max(SA[i-1][j] , SA[i-1][temp]);
                  SB[i][j] = min(SB[i-1][j] , SB[i-1][temp]);
            }
      }

      ll temp = 1;
      for (int i=0 ; i<=18 ; i++){
            id[temp] = i;
            temp*=2;
      }
      for (int i=2 ; i<maxn*10 ; i++){
            if (id[i]==0)id[i] = id[i-1];
      }

      for (int i=1 ; i<=n; i++){

            ll upperBound = -1 , lowerBound = n+4;

            /// upper Bound
            ll b = 1 , e = n-i+1;

            while(b<=e){

                  ll mid = (b+e)/2;
                  ll interval = id[mid] , l = i , r = i+mid-1;

                  ll mx = max(SA[interval][l] , SA[interval][r - (1 << interval) + 1]);
                  ll mn = min(SB[interval][l] , SB[interval][r - (1 << interval) + 1]);

                  if (mn==mx){
                        upperBound = max(mid,upperBound);
                        b = mid+1;
                  }
                  else if (mx>mn){
                        e = mid-1;
                  }
                  else b = mid+1;
            }

            if (upperBound==-1)continue;

            ///lower bound
            b = 1 , e = n-i+1;

            while(b<=e){

                  ll mid = (b+e)/2;
                  ll interval = id[mid] , l = i , r = i+mid-1;

                  ll mx = max(SA[interval][l] , SA[interval][r - (1 << interval) + 1]);
                  ll mn = min(SB[interval][l] , SB[interval][r - (1 << interval) + 1]);

                  if (mn==mx){
                        lowerBound = min(mid,lowerBound);
                        e = mid-1;
                  }
                  else if (mx>mn){
                        e = mid-1;
                  }
                  else b = mid+1;
            }

            /*show(i);
            show(upperBound);
            show(lowerBound);
            */
            ans += (upperBound-lowerBound+1);
      }

      cout << ans << endl;


      return 0;
}
