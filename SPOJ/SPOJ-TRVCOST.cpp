#include <bits/stdc++.h> 
using namespace std; 
#define INF 1e9 
#define MAX 1000
int n, U , Q ; 
 
vector<vector<pair<int,int>>> graph; 
vector<int> dist(MAX, INF); 
 
struct option{
  bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
    return a.second < b.second; 
  }
};
 
void Dijkstra(int s){
  priority_queue<pair<int,int>, vector<pair<int,int>>, option> pq; 
  dist[s] = 0 ; 
  pq.push(make_pair(s, 0)); 
  
  while(!pq.empty()){
    pair<int,int> top = pq.top(); 
    pq.pop(); 
    int u = top.first; 
    int w = top.second; 
    for(int i = 0 ; i < graph[u].size(); i++){
      pair<int,int> next = graph[u][i]; 
      if(w + next.second < dist[next.first]){
        dist[next.first] = w + next.second; 
        pq.push(make_pair(next.first, dist[next.first]));  
      }
    }
  }
}
 
int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  dist = vector<int>(MAX, INF); 
  graph = vector<vector<pair<int,int>>> (MAX + 5, vector<pair<int,int>>()); 
  cin >> n ; 
  
  for (int i = 0 ; i < n ; i++){
    int x , y , z; 
    cin >> x >> y >> z ; 
    graph[x].push_back(pair<int,int>(y,z)); 
    graph[y].push_back(pair<int,int>(x,z)); 
  }
  
  cin >> U ; 
  Dijkstra(U); 
  
  cin >> Q ; 
  
  for(int i = 0 ; i < Q ; i++){
    int x ; 
    cin >> x; 
    
    if (dist[x] != INF) {
      cout << dist[x] << "\n";  
    }
    else{
      cout << "NO PATH" << "\n";  
    }
    
  }
  
  return 0 ; 
  
} 
