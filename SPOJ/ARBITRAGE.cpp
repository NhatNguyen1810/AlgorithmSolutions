#include <bits/stdc++.h> 
using namespace std; 
int  n ; 
const double INF = 1e9; 
 

vector<vector<double>> graph; 

vector<vector<double>> dist; 

void floyd(vector<vector<double>> &graph, vector<vector<double>> &dist,int size){
  for(int i = 0 ; i < size ; i++){
    for(int j = 0 ; j < size ; j++){
      dist[i][j] = graph[i][j]; 
    }
  }
  for(int k = 0 ; k < n ; k++){
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++){
        if(dist[i][j] < dist[i][k]*dist[k][j]){
          dist[i][j] = dist[i][k]*dist[k][j]; 
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  int kase = 1 ; 
  while(cin >> n){
    if(n == 0){
      break ; 
    }
   
    graph = vector<vector<double>>(n,vector<double>(n)); 
    dist =  vector<vector<double>>(n,vector<double>(n)); 
    map<string,int> m;
    
    for(int i = 0 ; i < n ; i++){
      string str; 
      cin >> str; 
      m[str] = i; 
    }
    int M ; 
    cin >> M ; 
    
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++){
        if(i == j){
          graph[i][j] = 0.0 ;
        }
        else{
          graph[i][j] = 0.0; 
        }
      }
    }
    for(int i = 0 ; i < M ; i++){
      string str1, str2; 
      double temp; 
      cin >> str1 >> temp >> str2 ;
     
      graph[m[str1]][m[str2]] = temp; 
    }
    floyd(graph,dist,n);
    double res = -INF ; 
    for(int i = 0 ; i < n ; i++){
      if(dist[i][i] > res){
        res = dist[i][i]; 
      }
    }
    cout << "Case " << kase << ": " ;  
   
    
    if(res > 1){
      cout << "Yes" << endl ; 
    }
    else{
      cout << "No" << endl; 
    }
    kase++;
   
  }
  return 0 ; 
}
