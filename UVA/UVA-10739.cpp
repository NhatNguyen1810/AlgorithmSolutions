#include <bits/stdc++.h> 
using namespace std; 
int palin(string str, int i , int j){
  if(i == j){
    return 0 ; 
  }
  else if(i > j){
    return 0 ; 
  }
  else if(str[i] == str[j]){
    return palin(str,i+1,j-1); 
  }
  else{
    return 1 + min(palin(str,i+1,j-1),min(palin(str,i,j-1),palin(str,i+1,j))); 
  }
}
int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  int t ;
  cin >> t ;
  int kase = 1 ; 
  while(t--){
    string s; 
    cin >> s; 
    int res = palin(s,0,s.size()-1); 
    cout << "case " << kase << ": " << res << endl; 
    kase++;
  }
  return 0 ; 
}
