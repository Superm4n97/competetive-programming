#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 20000007

using namespace std;

ll c,d,x , ans = 0 , way[maxn] , nCr[15][15];
bool amodb(ll a, ll b)
{
      ll temp = a/b;
      if (temp*b==a)return true;
      return false;
}

ll POW(ll a)
{
      return (1LL<<(a-1));
}

ll C(ll n, ll r)
{
      if (r>n)return 0;
      if (n==r || r==0)return 1;
      if (nCr[n][r] != -1)return nCr[n][r];
      return nCr[n][r] = C(n-1,r)+C(n-1,r-1);
}

ll solve_D(ll i)
{
            ll p = i;
            ll a = p , b = d+x/p , denominator = c;
//            show(p);
//            show(a);
//            show(b);
            if (amodb(a*b,denominator)){
                  ///ll q = temp/c;
                  ll g = __gcd(denominator,a);
                  a/=g,denominator/=g;
                  b/=denominator;

                  if (p==a*b)return 1;
                  if (amodb(a*b,p)){
                        g = __gcd(a,p);
                        a/=g, p/=g;
                        b/=p;
                        g = __gcd(a,b);
                        return (POW(way[a])+POW(way[b])-POW(way[g]))*2;
                  }
            }
      return 0;
}

void initialization()
{
      memset(nCr,-1,sizeof nCr);
      way[1] = 1;
      for (ll i=2 ; i<maxn ; i++){
            if (way[i]==0){
                  way[i] = 1;
                  for (ll j = i+i ; j<maxn ; j+=i)way[j]++;
            }
      }
//      for (ll i=1 ; i<maxn ; i++){
//            way[i] = (1LL<<(way[i]-1));
//      }
//      show(way[30]);
//      show(way[15]);
//      show(way[8]);
}

void problem_D()
{
      initialization();
      int tc;
      scanf("%d",&tc);

      while(tc--){
            scanf("%lld %lld %lld",&c,&d,&x);
            ans = 0;

            for (ll i=1 ; i*i<=x ; i++){
                  if (amodb(x,i)){
                        ans+=solve_D(i);
                        if (i*i!=x)
                              ans+=solve_D(x/i);
                  }
            }
            printf("%lld\n",ans);
      }
}

void problem_C()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;
            ll xMin,xCnt , yMin , yCnt , sum , ans;
            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  if (i==0)xMin = a , xCnt = n;
                  else if (i==1){
                        yMin = a;
                        yCnt = n;
                        sum = xMin*n+yMin*n;
                        ans = sum;
                  }
                  else {
                        if (i%2==0){
                              xCnt--;
                              if (a<xMin){
                                    sum-=(xCnt*xMin);
                                    sum+=(xCnt*a);
                                    xMin = a;
                              }
                              else {
                                    sum-=xMin;
                                    sum+=a;
                              }
                        }
                        else {
                              yCnt--;
                              if (a<yMin){
                                    sum-=(yCnt*yMin);
                                    sum+=(yCnt*a);
                                    yMin = a;
                              }
                              else {
                                    sum-=yMin;
                                    sum+=a;
                              }
                        }
                        ans = min(ans,sum);
                  }

            }
            cout << ans << endl;
      }
}
void problem_A()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n,k1,k2 , w = 0 , b = 0;
            cin >> n >> k1 >> k2;
            w = min(k1,k2);
            w+=(max(k1,k2)-min(k1,k2))/2;
            b = n - w;
            if ((max(k1,k2)-min(k1,k2))%2)b--;

            ll a, bb;
            cin >> a >> bb ;
            if(a<=w && bb<=b)cout << "YES" << endl;
            else cout << "NO" << endl;
      }
}
void problem_B()
{
      int tc;
      cin >> tc;
      while(tc--){
            string s;
            cin >> s;

            ll cnt = 0;

            for (int i=1 ; i<s.size()  ; i++){
                  if (cnt==0 && s[i-1]=='1' && s[i]=='1')cnt = 1;
                  if (cnt==1 && s[i-1]=='0' && s[i]=='0')cnt = 2;
            }
            if (cnt==2)cout << "NO" << endl;
            else cout << "YES" << endl;
      }
}

int main()
{
//      problem_A();
//      problem_B();
//      problem_C();
      problem_D();


      return 0;
}
/*
6
2 58 4
3 83 49
1 1 3
4 2 6
3 3 7
2 7 25
*/
