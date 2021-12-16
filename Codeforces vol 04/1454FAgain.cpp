///find max value in a range. build O(n long n) , query O(1)///
#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define scl(w)          scanf("%I64d",&w)

using namespace std;

ll SP[maxn][25] , PrePower[maxn] , A[maxn] , N , BIT , pw[30];

void buildPrePower()
{
      pw[0] = 1;
      for (int i=1 ; i<26 ; i++){
            pw[i] = pw[i-1]*2;
      }
      ll temp = 1;

      for (int i=0 ; i<=19 ; i++){
            if (temp<maxn)PrePower[temp] = i;
            temp *=2;
      }
      for (int i=3 ; i<maxn ; i++){
            if (PrePower[i]==0)PrePower[i] = PrePower[i-1];
      }
}

void BuildSpTable()
{

      {
            BIT = PrePower[N]+1;
      }

      {///initialize SP
            for (int j= 0 ; j<=BIT ; j++){
                  for (int i=0 ; i<=N ; i++)SP[i][j] = -1;
            }
      }

      for (int i=1; i<=N ; i++)SP[i][0] = A[i];

      for (int j = 1 ; j<=BIT ; j++){
            for (int i=1 ; i<=N ; i++){

                  SP[i][j] = min(SP[i][j-1],SP[max(0LL,i-(pw[j-1]))][j-1]);
            }
      }
      return;
}

ll QuarySP(ll l, ll r)
{
      ll id1 = r, findbit = PrePower[(r-l+1)] ;
      ll id2 = l + (1<<findbit)-1;

      return min(SP[id1][findbit],SP[id2][findbit]);
}

int main()
{
      buildPrePower();
      ll tc;
      scl(tc);
      while(tc--){
            scl(N);
            for (int i=1 ; i<=N; i++)scl(A[i]);

            BuildSpTable();

            ll R[N+5] , L[N+5];

            for (int i=1 ; i<=N ; i++){
                  R[i] = L[i] = A[i];
                  if (i>1)L[i] = max(A[i],L[i-1]);
            }
            for (int i=N-1 ; i>=1 ; i--)R[i] = max(R[i+1],A[i]);

            bool sol = false;
            ll ansX , ansY , ansZ , beg = 1 , ed = N;

            while(beg+1<ed){
//                        show(beg);
//                        show(ed);
                  if (L[beg]<R[ed])beg++;
                  else if (L[beg]>R[ed])ed--;
                  else {
                        ll mid = QuarySP(beg+1,ed-1);
                        if (mid==L[beg]){
                              sol = true;
                              ansX = beg;
                              ansY = ed-beg-1;
                              ansZ = N - ansX - ansY;
                              break;
                        }

                        if (L[beg]>A[beg+1])beg++;
                        else ed--;
                  }
            }

            if (sol){
                  printf("YES\n");
                  printf("%lld %lld %lld\n",ansX,ansY,ansZ);
            }
            else printf("NO\n");
      }

      return 0;
}
