#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

vector < pair < ll , ll > > A,_A,B,_B,revB;
vector < pair < pair < ll, ll> , ll > > M;
ll n,m ,p , S[4*maxn] , ans = -100000000000000017;

void update(ll node, ll b , ll e , ll id , ll val)
{
      if (b>id || e<id ) return;
      if (b==e){
            S[node] += val;
            return;
      }

      ll mid = (b+e)/2;

      update(node*2,b,mid,id,val);
      update(node*2+1,mid+1,e,id,val);

      S[node] = S[node*2]+S[node*2+1];

      return;
}

ll query(ll node, ll b, ll e, ll lim)
{
      if (e<=lim)return S[node];
      if (b>lim)return 0LL;

      ll mid = (b+e)/2;

      return query(node*2,b,mid,lim)+query(node*2+1,mid+1,e,lim);
}

int main()
{
      cin >> n >> m >> p;
      for (int i=0 ; i<n;i++){

            ll a,b;
            cin >> a >> b;

            _A.push_back({a,b});
      }

      sort(_A.begin() , _A.end());
      A.push_back(_A[n-1]);

      for (int i=n-2 ; i>=0 ;i--){
            if (_A[i].second>=_A[i+1].second){

                  _A[i].second = _A[i+1].second;
            }
            else {

                  A.push_back(_A[i]);
            }
      }

      n = A.size();
      reverse(A.begin() , A.end());

      for (int i=0 ; i<m; i++){

            ll a,b;
            cin >> a >> b;

            _B.push_back({a,b});
      }

      sort(_B.begin(),_B.end());
      B.push_back(_B[m-1]);

      for (int i=m-2 ; i>=0 ; i--){

            if (_B[i].second>=_B[i+1].second){

                  _B[i].second = _B[i+1].second;
            }
            else {

                  B.push_back(_B[i]);
            }
      }

      m = B.size();
      reverse(B.begin() , B.end());

      ans = (A[0].second+B[0].second) * -1;

      for (int i=0 ; i<p ; i++){

            ll x,y,z;
            cin >> x >> y >> z;
            M.push_back({{x,y},z});
      }

      sort(M.begin() , M.end());

      for (int i=0 ; i< p ; i++){

            ll x = M[i].first.first , y = M[i].first.second , z = M[i].second;
            if (x>=A[n-1].first || y>=B[m-1].first)continue;

            ll b = 0 , e = n-1 , costA = n , costB = m;
            while(b<=e){

                  ll mid = (b+e)/2;
                  if (A[mid].first > x){

                        costA = min(costA,mid);
                        e = mid-1;
                  }
                  else b = mid+1;
            }

            ll t1 = A[costA].first;
            costA = A[costA].second;

            b = 0 , e = m-1;
            while(b<=e){

                  ll mid = (b+e)/2;
                  if (B[mid].first > y){

                        costB = min(costB,mid);
                        e = mid-1;
                  }
                  else b = mid+1;
            }

            ll t2 = B[costB].first;
            costB = B[costB].second;

            /*
            cout << "  x : " << x << "  y : " << y << "  z : " << z << endl;
            show(costA);
            show(t2);
            show(costB);
            */

            update(1,1,maxn-4,t2,z);
            ll gain = query(1,1,maxn-4,t2) , waste = costA+costB;

            ans = max(ans,gain-waste);
      }

      cout << ans << endl;


      return 0;
}
