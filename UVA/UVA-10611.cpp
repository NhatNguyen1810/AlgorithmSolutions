//8/18/2018 12:29pm 
Nhat Nguyen//


#include <bits/stdc++.h> 
using namespace std; 

int BinarySearch(vector<int> &a, int left, int right, int x){
  int mid = left  + (right-left)/2; 
  while(left <= right){
    if((mid == left || x > a[mid-1]) && x == a[mid]){
      return mid; 
    }
    else if(a[mid] < x){
      return BinarySearch(a,mid+1,right,x); 
    }
    else {
      return BinarySearch(a,left,mid-1,x); 
    }
  }
  return -1; 
}
int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  int N , Q; 
  cin >> N ; 
  vector<int> a; 
  int tmp; 
  for(int i = 0 ; i < N ; i++){
    cin >> tmp; 
    a.push_back(tmp); 
  }
  cin >> Q ; 
  vector<int>::iterator it; 
  for(int i = 0 ; i < Q ; i++){
    cin >> tmp; 
    it = upper_bound(a.begin(),a.end(),tmp); 
    int index = it - a.begin(); 
    int flag = 0; 
    int res = index; 
    if(index == a.size()){
      flag = 1;
      index = a.size() - 1; 
    }
    while(a[index] >= tmp){
      index--; 
    }
    if(index < 0){
      cout << 'X' << " " ;
      if(flag == 1){
        cout << 'X' << endl;
      }
      else{
        cout << a[res] << endl;
      }
    }
    else{
      cout << a[index] << " " ;
      if(flag == 1){
        cout << 'X' << endl; 
      }
      else{
        cout << a[res] << endl; 
      }
    }
  }
  return 0 ; 
}











