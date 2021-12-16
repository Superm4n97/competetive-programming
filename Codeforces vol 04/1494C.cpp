#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

ll n,m, ans = 0;
vector<ll>va,vb,match;

ll BS_va(ll val)
{
      ll ret = -1,b = 0, e = (ll)va.size()-1;
      while(b<=e){
            ll mid = (b+e)/2;
            if (va[mid]<=val){
                  b = mid+1;
                  ret = max(ret,mid);
            }
            else e = mid-1;
      }
      return ret+1;
}

ll BS_vb(ll val)
{
      ll ret = -1,b = 0, e = (ll)vb.size()-1;
      while(b<=e){
            ll mid = (b+e)/2;
            if (vb[mid]<=val){
                  b = mid+1;
                  ret = max(ret,mid);
            }
            else e = mid-1;
      }
      return ret+1;
}

ll BS_match(ll val)
{
      ll ret = -1,b = 0, e = (ll)match.size()-1;
      while(b<=e){
            ll mid = (b+e)/2;
            if (match[mid]<=val){
                  b = mid+1;
                  ret = max(ret,mid);
            }
            else e = mid-1;
      }
      return ret+1;
}

void sol()
{
      ll ret = 0;
      for (int i=0 ; i<vb.size() ; i++){
            ll have = BS_va(vb[i]) ;
            ll pos = BS_vb(vb[i]) - BS_vb(vb[i]-have);
            ret = max(ret,pos+(match.size()-BS_match(vb[i])));
      }
      ans+=ret;
}

int main()
{
      ll tc;scl(tc);

      while(tc--){
            scl(n) , scl(m);

            ll A[n+5] , B[m+5];
            ans  = 0;

            for (int i=0 ; i<n ; i++)scl(A[i]);
            for (int i=0 ; i<m ; i++)scl(B[i]);

            va.clear();
            vb.clear();
            match.clear();

            for (int i=0 ; i<n ; i++){
                  if (A[i]>0)va.push_back(A[i]);
            }
            for (int i=0 ; i<m ; i++){
                  if (B[i]>0){
                        vb.push_back(B[i]);
                        ll x = BS_va(B[i]);
                        x--;
                        if (x>=0 && x<va.size() && va[x]==B[i])match.push_back(B[i]);
                  }
            }

            sol();

            va.clear();
            vb.clear();
            match.clear();

            for (int i=n-1; i>=0 ; i--){
                  if (A[i]<0)va.push_back(-A[i]);
            }
            for (int i=m-1; i>=0 ; i--){
                  if (B[i]<0){
                        vb.push_back(-B[i]);
                        ll x = BS_va(-B[i]);
                        x--;
                        if (x>=0 && x<va.size() && va[x]==-B[i])match.push_back(-B[i]);
                  }
            }
            sol();

            printf("%I64d\n",ans);
      }


      return 0;
}
