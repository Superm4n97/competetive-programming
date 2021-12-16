#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int& x, int& y) {
      if (b == 0) {
            x = 1;
            y = 0;
            return a;
      }
      int x1, y1;
      int d = gcd(b, a % b, x1, y1);
      x = y1;
      y = x1 - y1 * (a / b);
      return d;
}
/*Degenerate Case: a=b=0
if c=0 infinite solution, else c!=0 no solution*/
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
      g = gcd(abs(a), abs(b), x0, y0);
      if (c % g) {
            return false;
      }

      x0 *= c / g;
      y0 *= c / g;
      if (a < 0) x0 = -x0;
      if (b < 0) y0 = -y0;
      return true;
}

int main()
{
      int x,y,g;
      find_any_solution(1,2,6,x,y,g);

      cout << x << ":" << y << " : " << g << endl;
}
