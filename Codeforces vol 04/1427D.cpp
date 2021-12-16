#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
vector <ll> G[60] , v;

int main()
{
      cin >> n;
      for (int i=0 ; i<n ; i++){

            ll a;
            cin >> a;
            v.push_back(a);
      }

      ll ans = 0;

      while(true){

            ll mn = 0 , temp = 0 , x = 0;
            vector <ll> part , v_new;

            for (int i=0 ; i<n ; i++){
                  if (mn<v[i]-1){

                        ll a,b,c,d;

                        if (i>0)G[ans].push_back(i);

                        a = i;

                        ll j = i+1;
                        while(v[j]==v[j-1]+1)j++;

                        if (j-i>0) G[ans].push_back(j-i);

                        b = j;
                        temp = j;

                        while(v[j]!=v[i]-1)j++;

                        if (j-temp+1>0)G[ans].push_back(j-temp+1);

                        c = j+1;

                        if (n-j-1>0)G[ans].push_back(n-j-1);

                        for (j = c ; j<n ; j++)v_new.push_back(v[j]);
                        for (j = b ; j<c ; j++)v_new.push_back(v[j]);
                        for (j = a ; j<b ; j++)v_new.push_back(v[j]);
                        for (j = 0 ; j<a ; j++)v_new.push_back(v[j]);

                        v = v_new;

                        x  = 1;
                        ans++;
                        break;
                  }
                  mn = max(mn,v[i]);
            }

            if (x==0)break;
      }

      cout << ans << endl;
      for (int i=0 ; i<ans ; i++){
            cout << G[i].size() << " ";
            for (int j=0 ; j<G[i].size() ; j++)cout << G[i][j] << " ";
            cout << endl;
      }

      return 0;
}
