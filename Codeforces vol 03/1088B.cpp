#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,k;
vector < ll > v;

int main()
{
      cin >> n >> k;
      for (int i=0;i<n; i++){
            ll a;
            cin >> a ;

            v.push_back(a);
      }

      sort(v.begin(),v.end());
      queue < ll > q;
      ll temp = 0 , cnt = 0;

      for (int i=0 ; i<n;i++)q.push(v[i]);

      while(k--){
            ll mn = q.front();
            q.pop();
            mn = max(0LL,mn-temp);
            temp+=mn;
            if (mn==0){
                  if (cnt>=n){
                        cout << 0 << endl;
                        q.push(0);
                  }
                  else {
                        q.push(0LL);
                        cnt++;
                        k++;
                  }
            }
            else {
                  cout << mn << endl;
                  q.push(0);
                  cnt++;
            }
      }

      return 0;
}
