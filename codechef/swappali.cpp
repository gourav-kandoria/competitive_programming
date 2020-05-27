#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    int l; cin >> l;
    string str; cin >> str;
    map<char,int> mp;
    for(auto a : str) {
      mp[a]++;
    }
    int e=0; int o=0;
    for(auto p : mp) {
      if(p.second%2==0) e++;
      else o++;
    }
    if(o>1) {cout << "NO\n"; continue;}
    int sz = l;
    vector<bool> allowed(l);
    for(int i=0; i<l; i++) allowed[i]=1;
    int op=0;
    for(int i=0; 1 ; i++) {
      if(sz==1) break;
      if(sz==3) {
        if(str[i]!=str[l-1-i]) {
          if(mp[str[i]]%2==1 and allowed[i]) {swap(str[i],str[i+1]); op++;}
          else if(mp[str[i+2]]%2==1 and allowed[i+2]) {swap(str[i+1],str[i+2]); op++;}
          if(str[i]==str[i+2]) break;
          else {
            // cout << "1st\n";
            cout << "NO\n"; goto place;
          }
        }
      }
      else if(sz==2) {
        if(str[i]!=str[i+1]) {
          // cout << "2nd\n";
          cout << "NO\n"; goto place;}
          break;
      }
      if(str[i]!=str[l-1-i]) {
        if((str[i]==str[l-1-i-1]) and allowed[l-1-i]) {
          swap(str[l-1-i],str[l-2-i]); op++;
          allowed[l-1-i]=0; allowed[l-2-i]=0;
        }
        else if((str[i+1]==str[l-1-i]) and allowed[i]) {
          swap(str[i],str[i+1]); op++;
          allowed[i]=0; allowed[i+1]=0;
        }
        else {
          // cout << "3rd\n";
          cout << "NO\n"; goto place;
        }
      }
      sz-=2;
    }
    cout << "YES\n" << op << "\n";
    place: ;
  }
}