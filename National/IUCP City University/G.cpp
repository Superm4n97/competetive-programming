#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

ll n;
vector<pair<ll,ll> > vp;
pair<ll,ll> pk;
double PRE[205], zeros[205][3] , ans;
bool sol = false;


double dis(ll i, ll j)
{
      double x1=(double)vp[i].first,y1=(double)vp[i].second;
      double x2=(double)vp[j].first,y2=(double)vp[j].second;

      double ret = sqrt((x1-x2)*(x1-x2)*1.0 + (y1-y2)*(y1-y2)*1.0);
      return ret;
}

double Distance(ll i, ll j, ll k)
{
      return dis(i,j)+dis(j,k)+dis(k,i);
}

ll side(pair<ll,ll> A, pair<ll,ll> B, pair<ll,ll> C)
{
      ll temp = A.first*B.second + B.first*C.second + C.first*A.second;
      temp -= (B.first*A.second + C.first*B.second + A.first*C.second);
      if (temp==0)return 0;
      if (temp<0)return -1;
      return 1;
}

void Handle(ll i, ll j, ll k)
{
      double d = Distance(i,j,k)-dis(i,j);
      ll id = side(vp[i],vp[j],vp[k]);
      if (id<0)id = 0;

      if (zeros[i][id]<0)zeros[i][id] = d;
      else {
            zeros[i][id] = min(zeros[i][id],d);
      }
            ll x = 1-id;
            if (zeros[i][x]>0){
                  ans = min(ans,zeros[i][x]+zeros[i][id]);
                  sol = true;
            }
}

bool inside(ll i, ll j, ll k)
{
      ll p1 = side(vp[i],vp[j],pk) , p2 = side(vp[j],vp[k],pk) , p3 = side(vp[k],vp[i],pk);
      if (p1==0 || p2==0 || p3==0){
            if(p1==0){
                  Handle(i,j,k);
            }
            else if (p2==0){
                  Handle(j,k,i);
            }
            else {
                  Handle(i,k,j);
            }
            return false;
      }
      if (p1==p2 && p1==p3)return true;
      return false;
}

int main()
{
      ll tc;
      scl(tc);

      for (int _t=1 ; _t<=tc ; _t++){

            ll aa,bb;
            scl(aa);
            scl(bb);
            pk.first = aa;
            pk.second = bb;

            scl(n);

            ans = 100000000000016.0;
            sol = false;
            for (int i=0 ; i<n+4 ; i++){
                  PRE[i] = -1;
                  zeros[i][0] = zeros[i][1] = -1;
            }

            for (int i=0 ; i<n ; i++){
                  ll a, b;
                  scl(a),scl(b);
                  vp.push_back({a,b});
            }


            for (int i=0 ; i<n ; i++){
                  for (int j=i+1 ; j<n ; j++){
                        for (int k = j+1 ; k<n ; k++){
                              if (inside(i,j,k)){
                                    sol = true;
                                    ans = min(ans,Distance(i,j,k));
                              }
                        }
                  }
            }

            if (!sol)printf("Case %d: -1\n",_t);
            else printf("Case %d: %.6f\n",_t,ans);

            vp.clear();
      }

      return 0;
}
