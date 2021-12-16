#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005

using namespace std;

ll A[maxn*4] , n, q;
vector<ll> mst[4*maxn], index[4*maxn];

void mergeChild(ll node, ll L ,ll R)
{
      ll x = 0 , y = 0, sL = mst[L].size() , sR = mst[R].size();
      while(x<sL || y<sR){
            if (x>=sL){
                  mst[node].push_back(mst[R][y]);
                  index[node].push_back(index[R][y]);
                  y++;
            }
            else if (y>=sR){
                  mst[node].push_back(mst[L][x]);
                  index[node].push_back(index[L][x]);
                  x++;
            }
            else {
                  if (mst[L][x]<=mst[R][y]){
                        mst[node].push_back(mst[L][x]);
                        index[node].push_back(index[L][x]);
                        x++;
                  }
                  else {
                        mst[node].push_back(mst[R][y]);
                        index[node].push_back(index[R][y]);
                        y++;
                  }
            }
      }
      return;
}

void buildTree(ll node, ll b, ll e)
{
      mst[node].clear();
      index[node].clear();

      if (b==e){
            mst[node].push_back(A[b]);
            index[node].push_back(b);
            return;
      }

      ll L = node*2, R = node*2+1 , mid = (b+e)/2;

      buildTree(L,b,mid);
      buildTree(R,mid+1,e);

      mergeChild(node,L,R);

      return;
}

ll findInNode(ll node, ll val)
{
      ll b = 0, e = mst[node].size()-1 , ret = mst[node].size();
      while(b<=e){
            ll mid = (b+e)/2;
            if (mst[node][mid]<val)b = mid+1;
            else if (mst[node][mid]>val)e = mid-1;
            else {
                  ret = min(ret,mid);
                  e = mid-1;
            }
      }
      if (ret==mst[node].size())return -1;
      return index[node][ret];
}

ll findVal(ll node, ll b, ll e, ll x, ll y, ll val)
{
      if (b>=x && e<=y)return findInNode(node, val);
      if (x>e || y<b)return -1;

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;

      ll temp = findVal(L,b,mid,x,y,val);
      if (temp!=-1)return temp;
      return findVal(R,mid+1,e,x,y,val);
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            scanf("%lld %lld",&n,&q);
            string s;
            cin >> s;

            for (int i=0 ; i<n ; i++){
                  if (i%2==1){
                        if (s[i]=='-')s[i]='+';
                        else s[i] = '-';
                  }

                  if (s[i]=='+')A[i+1] = 1;
                  else A[i+1] = -1;
                  A[i+1]+=A[i];
            }

            buildTree(1,1,n);

            while(q--){
                  ll l,r;
                  scanf("%lld %lld",&l,&r);

                  ll x = A[r] - A[l-1];
                  if (x==0)printf("0\n");
                  else if (x%2==0){
                        printf("2\n");
                        ll t1 = findVal(1,1,n,l,r,x/2+A[l-1]);
                        ll t2 = findVal(1,1,n,t1,r,x+A[l-1]);
                        printf("%lld %lld\n",t1,t2);
                  }
                  else {
                        printf("1\n");
                        if (x>0)x++;
                        else x--;

                        ll temp = A[l-1]+x/2;

                        ll t1 = findVal(1,1,n,l,r,temp);
                        printf("%lld\n",t1);
                  }
            }
      }

      return 0;
}
/*
6 17
+-+--+
1 1
1 2
1 3
1 4
1 5
1 6
2 2
2 3
2 4
2 5
2 6
4 4
4 5
4 6
5 5
5 6
6 6

1
6 1
+-+--+
6 6
*/
