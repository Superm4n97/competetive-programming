#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006
#define base 137
#define mod 1000000021

using namespace std;

string words[maxn];
vector<pair<ll,ll> > words_hash;
stack<ll> st , ans;
ll P[maxn];

ll amodb(ll a, ll b)
{
      return a - a/b*b;
}

void make(string s,ll id)
{
      ll hs = 0;
      reverse(s.begin(),s.end());
      for (int i = 0 ; i<s.size() ; i++){
            if (s[i]>='A' && s[i]<='Z')s[i]+=32;
            hs = amodb(hs*base+s[i],mod);
            //hs = amodb(hs,mod);

            if (i==s.size()-1){
                  words_hash.push_back({hs,id});
//                  show(s);
//                  show(hs);
            }
            else {
                  words_hash.push_back({hs,0});
            }
      }
}

ll findVal(ll hs)
{
      ll b = 0 , e = words_hash.size()-1 , ret = -1;

      while(b<=e){
            ll mid = (b+e)/2;
            if (words_hash[mid].first<=hs)
            {
                  if (hs==words_hash[mid].first)ret = max(ret,mid);
                  b = mid+1;
            }
            else e = mid-1;
      }
      return ret;
}

int main()
{
      P[0] = 1;
      for (int i=1 ; i<maxn ; i++){
            P[i] = P[i-1]*base;
            P[i] = amodb(P[i],mod);
      }

      ll n;
      cin >> n;
      string s;
      cin >> s;

      ll m;
      cin >>m;

      for (int i=1 ; i<=m ; i++){
            cin >> words[i];
            make(words[i],i);

            //show(words_hash.size());
      }

      sort(words_hash.begin(),words_hash.end());

      ll sz = 0 , cur = 0;


      for (int i=0 ; i<s.size() ; i++){
            cur = amodb(cur*base+s[i],mod);
            sz++;

            ll fnd = findVal(cur);
            while(fnd==-1){
                  ll tp = st.top();
                  st.pop();

                  ll H = words_hash[tp].first , len = words[words_hash[tp].second].size();
                  H = amodb(H*P[sz],mod);
                  cur = amodb(H+cur,mod);
                  sz +=len;

                  fnd = findVal(cur);
            }

            if (words_hash[fnd].second>0){
                  st.push(fnd);
                  sz = 0;
                  cur = 0;
            }
      }
      if (cur!=0){
            while(true){
                  ll tp = st.top();
                  st.pop();

                  ll H = words_hash[tp].first , len = words[words_hash[tp].second].size();
                  H = amodb(H*P[sz],mod);
                  cur = amodb(H+cur,mod);
                  sz += len;

                  ll fnd = findVal(cur);
                  if (fnd==-1 || words_hash[fnd].second==0)continue;

                  {
                        st.push(fnd);
                        break;
                  }
            }
      }
      //show(m);

      while(!st.empty()){
            ans.push(st.top());
            st.pop();
      }

      while(!ans.empty()){
            cout << words[words_hash[ans.top()].second] << " ";
            ans.pop();
      }
      printf("\n");


      return 0;
}
