#include <bits/stdc++.h>
using namespace std; 
int t , n ; 
const int INF = 1e9 ; 
vector<vector<int>> graph; 
vector<vector<int>> dist; 
void Floyd(vector<vector<int>> &graph, vector<vector<int>> &dist,int size){
  int i , j , k ; 
  for(int i = 0 ; i < size ; i++){
    for(int j = 0 ; j < size ; j++){
      dist[i][j] = graph[i][j]; 
    }
  }
  
  for(int k = 0 ; k < size ; k++){
    for(int i = 0 ; i < size ; i++){
      for(int j = 0 ; j < size ; j++){
        if(dist[i][j] < dist[i][k] + dist[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j]; 
        }
      }
      
    }
  }
  
}
int main(){
 
   cin >> t ;
  
   while(t--){
     cin >> n ; 
    
     int length = 49 ; 
     graph = vector<vector<int>>(49, vector<int>(49)); 
     dist = vector<vector<int>>(49, vector<int>(49)); 
      
     for(int i = 0 ;  i < 49 ; i++){
       for(int j = 0 ; j < 49 ; j++){
         if(i == j){
           graph[i][j] = 0 ; 
         }
         else{
           graph[i][j] = -INF; 
         }
       }
     }
     
      int x , y , z ; 
      for(int i = 0 ; i < n ; i++){
        
         cin >> x ; 
         cin >> y ; 
         cin >> z ; 
       
          x--; 
          y--;
        graph[x][y] = z ; 
        
      }
    
     Floyd(graph,dist,49); 
     int max = -INF; 
     for(int i = 0 ; i < 49 ; i++){
       for(int j = 0 ; j < 49 ; j++){
         if(dist[i][j] > max){
           max = dist[i][j]; 
         }
       }
     }
     cout << max << endl; 
   }
  return 0 ; 
}













