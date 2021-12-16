#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000007

using namespace std;

struct mat
{
      ll arr[2][2];
};

void matshow(mat A)
{
      cout << endl;
      cout << A.arr[0][0] << " " << A.arr[0][1] << endl;
      cout << A.arr[1][0] << " " << A.arr[1][1] << endl;
      cout << endl;
}

ll amod(ll a)
{
      return a - a/mod*mod;
}

mat base()
{
      mat A;
      A.arr[0][0] = 1;
      A.arr[0][1] = 1;
      A.arr[1][0] = 1;
      A.arr[1][1] = 0;
      return A;
}

mat matMul(mat A, mat B)
{
      mat ret;
      ret.arr[0][0] = ((A.arr[0][0]*B.arr[0][0])%mod + (A.arr[0][1]*B.arr[1][0])%mod)%mod;
      ret.arr[0][1] = ((A.arr[0][0]*B.arr[0][1])%mod + (A.arr[0][1]*B.arr[1][1])%mod)%mod;
      ret.arr[1][0] = ((A.arr[1][0]*B.arr[0][0])%mod + (A.arr[1][1]*B.arr[1][0])%mod)%mod;
      ret.arr[1][1] = ((A.arr[1][0]*B.arr[0][1])%mod + (A.arr[1][1]*B.arr[1][1])%mod)%mod;
      return ret;
}

mat bigmod(mat A, ll pw)
{
      if (pw==1)return A;
      mat temp = bigmod(A,pw/2);
      temp = matMul(temp,temp);
      if (pw%2) return matMul(temp,A);
      return temp;
}

ll bigmodLL(ll a, ll pw)
{
      if (pw==0)return 1;
      if (pw%2)return amod(bigmodLL(a,pw-1)*a);
      ll temp = bigmodLL(a,pw/2);
      return amod(temp*temp);
}

ll cal(ll a,ll b, ll xx, ll yy)
{
      return a*xx+b*yy;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll n,x,m,y,k , a,b,c,d;
            scanf("%lld %lld %lld %lld %lld",&n,&x,&m,&y,&k);

            mat temp = bigmod(base(),n+1);
            a = temp.arr[0][0];
            b = temp.arr[0][1];

            temp = bigmod(base(),m+1);
            c = temp.arr[0][0];
            d = temp.arr[0][1];

            ll xx = amod(amod(b*y) - amod(d*x) + mod);
            ll dn = amod(amod(b*c) - amod(d*a) + mod);
            dn = bigmodLL(dn,mod-2);
            xx = amod(xx*dn);
            ll yy = amod(amod(x - amod(a*xx) + mod) * bigmodLL(b,mod-2));

            /*show(a);
            show(b);
            show(c);
            show(d);
            show(xx);
            show(yy);*/

            printf("Case %d: ",_t);
            if (cal(a,b,xx,yy)!=x || cal(c,d,xx,yy)!=y)printf("Impossible\n");
            else {
                  temp = bigmod(base(),k+1);
                  ll ans = amod(amod(temp.arr[0][0]*xx) + amod(temp.arr[0][1]*yy));
                  printf("%lld\n",ans);
            }
      }

      return 0;
}

/*
a
b
ab
bab
abbab
bababbab

a
1
1 1 2 3 4
=5

|f(n)|  |a b| x
|g(n)|  |1 0| y

ax+by = X
y = (X - ax)/b
cx+dy = Y
bcx + dX - dax = Yb
x(bc - da) = bY - dX
x = (bY - dX) / (bc - da)


*/
