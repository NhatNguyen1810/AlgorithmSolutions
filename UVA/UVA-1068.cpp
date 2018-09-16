#include <bits/stdc++.h> 
using namespace std; 
#define MAX 5000 
const int INF = 1e9; 
int dist[5000]; 
int path[5000]; 
int n ; 
struct triad{
  int source; 
  int target; 
  int weight; 
}; 
vector<triad> graph; 
void bellman(int s){
  fill(dist + 1, dist + (n + 1),INF);  
  dist[s] = 0 ; 
  int u , v , w ; 
  for(int i = 1 ; i <= n-1 ; i++){
    for(int j = 0 ; j < graph.size(); j++){ 
      u = graph[j].source; 
      v = graph[j].target; 
      w = graph[j].weight; 
      if(dist[u] != INF && dist[u] + w < dist[v]){
        dist[v] = dist[u] + w ; 
        path[v] = u ; 
      }
    }
  }
}


int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
 
  cin >> n ; 
  for(int i = 2 ; i <= n ; i++) {
    for(int j = 1 ; j < i ; j++) {
     
      
      string x;
      cin >> x ; 
      if( x != "x"){
       
        int w = atoi(x.c_str());
        graph.push_back({i, j, w}); 
        graph.push_back({j, i, w}); 
      }
    }
  }
  bellman(1);  
  int res = 0 ; 
  for(int i = 1 ; i <= n ; i++){
    res = max(res,dist[i]); 
  }
  cout << res; 
  return 0 ; 
 
}
