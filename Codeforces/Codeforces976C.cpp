#include <bits/stdc++.h> 
using namespace std; 
#define MAX 500000
int main(){
   ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    int n ; 
    pair<pair<int,int>,int> a[MAX]; 
    cin >> n ; 
    for(int i = 1 ; i <= n; i++){
         int x , y ; 
         cin >> x >> y ; 
         a[i] = make_pair(make_pair(x,y),i); 
    }
    sort(a + 1 , a + n + 1); 
    for(int i = 1 ; i <= n ; i++){
      for(int j = i + 1 ; j <= n ; j++){
        if(a[i].first.first <= a[j].first.first && a[i].first.second <= a[j].first.second){
          cout << a[i].second << " " << a[j].second << "\n"; 
          return 0 ; 
        }
      }
    }
    cout << "1" << " " << "-1"; 
    return 0 ; 
}
