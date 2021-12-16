#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      scanf("%I64d",&tc);

      while(tc--){

            ll n , ans = 0 ,x;
            cin >> n >> x;
            vector<ll> v , p;

            for (int i = 0; i <n ; i++){
                  ll a;
                  cin >> a;
                  v.push_back(a);
                  p.push_back(a);
            }

            sort(p.begin() , p.end());

            if (p==v){
                  cout << 0 << endl;
            }
            else {
                  ll srt[n+5];
                  memset(srt,0,sizeof srt);
                  srt[n-1] = 0;

                  for (int i=n-2 ; i>=0 ; i--){
                        if (srt[i+1]==1)srt[i] = 1;
                        else if (v[i]>v[i+1])srt[i] = 1;
                  }

                  for (int i=0 ; i<n ; i++){
                        if (v[i]>x && srt[i]==1){
                              swap(v[i],x);
                              ans++;
                        }
                  }

                  for (int i=1 ; i<n ; i++){
                        if (v[i]<v[i-1])ans = -1;
                  }

                  cout << ans << endl;
            }
      }

      return 0;
}
