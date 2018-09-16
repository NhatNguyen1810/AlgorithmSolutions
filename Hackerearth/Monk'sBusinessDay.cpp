#include<bits/stdc++.h> 
using namespace std; 
#define MAX 500 
const int INF = 1e9 ; 
int dist[5000]; 
int n , m ; 
struct triad{
  int source; 
  int target; 
  int weight; 
};
vector<triad> graph; 
int path[5000]; 
bool bellman(int s){
  dist[s] = 0 ; 
  int u , v , w ; 
  for(int i = 1 ; i <= n - 1 ; i++){
    for(int j = 0; j < m ; j++){
      u = graph[j].source; 
      v = graph[j].target; 
      w = graph[j].weight; 
      if(dist[u] != INF && dist[u] + w < dist[v]){
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
  int t ;
  cin >> t ; 
  while(t--){
      graph.clear(); 
      cin >> n >> m ; 
      fill(dist,dist+n,INF); 
      for(int i = 0 ; i < m ; i++){
        int x , y , z ; 
        cin >> x >> y >> z ; 
        triad temp; 
        temp.source = x ; 
        temp.target = y ; 
        temp.weight = -z; 
        graph.push_back(temp); 
      }
      bool res = bellman(1); 
    if(res == false){
      cout << "Yes" << endl ; 
    }
    else {
      cout << "No" << endl; 
    }
  }
  return 0 ; 
}
