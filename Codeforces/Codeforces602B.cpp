#include <iostream> 
#include <vector> 
#include <math.h> 
using namespace std; 

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    int n, c[10000000] ; 
    cin >> n ;
    vector<int> a ;
     a.resize(n); 
     for(int i = 0 ; i < n ; i++){ 
         cin >> a[i]; 
     }
     int cnt = 0 ; 
   
     int j = 0 ; 
     int length = 0 ; 
     for(int i = 0 ; i < n ; i++){
       
         if(c[a[i]] == 0) cnt ++ ; 
           c[a[i]] ++ ; 
         while (cnt > 2 ) {
             c[a[j]]-- ; 
            
             if(c[a[j]] == 0 ){
                 cnt --; 
             }
              j++ ; 
            
         }
         length = max(length,i - j + 1 ); 
     }
     cout << length  ; 
     return 0 ; 
}
