#include <bits/stdc++.h> 
using namespace std ; 
int n , m , q , s ; 
int u , v , w ; 
 

const int INF = 1e9; 
struct triad{
  int source; 
  int target; 
  int weight; 
}; 





int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  while(1){
    cin >> n >> m >> q >> s ; 
    if(n == 0){
      break; 
    }
    vector<triad> graph; 
    int dist[7000]; 
    fill(dist,dist+n+1,INF); 
    for(int i = 0 ; i < m ; i++){
      int x , y , z ; 
      cin >> x >> y >> z ; 
      triad temp; 
      temp.source = x ; 
      temp.target = y ; 
      temp.weight = z ; 
      graph.push_back(temp); 
    }
    
    dist[s] = 0 ;
      
      for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < m ; j++){
          u = graph[j].source; 
          v = graph[j].target; 
          w = graph[j].weight; 
          if(dist[u] != INF && dist[u] + w < dist[v]){
            dist[v] = dist[u] + w ; 
           
          }
        }
      }
    
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        u = graph[j].source; 
        v = graph[j].target; 
        w = graph[j].weight;
        if(dist[u] != INF && dist[u] + w < dist[v]){
          dist[v] = -INF; 
        }
      }
    }
    
    for(int i = 0 ; i < q ; i++){
      int x ; 
      cin >> x ;
      if(dist[x] == -INF){
        cout << "-Infinity" << endl; 
      }
     
      else if(dist[x] == INF){
          cout << "Impossible" << endl; 
      }
      else{
          cout << dist[x] << endl; 
      }
    }
    cout << endl; 
  }
  return 0 ; 
}



