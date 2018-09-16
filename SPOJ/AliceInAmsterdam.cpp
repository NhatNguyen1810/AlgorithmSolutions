#include <bits/stdc++.h> 
using namespace std; 
#define MAX 500 
const int INF = 1e9; 
int n ; 
struct triad{
  int source; 
  int target; 
  int weight; 
}; 
int dist[5000]; 
vector<triad> graph; 
int path[5000]; 
map<int,string> m; 
bool bellman(int s){
  fill(dist,dist+n,INF); 
  dist[s] = 0 ;
  int u , v , w ; 
  for(int i = 0 ; i <= n-2 ; i++){
    for(int j = 0 ; j < n*n ; j++){
      u = graph[j].source; 
      v = graph[j].target; 
      w = graph[j].weight; 
      if(dist[u] != INF && dist[u] + w < dist[v]){
        dist[v] = dist[u] + w ; 
        path[v] = u; 
      }
    }
  }
  for(int i = 0 ; i < n*n ; i++){
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
  
  int kase = 1 ; 
  
  while(1){
      
      cin >> n ; 
      if(n == 0 ){
        break;
      }
      graph.clear(); 
     
      for(int i = 0 ; i < n ; i++){
        string str ; 
        cin >> str ; 
        m[i] = str ;
        for(int j = 0 ; j < n ; j++){
          int x ; 
          cin >> x ; 
          if((x == 0 && i != j)){
            continue;
          }
          
          triad temp;
          temp.source = i; 
          temp.target = j ; 
          if(i == j && x > 0){
            temp.weight = 0 ; 
          }
          else {
            temp.weight = x ; 
          }
          graph.push_back(temp); 
        }
      }
    
    cout << "Case #" << kase++ << ":" << endl;  
    int q; 
    cin >> q; 
    for(int i = 0 ; i < q ; i++){
      int x , y ; 
      cin >> x >> y ; 
      bool res = bellman(x); 
      if(res == false){
        cout << "NEGATIVE CYCLE" << endl; 
      }
      else if(dist[y] == INF){
        cout << m[x] << "-" << m[y] << " NOT REACHABLE"   << endl; 
      }
      else if(dist[y] != INF){
        cout << m[x] << "-" << m[y] << " " << dist[y] << endl; 
      }
    }
    
  }
  return 0 ; 

}

