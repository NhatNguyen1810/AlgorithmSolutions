#include <bits/stdc++.h> 
using namespace std; 
const int INF = 1e9; 
struct triad{
  int source; 
  int target; 
  int weight; 
};

int dist[201]; 
vector<triad> graph;  
int n , m; 

void Bellman(int s){
  dist[s] = 0 ; 
  int u , v , w ; 
  for(int i = 1 ; i <= n - 1 ; i++){
    for(int j = 0 ; j < m ; j++){
      u = graph[j].source; 
      v = graph[j].target; 
      w = graph[j].weight; 
      if(dist[u] != INF && dist[u] + w < dist[v]){
        dist[v] = dist[u] + w ; 
      }
    }
  }
}


int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  int t ; 
  cin >> t ; 
  int Case = 1 ; 
  
  while(t--){
    graph.clear(); 
    cin >> n ; 
    fill(dist, dist +(n+1),INF); 
    int vertex[201]; 
    
    for(int i = 1 ; i <= n ; i++){
      int tmp; 
      cin >> tmp ; 
      vertex[i] = tmp; 
    }
    cin >> m ; 
    
    for(int i = 0 ; i < m ; i++){
      int x , y , z ; 
      cin >> x >> y ; 
      graph.push_back((triad) {x, y, int(pow(vertex[y] - vertex[x], 3))}); 
    }
    
    cout << "Case " << Case++ << ":" << endl; 
    Bellman(1); 
    int q ; 
    cin >> q ; 
    
    for(int i = 0 ; i < q ; i++){
      int x ; 
      cin >> x;   
      if(dist[x] < 3 || dist[x] == INF){
          cout << "?" << endl; 
      }  
      else{
      cout << dist[x] << endl; 
      }
    }
  }
  return 0 ; 
}
