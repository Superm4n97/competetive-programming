#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005

using namespace std;

ll n,q, A[maxn] , peek[maxn] , ans;

ll checkPeek(ll i)
{
      if (i==0 || i>n)return 0;
      if (A[i]>A[i-1] && A[i]>A[i+1])return 1;
      if (A[i]<A[i-1] && A[i]<A[i+1])return -1;

      return 0;
}

void Dis1(ll a, ll b)
{
      ll temp = A[a]*peek[a]+A[b]*peek[b];
      temp += A[a-1]*peek[a-1] + A[b+1]*peek[b+1];
      ans+=temp*-1;

      swap(A[a],A[b]);

      {//changing a
            peek[a-1] = checkPeek(a-1);
            peek[a] = checkPeek(a);
            peek[b] = checkPeek(b);
            peek[b+1] = checkPeek(b+1);
      }

      temp = A[a]*peek[a]+A[b]*peek[b];
      temp += A[a-1]*peek[a-1] + A[b+1]*peek[b+1];
      ans+=temp;
}

void Dis2(ll a, ll b)
{
      ll temp = A[a]*peek[a]+A[b]*peek[b];
      temp += A[a-1]*peek[a-1] + A[a+1]*peek[a+1] + A[b+1]*peek[b+1];
      ans+=temp*-1;

      swap(A[a],A[b]);

      {//changing a
            peek[a-1] = checkPeek(a-1);
            peek[a] = checkPeek(a);

            peek[a+1] = checkPeek(a+1);

            peek[b] = checkPeek(b);
            peek[b+1] = checkPeek(b+1);
      }

      temp = A[a]*peek[a]+A[b]*peek[b];
      temp += A[a-1]*peek[a-1] + A[a+1]*peek[a+1] + A[b+1]*peek[b+1];
      ans+=temp;
}

void Dis3(ll a, ll b)
{
      ll temp = A[a]*peek[a] + A[b]*peek[b];
      temp += A[a-1]*peek[a-1]+A[a+1]*peek[a+1] + A[b-1]*peek[b-1]+A[b+1]*peek[b+1];
      ans+=temp*-1;

      swap(A[a],A[b]);

      {//changing a
            peek[a-1] = checkPeek(a-1);
            peek[a] = checkPeek(a);
            peek[a+1] = checkPeek(a+1);

            peek[b-1] = checkPeek(b-1);
            peek[b] = checkPeek(b);
            peek[b+1] = checkPeek(b+1);
      }

      temp = A[a]*peek[a]+A[b]*peek[b];
      temp += A[a-1]*peek[a-1]+A[a+1]*peek[a+1] + A[b-1]*peek[b-1]+A[b+1]*peek[b+1];
      ans+=temp;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ans = 0;
            //cin >> n >> q;
            scanf("%I64d %I64d",&n,&q);
            for (int i=0 ; i<=n+3 ; i++)peek[i] = A[i] = 0;
            for (int i=1 ; i<=n ; i++)scanf("%I64d",&A[i]);//cin >> A[i];

            for (int i=1 ; i<=n ; i++){
                  peek[i] = checkPeek(i);
            }

            for (int i=1 ; i<=n ; i++)ans += A[i]*peek[i];

            printf("%I64d\n",ans);

            while(q--){

                  ll a,b;
                  //cin >> a >> b;
                  scanf("%I64d %I64d",&a,&b);


                  if (b-a==1)Dis1(a,b);
                  if (b-a==2)Dis2(a,b);
                  if (b-a>2)Dis3(a,b);

                  //cout << ans << endl;
                  printf("%I64d\n",ans);
            }
      }

      return 0;
}
/**
3 2 4 5

1
3 1
1 3 2
1 2
**/
