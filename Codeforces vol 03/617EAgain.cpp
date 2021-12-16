#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 600005

using namespace std;

struct node
{
      ll l,r,id;
}qry[maxn];
ll n,m,k , A[maxn] , bucket , ans[maxn],global[maxn] , globalLarge[maxn];

bool comp(node a, node b)
{
      if ((a.l-1)/bucket != (b.l-1)/bucket)return a.l/bucket < b.l/bucket;
      return a.r<b.r;
}

int main()
{
      scanf("%I64d %I64d %I64d",&n,&m,&k);
      for (int i=1 ; i<=n ; i++)scanf("%I64d",&A[i]);

      bucket = sqrt(n);

      for (int i = 0 ; i<m ; i++){
            scanf("%I64d %I64d",&qry[i].l,&qry[i].r);
            qry[i].id = i;
      }

      sort(qry,qry+m,comp);

//      for (int i=0 ; i<m ; i++)
//            cout<<qry[i].l<<" "<<qry[i].r<<" "<<qry[i].id<< endl;
//      show(bucket);

      ll smallBuck[bucket+5],largeBuck[n+5] , R = 0, preBucket = -1 , cnt = 0;
      for (int i=0 ; i<m ; i++){
            if (preBucket != (qry[i].l+bucket-1)/bucket){
                  cnt = 0;
                  preBucket = (qry[i].l+bucket-1)/bucket;
                  memset(largeBuck,0,sizeof largeBuck);
                  memset(globalLarge,0,sizeof globalLarge);
                  globalLarge[0]++;
                  R = preBucket*bucket;
            }

            memset(smallBuck,0,sizeof smallBuck);

            if ((qry[i].l-1)/bucket == (qry[i].r-1)/bucket){
                  ll tempCount = 0;

                  global[0]++;
                  for (int j=qry[i].l , index = 1; j<=qry[i].r ; j++,index++){
                        smallBuck[index] = smallBuck[index-1]^A[j];
                        tempCount += global[k^smallBuck[index]];
                        global[smallBuck[index]]++;
//                        if (A[j]==0 && k==0)tempCount--;
                  }
                  global[0]--;
                  for (int j=qry[i].l ,index = 1;j<=qry[i].r ; j++,index++)
                        global[smallBuck[index]]--;
                  ans[qry[i].id] = tempCount;
            }
            else {
                  while(R<qry[i].r){
                        R++;
                        largeBuck[R] = largeBuck[R-1]^A[R];
                        cnt += globalLarge[k^largeBuck[R]];
                        globalLarge[largeBuck[R]]++;
//                        if (A[R]==0 && k==0)cnt--;
                  }

                  ll tempCnt = cnt;

                  for (int j = preBucket*bucket,index = bucket ; j>=qry[i].l ; j--,index--){
                        smallBuck[index] = smallBuck[index+1]^A[j];

                        tempCnt += global[smallBuck[index]^k];
                        tempCnt += globalLarge[smallBuck[index]^k];
                        global[smallBuck[index]]++;
//                        if (A[j]==0 && k==0)tempCnt--;
                  }
                  for (int j = preBucket*bucket,index = bucket ; j>=qry[i].l ; index--,j--){
                        global[smallBuck[index]]--;
                  }

                  ans[qry[i].id] = tempCnt;
            }
      }
      for (int i=0 ; i<m ; i++)printf("%I64d\n",ans[i]);


      return 0;
}
/**
5 2 0
0 0 0 0 0
1 2
1 1
4 5
1 3
1 5
3 5
2 5
**/
