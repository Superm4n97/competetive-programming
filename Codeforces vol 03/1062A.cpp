#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n , ans = 0;
      cin >> n;
      stack < ll > st;

      for (int i=0 ; i<n ; i++){

            ll a;
            cin >> a;
            if (st.empty())st.push(a);
            else {
                  if (st.top()+1 == a){
                        st.push(a);
                  }
                  else {
                        ll beg =st.top() - st.size() +1  , ed = st.top();

                        if (st.size()==1){
                              st.pop();
                              st.push(a);
                              continue;
                        }

                        //show(st.size());

                        ll temp = st.size()-2;
                        if (beg==1)temp++;
                        if (ed==1000)temp++;

                        while(!st.empty())st.pop();

                        ans = max(ans,temp);
                        st.push(a);
                  }
            }
      }



      if (st.size()>1){
            ll beg =st.top() - st.size() +1  , ed = st.top();
            ll temp = st.size()-2;
            if (beg==1)temp++;
            if (ed==1000)temp++;

            ans =max(ans, temp);
      }



      cout << ans << endl;

      return 0;
}
