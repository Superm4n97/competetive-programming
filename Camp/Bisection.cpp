#include<bits/stdc++.h>
using namespace std;

double Bisection(double val)
{
      double b = 0, e = val , mid;
      for (int i=0 ; i<100 ; i++){
            mid = (b+e)/2;
            if (mid*mid>val)e = mid;
            else b = mid;
      }
      return mid;
}

int main()
{
      double num = 2;
      printf("%.9f\n",Bisection(num));
}
