#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n;

ll mirror(ll a)
{
      return n-a;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll a,b;
            cin >> a >> b;
            vector<ll> v;

            n = a+b;

            if (a==0 || b==0){
                  v.push_back(n/2);
                  if (mirror(n/2) != n/2)v.push_back(mirror(n/2));
            }
            else {
                  for (int i=1 ; i<=n+1 ; i++){
                        ll x = (i+1)/2 , y = (i+1)/2;
                        if (i%2==0)x++;

                        if ((x<=a && y<=b) || (x<=b && y<=a)){
                              ll temp = (n-x-y+1)/2;

//                              show(x);
//                              show(y);
//                              show(temp);
//                              show(mirror(temp));

                              v.push_back(temp);
                              if (temp!=mirror(temp))v.push_back(mirror(temp));
                        }
                  }
            }

            cout << v.size() << endl;
            sort(v.begin(),v.end());
            for (int i=0 ; i<v.size() ; i++)cout << v[i] << " ";
            cout << endl;
      }

      return 0;
}
/**
1-2 1,1
2-3 2,1
3-4 2 2
ABA
ABABAB
------
ABABAB

even:
diff jodi 0 hoy taile 0 kora jabe, 2 hoile sob kora jabe(0 baad e)

odd:
diff jodi 1 hoy sob kora jabe

5 2
ABABABA
AAABABA
**/
