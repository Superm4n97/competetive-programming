#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200009
#define mod 1000000021
#define base 137

using namespace std;

//string s;
char s[maxn];
ll st[4*maxn], rt[maxn*4], P[maxn] , n;

ll amod(ll a, ll b)
{
      return a - a/b*b;
}

void build(ll node, ll b, ll e)
{
      if (b==e){
            st[node] = s[b];
            rt[node] = s[b];
            return;
      }
      ll mid = (b+e)/2, L = node*2, R = node*2+1;
      build(L,b,mid);
      build(R,mid+1,e);

      st[node] = amod(amod(st[L]*P[e-mid],mod)+st[R],mod);
      rt[node] = amod(amod(rt[R]*P[mid-b+1],mod)+rt[L],mod);
      return;
}

void update(ll node, ll b, ll e, ll idx, char ch)
{
      if (b>idx || e<idx)return;
      if (idx==b && idx==e){
            s[b] = ch;
            st[node] = ch;
            rt[node] = ch;
            return;
      }

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      update(L,b,mid,idx,ch);
      update(R,mid+1,e,idx,ch);

      st[node] = amod(amod(st[L]*P[e-mid],mod)+st[R],mod);
      rt[node] = amod(amod(rt[R]*P[mid-b+1],mod)+rt[L],mod);
      return;
}

ll quary(ll node, ll b, ll e, ll x, ll y, ll type)
{
      if (b>y || e<x)return 0;
      if (b>=x && e<=y){
            if (type==1)return st[node];
            else return rt[node];
      }

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      ll t1 = quary(L,b,mid,x,y,type) , t2 = quary(R,mid+1,e,x,y,type);
      if (type==1){
            ll xp = min(e,y)-mid;
            if (y<=mid)xp = 0;
            return amod(amod(t1*P[xp],mod)+t2,mod);
      }
      else{
            ll xp = mid-max(b,x)+1;
            if (x>mid)xp = 0;
            return amod(amod(t2*P[xp],mod)+t1,mod);
      }
}

ll solve(ll l, ll r, ll x, ll y)
{
//      cout << "solve : ";
//      cout << l << " " << r << " " << x << " " << y << endl;
      ll b = 1 , e = (r-l+1) , len = 0;
      while(b<=e){
            ll mid = (b+e)/2;
            ll t1 = quary(1,0,n-1,l,l+mid-1,1),t2 = quary(1,0,n-1,y-mid+1,y,2);
            if (t1==t2){
                  b = mid+1;
                  len = max(len,mid);
            }
            else e = mid-1;
      }

      if (l+len>r)return x;
      ll rem = r-l+1 - len;

      if (quary(1,0,n-1,r-rem+1,r,1)==quary(1,0,n-1,x,x+rem-1,2))return x+rem;
      return n+5;
}

ll range(ll l, ll r)
{
      if (l+1>=r){
            if (s[l]==s[r])return 0;
            else return l+1;
      }
      ll ret, mid = (l+r)/2;
      if (amod(r-l+1,2)==0){//even
            if (quary(1,0,n-1,l,mid,1)==quary(1,0,n-1,mid+1,r,2))return 0;
            ll t2 = solve(mid+2,r,l,mid);
            if(t2<n)return t2+1;
            ll t1 = solve(l,mid-1,mid+1,r);
            if(t1<n)return t1+1;
            return -1;
      }
      else{//odd
            if (quary(1,0,n-1,l,mid-1,1)==quary(1,0,n-1,mid+1,r,2))return 0;
            ll t2 = solve(mid+1,r,l,mid);
            if (t2<n)return t2+1;
            ll t1 = solve(l,mid-1,mid,r);
            if (t1<n)return t1+1;
            return -1;
      }
}

int main()
{
      P[0] = 1;
      for (int i=1 ; i<maxn ; i++)P[i] = amod(P[i-1]*base,mod);

      int tc;
      scanf("%d",&tc);

      for (int _t=1 ; _t<=tc ; _t++){            scanf("%s",s);
            n = strlen(s);
            build(1,0,n-1);

            int q;
            scanf("%d",&q);

            printf("Case %d:\n",_t);
            while(q--){
                  int l,r,type;
                  scanf("%d",&type);

                  if (type==1){
                        scanf("%d %d",&l,&r);
                        printf("%d\n",range(l-1,r-1));
                  }
                  else {
                        int id;
                        char ch;
                        scanf("%d %c",&id, &ch);
                        update(1,0,n-1,id-1,ch);
                  }
            }
      }
}
/*
1
abca
5
1 1 4
1 2 4
2 4 w
1 1 4
1 3 3

1
abca
2
2 4 w
1 1 4

1
abca
1
2 4 w

3
abccbxa
7
1 1 7
1 2 6
1 3 5
1 3 4
1 1 4
2 6 b
1 1 7
abbccba
1
1 1 7
abcxba
1
1 1 6

1
baaaaaaaaa
1
1 1 10

*/
