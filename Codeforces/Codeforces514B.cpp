#include <bits/stdc++.h> 
using namespace std; 


int hesogoc(int x1,int y1,int x2, int y2){
  return (y2-y1)/(x2-x1); 
}

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  int n , x0, y0; 
  cin >> n >> x0 >> y0; 
 
  set<double> s; 
  int bonus = 0;
  
  
  int tmp1 , tmp2 ; 
 
  for(int i = 0 ; i < n ; i++){
    cin >> tmp1 >> tmp2 ; 
    if(tmp1 == x0){
      bonus = 1;
    }
    else{
    int temphsg = hesogoc(x0,y0,tmp1,tmp2); 
    s.insert(temphsg); 
    }
  }
  cout << s.size() + bonus ; 
  return 0 ;  
}







