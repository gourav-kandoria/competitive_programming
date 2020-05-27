#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

class MaximumBalances {
public:
  int solve(string s);
};

int MaximumBalances::solve(string s) {
  int l = s.length();
  int o=0; int c=0;
  for(int i=0; i<l; i++) {
    if(s[i]=='(') o++;
    else c++;
  }
  l = min(o,c);
  int h = l;
  return (h*(h+1))/2;
}

// int main() {
//   MaximumBalances a;
//   cout << a.solve("))()()))(()") << "\n";
// }