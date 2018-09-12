#include <bits/stdc++.h> 
using namespace std; 
vector<int> a[1005]; 


int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  string s; 
  cin >> s; 
  queue<char> q; 
  int res = 0 ; 
  for(char x : s){
    if(x == '(' ){
      q.push(x); 
    }
    else if(x == ')'){
      if(q.empty() == true){
        continue;
      }
      else {
        q.pop(); 
        res += 2 ; 
      }
    }
  }
  cout << res; 
  return 0 ; 
}
