#include <bits/stdc++.h> 
using namespace std; 

bool BNRS(vector<int> &a, int left, int right, int x){
  while(left <= right){
    int mid = left + (right- left)/2; 
    if(a[mid] == x){
      return true; 
    }
    else if(a[mid] > x){
      right = mid - 1; 
    }
    else {
      left = mid + 1; 
    }
  }
  return false; 
}
int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  int n , k; 
  int t ; 
  cin >> t; 
  while(t--){
    int res = 0 ; 
    cin >> n >> k ; 
    vector<int> a;
    int tmp; 
    for(int i = 0 ; i < n ; i++){
      cin >> tmp; 
      a.push_back(tmp);
    }
    sort(a.begin(),a.end()); 
    for(int i = 0 ; i < n ; i++){
      if(BNRS(a,0,n-1,k-a[i])){
        res++;
      }
    }
    cout << res/2 << endl;
  }
  return 0 ; 
}
