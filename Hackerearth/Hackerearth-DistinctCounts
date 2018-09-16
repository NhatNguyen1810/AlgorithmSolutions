#include <bits/stdc++.h> 
using namespace std; 

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  int t; 
  cin >> t ;
  while(t--){
    set<int> s; 
    int n , m ; 
    cin >> n >> m ; 
    int tmp; 
    for(int i = 0 ; i < n + m ; i++){
      cin >> tmp; 
      if(i < n){
        s.insert(tmp); 
      }
      else{
        set<int>::iterator it; 
        it = s.find(tmp); 
        if(it != s.end()){
          cout << "YES" << endl;
          
        }
        else{
          cout << "NO" << endl; 
          s.insert(tmp); 
        }
      }
    }
  }
  return 0;
}




