#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 10000007

using namespace std;

int D[maxn] , n , k;

int main()
{
      for (ll i=2 ; i<maxn ; i++){
            if (D[i]==0){
                  D[i] = i;
                  for (ll j = i*i ; j<maxn ; j+=i){
                        if (D[j]==0)D[j] = i;
                  }
            }
      }

      int tc;
      scanf("%d",&tc);

      while(tc--){
            scanf("%d %d",&n,&k);

            vector<pair<int,int> > segments;
            map<int,int> pre;

            for (int i=1 ; i<=n ; i++){
                  int a;
                  scanf("%d",&a);
                  int x = 1;
                  while(a>1){
                        int temp = D[a] , cnt = 0;
                        while(D[a]==temp){
                              cnt++;
                              a = a/temp;
                        }
                        if (cnt&1){
                              x *= temp;
                        }
                  }

                  if (pre[x] == 0)pre[x] = i;
                  else {
                        segments.push_back({pre[x],i});
                        pre[x] = i;
                  }
            }
            sort(segments.begin(),segments.end());

            int ans = 1, px = -1;
            for (int i=0 ; i<segments.size() ; i++){
//                  cout << segments[i].first << " " << segments[i].second << endl;
                  if (segments[i].first>=px){
                        px = segments[i].second;
                        ans++;
                  }
                  else px = min(segments[i].second,px);
            }
            printf("%d\n",ans);
      }


      return 0;
}
