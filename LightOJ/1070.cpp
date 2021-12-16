#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout<<#x <<" : "<<x<< endl

using namespace std;

ll p , q , n;

struct mat
{
      ll a,b,c,d;
};

mat baseInitialize()
{
      mat A;
      A.a = p;
      A.b = -q;
      A.c = 1;
      A.d = 0;
      return A;
}

/*
void matShow(mat A)
{
      cout << endl;
      cout << A.a<< " " << A.b << endl;
      cout << A.c<< " " << A.d << endl;
      cout << endl;
}
*/

mat matMul(mat A,mat B)
{
      mat ret;
      ret.a = A.a*B.a + A.b*B.c;
      ret.b = A.a*B.b + A.b*B.d;
      ret.c = A.c*B.a + A.d*B.c;
      ret.d = A.c*B.b + A.d*B.d;
      return ret;
}

mat bigmod(mat A, ll pw)
{
      if (pw==1)return A;
      mat temp = bigmod(A,pw/2);
      temp = matMul(temp,temp);

      if (pw%2)return matMul(temp,A);
      return temp;
}

int main()
{
      ll tc;
      cin >> tc;

      for (int i=1 ; i<=tc ; i++){
            cin >> p >> q >> n;
            ll a1 = p , a2 = p*p-2*q;
            cout<<"Case "<<i<<": ";
            if (n==0)cout << 2 << endl;
            else if (n==1)cout << p << endl;
            else if (n==2)cout << a2 << endl;
            else {
                  mat T = bigmod(baseInitialize(),n-2);
                  unsigned long long ans = a2*T.a + a1*T.b;
                  cout << ans << endl;
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

f(n b) = |1 1| f(n-1 b) f(n-1 a)+f(n-1 b)
f(n a) = |1 0| f(n-1 a) f(n-1 b)


*/
