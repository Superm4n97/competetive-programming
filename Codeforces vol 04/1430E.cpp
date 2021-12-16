#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll n , A[maxn];
string s , r;
queue<ll> ache[30] , lagbe[30];
vector <pair<ll,ll> > vp;

ll N , BIT[maxn];

void AddElement(ll index, ll value)
{
      while(index<=N){
            BIT[index]+=value;
            index += (index&(-index));
      }
}

ll PrefixSum(ll index)
{
      ll ret = 0;
      while(index>0){
            ret+=BIT[index];
            index-=(index&(-index));
      }
      return ret;
}

int main()
{

      cin >> n;
      cin >> s;

      r = s;
      reverse(r.begin() , r.end());

      for (ll i=0 ; i<n ; i++){

            {
                  ll b = s[i]-'a' , c = r[i]-'a';

                  if (ache[c].empty())lagbe[c].push(i);
                  else {
                        vp.push_back({ache[c].front(),i});
                        ache[c].pop();
                  }
                  if (lagbe[b].empty())ache[b].push(i);
                  else {
                        vp.push_back({i,lagbe[b].front()});
                        lagbe[b].pop();
                  }
            }
      }

      sort(vp.begin(),vp.end());

      /*
      cout << "vp[]//" << endl;
      for (int i=0 ; i<n ; i++)cout << vp[i].first+1 << " " << vp[i].second+1 << endl;
      cout << "//" << endl;*/

      N = n;
      ll ans = 0;
      for (int i=n-1 ; i>=0 ; i--){

            ll x = vp[i].first+1 , y = vp[i].second+1;

            //show(y);
            //show(PrefixSum(y));
            ans+=PrefixSum(y);
            AddElement(y,1);

      }
      cout << ans << endl;


      return 0;
}
