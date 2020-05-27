#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

class ValueDivision {
public:
  vector<int> & getArray(vector<int> & A);
};

vector<int> & ValueDivision::getArray(vector<int> & vec) {
  map<int,int> mp;
  for(auto a : vec) {
    mp[a]++;
  } 
  for(map<int,int>::iterator it=--(mp.end()); 1; it--) {
    while(it->second!=1) {
      int c = it->second; 
      it->second = c-c/2;
      int count=c/2;
      if(it->first == 1) break;
      for(auto & a : vec) {
        if(count==0) break;
        if(a==it->first) {
          a--; mp[a]++;
          count--;
        }
      }
    }
    if(it==mp.begin()) break;
  }
  return vec;
}

int main() {
  ValueDivision a;
  vector<int> v = {7,7,7,7};
  vector<int> vec = a.getArray(v);
  for(auto a : vec) {
    cout << a << " ";
  }
}