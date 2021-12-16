#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,m , A[200][200] , ans;

ll opposit(ll a, ll x)
{
      return x+1-a;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            cin >> n >> m;
            for (int i=1 ; i<=n ; i++){
                  for (int j=1 ; j<=m ; j++)cin >> A[i][j];
            }

            ans = 0;

            for (ll i=1 ; i<=n ; i++){
                  for (ll j=1 ; j<=m ; j++){

                        ll x = n+1-i , y = m+1-j;

                        if (x>i || y>j)continue;

                        //ll sum = A[i][j]+A[x][j]+A[i][y]+A[x][y];

                        vector < ll > v;
                        v.push_back(A[i][j]);
                        v.push_back(A[i][y]);
                        v.push_back(A[x][j]);
                        v.push_back(A[x][y]);

                        sort(v.begin(),v.end());

                        if (v[0]!=v[1]){
                              v[0] = v[1];
                        }
                        if (v[3]!=v[2])v[3] = v[2];

                        ll mid = ((v[2]+v[3])/2);

                        ans+=abs(A[i][j]-mid);
                        A[i][j] = mid;

                        ans+=abs(A[x][j]-mid);
                        A[x][j] = mid;

                        ans+=abs(A[i][y]-mid);
                        A[i][y] = mid;

                        ans+=abs(A[x][y]-mid);
                        A[x][y] = mid;
/*
                        show(i);
                        show(j);
                        show(x);
                        show(y);
                        show(ans);
                        show(sum);
                        show(mid);
                        for (int p = 1;p<=n ; p++){
                              for (int q = 1 ; q<=m ; q++)cout << A[p][q] << " ";
                              cout << endl;
                        }
                        cout << endl;
  */
                  }
            }
           /* cout << endl;
            for (int i=1 ; i<=n ; i++){
                  for (int j=1 ; j<=m ; j++)cout << A[i][j] << " ";
                  cout << endl;
            }
            */

            cout << ans << endl;
      }

      return 0;
}
