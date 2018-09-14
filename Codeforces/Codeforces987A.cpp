#include <bits/stdc++.h> 
using namespace std; 



int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cout.tie(0); 
  int n; 
  cin >> n; 
  vector<int> a; 
  int cnt = 0 ; 
  vector<int> res; 
  int v[5000]; 
  int tmp; 
  for(int i = 0 ; i < n ; i++){
    cin >> tmp; 
    v[tmp]++;
    a.push_back(tmp); 
  }
  for(int i = 0 ; i < n ; i++){
    if(v[a[i]] > 1){
      v[a[i]]--;
    }
    else if(v[a[i]] == 1){
      cnt++; 
      res.push_back(a[i]); 
    }
    
  }
  cout << cnt << endl; 
  for(int i = 0 ; i < res.size() ; i++){
    cout << res[i] << " " ;
  }
  return 0 ; 
  
}
