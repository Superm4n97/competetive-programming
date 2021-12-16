#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005
#define base 137
#define mod 1000000021

using namespace std;

ll n, H[maxn], R[maxn] , P[maxn];

ll amodb(ll a, ll b)
{
      ll temp = a/b;
      return a-b*temp;
}
void createHash(string s)
{
      H[0] = s[0];
      for (int i=1; i<n; i++)H[i] = amodb(H[i-1]*base+s[i],mod);
}
void createReverseHash(string s)
{
      R[n-1] = s[n-1];
      for (int i=n-2 ; i>=0 ; i--)R[i] = amodb(R[i+1]*base+s[i],mod);
}
ll forSH(ll l, ll r)
{
      if (l==0)return H[r];
      ll temp = amodb(H[l-1]*P[r-l+1],mod);
      temp = amodb(H[r]-temp+mod,mod);
      return temp;
}
ll revSH(ll l, ll r)
{
      if (r==n-1)return R[l];
      ll temp = amodb(R[r+1]*P[r-l+1],mod);
      temp = amodb(R[l]-temp+mod,mod);
      return temp;
}
bool quary(ll l, ll r)
{
      ll m = (l+r)/2;
      ll x = m , y = m+1;
      if ((r-l+1)%2)x--;
      if (forSH(l,x)==revSH(y,r))return true;
      return false;
}

int main()
{
      P[0] = 1;
      for (int i=1 ; i<maxn ; i++)P[i] = amodb(P[i-1]*base,mod);
      cin >> n;
      string s;
      cin >> s;

      createHash(s);
      createReverseHash(s);

      ll b = 2, e = n , ans = 1;
      //even
      while(b<=e){
            ll mid = (b+e)/2;
            if (mid%2)mid--;
            bool sol = false;

            for (int i=mid-1 ; i<n ; i++){
                  if (quary(i-mid+1,i)){
                        sol = true;
                  }
            }
            if (sol){
                  ans = max(ans,mid);
                  b = mid+2;
            }
            else e = mid-2;
      }
      b = 3 , e = n;
      //odd
      while(b<=e){
            ll mid = (b+e)/2;
            if (mid%2==0)mid--;
            bool sol = false;
            for (int i=mid-1 ; i<n ; i++){
                  if (quary(i-mid+1,i))sol = true;
            }
            if (sol){
                  ans = max(ans,mid);
                  b = mid+2;
            }
            else e = mid-2;
      }

      cout << ans << endl;

      return 0;
}
