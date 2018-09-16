#include <bits/stdc++.h> 
using namespace std; 
#define MAX 1e3
bool option(const pair<int,int> &a, const pair<int,int> &b){
  return a.first < b.first;
}
int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  int n , m ; 
  cin >> n >> m ; 
  vector<int> a,d; 
  vector<pair<int,int>> b ; 
  vector<pair<int,int>> c;
  for(int i = 0 ; i < n ; i++){
    int x ; 
    cin >> x ; 
    a.push_back(x); 
  }
  for(int i = 0 ; i < m ; i++){
    int x ; 
    cin >> x ;
    b.push_back(make_pair(x,i));  
    
  }
  a.push_back(1e9 + 5); 
  sort(a.begin(), a.end()); 
  sort(b.begin(), b.end(),option); 
  int i = 0 , j = 0 ; 
  while( j < m ){
    
    if(b[j].first >= a[i]) i++; 
    else if(b[j].first < a[i]){
      c.push_back(make_pair(b[j].second,i));
      j++;
    } 
  }
  sort(c.begin(),c.end(),option); 
  for(int i = 0 ; i < c.size() ; i++){
    cout << c[i].second << " " ;  
  }
  return 0 ; 
}
