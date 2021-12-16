#include<bits/stdc++.h>

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc; _t++){
            int seive[105];
            memset(seive,0,sizeof seive);

            vector<pair<int,int> > ans;
            int n;
            scanf("%d",&n);

            for (int i=2 ; i<=n ; i++){
                  if (seive[i]==0){
                        for (int j = i*i ; j<=n ; j+=i)seive[j] = 1;
                        int cnt = 0 , x = i;
                        while(n/x>0){
                              cnt += (n/x);
                              x*=i;
                        }
                        ans.push_back({i,cnt});
                  }
            }
            printf("Case %d: %d = ",_t,n);
            for (int i=0; i<ans.size() ; i++){
                  if(i>0)printf(" * ");
                  printf("%d (%d)",ans[i].first,ans[i].second);
            }
            printf("\n");
      }

      return 0;
}
