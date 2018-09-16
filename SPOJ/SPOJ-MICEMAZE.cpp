#include <bits/stdc++.h> 
using namespace std; 
#define INF 1e9 
#define MAX 1000
int N , E , T , M ; 
 
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
  cin >> N >> E >> T >> M ;  
  
  for(int i = 0 ; i < M ; i++){
    int x , y , z ;
    cin >> x >> y >> z ; 
    graph[x].push_back(make_pair(y,z)); 
  }
  
  int res = 0 ; 
  
  for(int i = 1 ; i <= N ; i++){
    Dijkstra(i); 
   
    if (dist[E] <= T){
      res++;  
    }
    dist = vector<int>(MAX, INF); 
 
    }
 
  
  cout << res ; 
  return 0 ; 
} 
