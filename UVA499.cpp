#include <bits/stdc++.h> 
using namespace std; 
int dist[1001];
#define MAX 105 
int INF = 1e9; 
struct triad{
  int source; 
  int target; 
  int weight;
};
vector<triad> graph; 
int n , m ; 
int path[1001]; 
bool bellman(int s){
  dist[s] = 0 ; 
  int u , v , w ; 
  for(int i = 0 ; i <= n - 2; i++){
    for(int j = 0 ; j < m ; j++){
      u = graph[j].source; 
      v = graph[j].target; 
      w = graph[j].weight; 
      if(dist[u] != INF && (dist[u] + w < dist[v]) ){
        dist[v] = dist[u] + w ; 
        path[v] = u ; 
      }
    }
  }
  for(int i = 0 ; i < m ; i++){
    u = graph[i].source; 
    v = graph[i].target; 
    w = graph[i].weight; 
    if(dist[u] != INF && dist[u] + w < dist[v]){
      return false; 
    }
  }
  return true; 
}


int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  int t; 
  cin >> t; 
  while(t--){
    graph.clear();
    cin >> n >> m; 
    fill(dist,dist+n,INF); 
    int x , y , z ; 
    
    for(int i = 0 ; i < m ; i++){
      triad temp; 
      cin >> x >> y >> z ; 
      temp.source = x ; 
      temp.target = y ; 
      temp.weight = z ; 
      graph.push_back(temp); 
    }
    bool res = bellman(0); 
    if(res == false){
      cout << "possible" << endl; 
    }
    else{
      cout << "not possible" << endl; 
    }
  }
  return 0 ; 
}
