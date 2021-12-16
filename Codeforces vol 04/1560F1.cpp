#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 2000000000000000018

using namespace std;

ll numberOfDigits , k,n, typesOfDigits, f1,f2 , f2_found;
vector<ll> digits;

void info(ll x)
{
      digits.clear();
      numberOfDigits = 0;
      set<ll> st;
      while(x){
            numberOfDigits++;

            st.insert(x%10);
            digits.push_back(x%10);
            x/=10;
      }
      typesOfDigits = st.size();
      reverse(digits.begin(),digits.end());
      for (int i=0 ; i<digits.size() ; i++){
            if (i==0)f1 = digits[i];
            else if (digits[i]!=digits[i-1]){
                  f2 = digits[i];
                  f2_found = i;
                  break;
            }
      }
}

ll makeOne(ll a)
{
      ll temp  = a;
      for (int i=0 ; i<numberOfDigits-1 ; i++){
            temp*=10;
            temp+=a;
      }
      return temp;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            scanf("%lld %lld",&n,&k);
            info(n);

            if (typesOfDigits==k)cout << n << endl;
            else {
                  if (k==1){
                        ll ans = inf;
                        ll x = makeOne(digits[0]);
                        if (x>=n)ans = min(ans,x);
                        x = makeOne(digits[0]+1);
                        if(x>=n)ans = min(ans,x);
                        cout << ans << endl;
                  }
                  else {
                        if (numberOfDigits==1){
                              cout << 10 - digits[0] << endl;
                        }
                        else {
                              if (typesOfDigits==1)cout << n+1 << endl;
                              else {
                                    ll large = 0;
                                    for (int i=2; i<digits.size() ; i++){
                                          if (digits[i] != f1 && digits[i]!=f2){
                                                //123
                                                if (digits[i]>f1 && digits[i]>f2){
                                                      ll _new = f2+1;
                                                      if (_new==f1){
                                                            for (int j=0; j<numberOfDigits ; j++){
                                                                  digits[j] = _new;
                                                            }
                                                            digits[numberOfDigits-1]--;
                                                      }
                                                      else {
                                                            f2 = _new;
                                                            digits[f2_found] = f2;
                                                            for (int j=f2_found+1 ;j<numberOfDigits ; j++){
                                                                  digits[j] = min(f1,f2);
                                                            }
                                                      }
                                                      break;
                                                }
                                                else if (digits[i]<f1 && digits[i]<f2){
                                                      for (int j=i ; j<numberOfDigits ; j++)digits[j] = min(f1,f2);
                                                      break;
                                                }
                                                else {
                                                      digits[i] = max(f1,f2);
                                                      for (int j=i+1 ; j<numberOfDigits ; j++)digits[j] = min(f1,f2);
                                                      break;
                                                }
                                          }
                                    }
                                    for (int i=0 ; i<numberOfDigits ; i++)cout << digits[i];
                                    cout << endl;
                              }
                        }
                  }
            }
      }

      return 0;
}
