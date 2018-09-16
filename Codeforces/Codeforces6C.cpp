#include <stdio.h> 
#include <algorithm> 
#include <iostream> 
#include <vector> 
#include <math.h>
using namespace std ; 

int main() {
   
   int n ; 
   cin >> n ; 
   vector<int> a ; 
   a.resize(n); 
   for(int i = 0 ; i < n ; i++){
       cin >> a[i]; 
   }
   int alice = 1 ; 
   int bob = 1 ; 
   int atime = a[0] ; 
   int btime = a[a.size() - 1] ; 
   int curra = 0 ; 
   int currb = a.size() - 1 ; 
   if(n == 1){
       cout << "1" << " " << "0"; 
       return 0 ; 
   }
   if(n == 2){
       cout << "1" << " " << "1" ; 
       return 0 ; 
   }
   for(int i = 0 ; i < n ; i++){
       while(atime < btime && currb > curra + 1 ){
           alice ++ ; 
           curra ++ ; 
           atime += a[curra]; 
       }
       while(atime > btime && currb > curra + 1){
           bob ++ ; 
           currb -- ; 
           btime += a[currb]; 
       }
       while(atime == btime && currb - curra > 2){
           alice ++ ; 
           bob++ ; 
           currb-- ;
            curra ++ ; 
            atime += a[curra]; 
            btime += a[currb]; 
       }
      while(atime == btime && currb - curra == 2){
          alice ++ ; 
          curra ++ ; 
          currb -- ; 
          atime += a[curra] ; 
          btime += a[currb]; 
      }
     
    
   }
   cout << alice << " " << bob ; 
   return 0 ; 
}
