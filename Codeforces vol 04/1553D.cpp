#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

ll n,m;
vector<ll>ei[30],oi[30];
string s,t;

void clean()
{
      for (int i=0 ; i<29 ; i++){
            ei[i].clear();
            oi[i].clear();
      }
      return;
}

ll findEven(ll id, ll val)
{
      if (ei[id].empty())return -1;
      ll b = 0 , e = ei[id].size()-1, ret = ei[id].size();
      while(b<=e){
            ll mid = (b+e)/2;
            if (ei[id][mid]>val){
                  ret = min(ret,mid);
                  e = mid-1;
            }
            else b = mid+1;
      }
      if (ret==ei[id].size())return -1;
      return ei[id][ret];
}

ll findOdd(ll id, ll val)
{
      if (oi[id].empty())return -1;
      ll b = 0 , e = oi[id].size()-1, ret = oi[id].size();
      while(b<=e){
            ll mid = (b+e)/2;
            if (oi[id][mid]>val){
                  ret = min(ret,mid);
                  e = mid-1;
            }
            else b = mid+1;
      }
      if (ret==oi[id].size())return -1;
      return oi[id][ret];
}

ll rec(ll pos, ll parity, ll preIndex)
{
//      show(pos);
//      show(parity);
//      show(preIndex);
      if (pos==m){
            if ((n-preIndex)%2==1)return true;
            return false;
      }

      if (parity==1){
            ll new_index = findEven((ll)(t[pos]-'a'),preIndex);
            if (new_index==-1)return false;
            return rec(pos+1,0,new_index);
      }
      else {
            ll new_index = findOdd((ll)(t[pos]-'a'),preIndex);
            if (new_index==-1)return false;
            return rec(pos+1,1,new_index);
      }
}

int main()
{
      ll tc;
      scl(tc);
      while(tc--){
            clean();
            cin >> s >> t;
            n = s.size() , m = t.size();

            for (int i=0 ; i<n ; i++){
                  ll temp = s[i]-'a';

                  if (i%2==0)ei[temp].push_back(i);
                  else oi[temp].push_back(i);
            }
            //show(oi[1].size());
            bool ans1 = rec(0,0,-1);
            bool ans2 = rec(0,1,-1);
            if (ans1)cout << "YES\n";
            else if (ans2)cout << "YES\n";
            else cout << "NO\n" ;
      }

      return 0;
}
