#include <bits/stdc++.h> 
using namespace std; 
const int INF = 1e9; 
int t, n ;
vector<vector<double>> graph; 
vector<vector<double>> dist; 
 

void floyd(vector<vector<double>> &graph ,vector<vector<double>> &dist,int size){
  int i , j , k ; 
  for(i = 0 ; i < size ; i++){
    for(j = 0 ; j < size ; j++){
      dist[i][j] = graph[i][j]; 
    }
  }
  for(k = 0 ; k < size ; k++){
    for(i = 0 ; i < size ; i++){
      for(j = 0 ; j < size ; j++){
        if(dist[i][j] > dist[i][k] + dist[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j] ; 
        }
      }
    }
  }
}
double distance(int x , int y){
  return sqrt(pow(x,2) + pow(y,2) ) ; 
}
int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  cin >> t ; 
  int kase = 1 ; 
  while(t--){
    cin >> n ; 
    graph = vector<vector<double>>(n , vector<double>(n)); 
    dist = vector<vector<double>>(n, vector<double>(n)); 
    vector<int> xCoord; 
    vector<int> yCoord;
    for(int i = 0 ; i < n ; i++){
      int x , y ; 
      cin >> x >> y ; 
      xCoord.push_back(x); 
      yCoord.push_back(y); 
    }
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++){
        graph[i][j] = INF; 
      }
    }
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++){
        double tmp = sqrt(pow(xCoord[j] - xCoord[i],2) + pow(yCoord[j] - yCoord[i], 2) ) ; 
        if(tmp <= 10){
          graph[i][j] = tmp; 
        }
        
      }
    }
    floyd(graph,dist,n); 
    double res = 0 ; 
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++){
        if(res < dist[i][j]){
          res = dist[i][j]; 
        }
      }
    }
    cout << "Case #" << kase << ":" << endl; 
    if(res != INF){
      
      cout << fixed << setprecision(4) << res << endl; 
    }
    else{
      cout << "Send Kurdy" << endl ; 
    }
    cout << endl; 
    kase++; 
  
  }
 return 0 ; 
}
