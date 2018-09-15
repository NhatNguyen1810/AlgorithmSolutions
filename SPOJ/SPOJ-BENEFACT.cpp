#include <bits/stdc++.h> 
#define MAX 50001
using namespace std; 

vector<int> graph[MAX];
long long path[MAX];
 
map<pair<int,int>,int> dist; 
long long max_dist = 0 ; 
long long f = 0 ;

void bfs(int s){
  memset(path, -1, sizeof(path)); 
  stack<int> q; 
  q.push(s); 
  path[s] = 0;
  
  while (!q.empty()){
    int u = q.top(); 
    q.pop(); 
    
    for (int i = 0 ; i < graph[u].size() ; i++){
      int next = graph[u][i]; 
      pair<int,int> p = make_pair(u,next); 
      if (path[next] == -1){
        path[next] = path[u] + dist[p]; 
        q.push(next); 
        
        if(path[next] > max_dist){
          max_dist = path[next]; 
          f = next ; 
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  int t, n; 
  int a, b, c; 
  cin >> t; 
  
  while (t--){
     for (int i = 0; i < MAX; i++) {
       graph[i].clear();
     }
    
      cin >> n; 
      for (int i = 0; i < n - 1 ; i++){
        cin >> a >> b >> c ; 
        pair<int,int> p1 = make_pair(a, b); 
        pair<int,int> p2 = make_pair(b, a); 
        dist[p2] = c; 
        dist[p1] = c; 
        graph[a].push_back(b); 
        graph[b].push_back(a);
      }
      max_dist = 0;
      bfs(1); 
      bfs(f); 
      cout << max_dist << endl; 
  }
  return 0 ; 
}
