#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n,l,r;
            cin >> n >> l >> r;

            ll start = l , total = r-l+1 , mark = 0;
            vector < ll > ans;

            for (ll i=1 ; i<n ; i++){
                  for (ll j=i+1 ; j<=n ; j++){
                        if (!mark){
                              for (ll x = n-1  , y = 1; x>=1 ; x-- , y++){

                                    if (x*2<start){
                                          start-=x*2;
                                    }
                                    else {

                                          //show(start);

                                          if (start - x*2==0){

                                                i = y+1;
                                                j = y+2;

                                                ans.push_back(n);
                                                start = 0;
                                          }
                                          else {

                                                ll temp = start/2;
                                                if (start%2==0){

                                                      ans.push_back(y+temp);
                                                      i = y;
                                                      j = y+temp+1;
                                                }
                                                else {

                                                      i = y;
                                                      j = y+temp+1;
                                                }
                                                start = 0;
                                          }

                                          break;
                                    }
                              }

                              if (start){
                                    ans.push_back(1);
                                    start = 0;
                                    i = n+1;
                                    j = n+1;
                              }
                              mark = 1;
                        }

                        if (ans.size()==total)break;
                        if (i==n){
                              ans.push_back(1);
                        }

                        if (ans.size()==total)break;
                        ans.push_back(i);

                        if (ans.size()==total)break;

                        ans.push_back(j);
                        if (ans.size()==total)break;
                  }

                  if (ans.size()==total)break;
            }

            if (ans.size()<total)ans.push_back(1);

            for (int i = 0 ; i<ans.size() ; i++)cout << ans[i] << " ";
            cout << endl;
      }
}
