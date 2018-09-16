#include <bits/stdc++.h> 
using namespace std; 

bool Binary(vector<int> &a, int left, int right, int x){
  while(left <= right){
    int mid = (right+left)/2; 
    if(a[mid] == x){
      return true; 
    }
    else if(x > a[mid]){
      left = mid + 1; 
    }
    else if(x < a[mid]){
      right = mid - 1; 
    }
  }
  return false; 
}

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  int n, k; 
  vector<int> a; 
  cin >> n ; 
  cin >> k; 
  int tmp; 
  int res = 0 ; 
  for(int i = 0 ; i < n ; i++){
    cin >> tmp; 
    a.push_back(tmp); 
  }
  sort(a.begin(),a.end()); 
  int sz = a.size() - 1; 
  for(int i = 0 ; i < n ; i++){
    if(Binary(a,0,n-1,a[i]+k)){
      res++;
    }
  }
  cout << res; 
  return 0;
}
