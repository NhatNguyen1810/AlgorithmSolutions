#include <bits/stdc++.h> 
using namespace std; 

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  long long n ; 
  cin >> n ;
  set<long long> s; 
  long long res = 1e18; 
  for(int i = 0 ; i < n ; i++){
    long long x ; 
    cin >> x ; 
    set<long long>::iterator it = s.upper_bound(x); 
    s.insert(x); 
    if(it == s.end()){
      continue; 
    }
    else{
      res = min(res , *it - x); 
    }
  }
  cout << res ; 
  return 0 ; 
}
