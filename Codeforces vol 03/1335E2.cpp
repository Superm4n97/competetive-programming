#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " <<x << endl

using namespace std;

int tc , n;

int main()
{
      scanf("%d",&tc);

      while(tc--){

            int n;
            vector < int > G[205];

            scanf("%d",&n);

            for (int i=1 ; i<=n;i++){

                  int a;
                  scanf("%d",&a);

                  G[a].push_back(i);
            }

            int ans = 0;

            for (int i=1 ; i<=200 ; i++){

                  if (G[i].empty())continue;

                  int x = 0 , y = G[i].size()-1;

                  while(x<=y){

                        int aa = (x+1)*2;
                        if (x==y){

                              aa--;
                              //ans = max(ans,aa);
                              if (aa>ans)ans = aa;
                              x++ , y--;

                              continue;
                        }

                        //ans = max(ans,aa);
                        if (aa>ans)ans = aa;

                        int L = G[i][x] , R = G[i][y];

                        for (int j = 1 ; j<=200 ; j++){

                              int bb = 0;

                              if (G[j].empty() || i==j){
                                    continue;
                              }
                              else {

                                    int b = 0 , e = G[j].size()-1 , start = -1 , endd = -1;

                                    if (G[j][0]>R || G[j][e]<L)continue;

                                    while(b<=e){

                                          int mid = (b+e)/2;
                                          if (G[j][mid]<L){

                                                //start = max(start,mid);
                                                if (mid>start)start = mid;
                                                b = mid+1;
                                          }
                                          else e = mid-1;
                                    }

                                    b = 0 , e = G[j].size()-1;

                                    while(b<=e){

                                          int mid = (b+e)/2;
                                          if (G[j][mid]<=R){

                                                //endd = max(endd,mid);
                                                if (mid>endd)endd = mid;
                                                b = mid+1;
                                          }
                                          else e = mid-1;
                                    }

                                    if (endd==-1)bb = 0;
                                    else if (start==-1){
                                          bb = endd+1;
                                    }
                                    else {
                                          bb = endd-start;
                                    }

                                    //ans = max(ans,aa+bb);
                                    if (aa+bb>ans)ans = aa+bb;
                              }
                        }

                        x++ , y--;
                  }
            }
            printf("%d\n",ans);
      }

      return 0;
}
