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

                  SP[i][j] = min(SP[i][j-1],SP[max(0LL,i-pw[j-1])][j-1]);
            }
      }
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
            A[0] = A[N+1] = L[0] = R[N+1] = 0;

            for (int i=1 ; i<=N ; i++){
                  R[i] = L[i] = A[i];
                  if (i>1)L[i] = max(A[i],L[i-1]);
            }
            for (int i=N-1 ; i>=1 ; i--)R[i] = max(R[i+1],A[i]);

            bool sol = false;
            ll ansX , ansY , ansZ;

            for (int i=2 ; i<=N-1 ; i++){

                  ll x = 1 , y = i-1 , l = i , r = i;
                  while(x<=y){

                        ll mid = (x+y)/2;
                        if (QuarySP(mid,i-1)>=A[i]){
                              y = mid-1;
                              l = min(l,mid);
                        }
                        else x = mid+1;
                  }

                  x = i+1 , y = N;
                  while(x<=y){

                        ll mid = (x+y)/2;
                        if (QuarySP(i+1,mid)>=A[i]){
                              x = mid+1;
                              r = max(mid,r);
                        }
                        else y = mid-1;
                  }

                  if (L[l-1] < A[i] && A[l]==A[i]){
                        l++;
                  }
                  if (R[r+1] < A[i] && A[r]==A[i]){
                        r--;
                  }

                  if (l==1 || r==N || r<l)continue;

                  ll mdl = QuarySP(l,r);

                  if (L[l-1]==A[i] && R[r+1]==A[i] && mdl == A[i]){
                        sol = true;
                        ansX = l-1;
                        ansY = r-l+1;
                        ansZ = N-r;
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
