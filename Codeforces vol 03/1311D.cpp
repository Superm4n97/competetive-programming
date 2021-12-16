#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 20004

using namespace std;

vector<int>D[maxn];

void init()
{
      int mx = 0;
      for (int i=1 ; i<maxn ; i++)D[i].push_back(1);
      for (int i=2 ; i<maxn ; i++){
            for (int j = i ; j<maxn ; j+=i)D[j].push_back(i);
            mx = max(mx,(int)D[i].size());
      }
//      show(mx);
}

int fndA(int b, int a)
{
      int dif = maxn+maxn , ret;
      for (int i=0 ; i<D[b].size() ; i++){
            if (abs(a-D[b][i])<dif){
                  dif = abs(a-D[b][i]);
                  ret = D[b][i];
            }
      }
      return ret;
}

int fndB(int b, int c)
{
      int c1 = c/b*b , c2 = (c/b+1)*b;
      if (c-c1<c2-c)return c1;
      return c2;
}

int main()
{
      init();
      int tc;
      scanf("%d",&tc);

      while(tc--){
            int a,b,c , ans = maxn*maxn , A,B,C;
            scanf("%d %d %d",&a,&b,&c);
            for(int y=1 ; y<maxn ; y++){
                  int x = fndA(y,a) , z = fndB(y,c);
                  int mv = abs(x-a)+abs(z-c)+abs(b-y);
                  if (mv<ans){
                        ans = mv;
                        A = x, B = y, C = z;
                  }
            }
            printf("%d\n",ans);
            printf("%d %d %d\n",A,B,C);
      }

      return 0;
}
/*
1
63 10000 10000

10
61 10004 10004
*/
