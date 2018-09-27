#include<bits/stdc++.h> 
using namespace std; 

const int INF = 1e9; 

vector<vector<int>> graph; 
vector<vector<int>> dist;  
vector<int> pos; 
int t , n ; 

void Floyd(vector<vector<int>> &graph, vector<vector<int>> &dist,int size,vector<int> &pos){
  int i , j , k ; 
  for(int i = 0 ; i < size ; i++){
    for(int j = 0 ; j < size ; j++){
      dist[i][j] = graph[i][j]; 
    }
  }
  
  for(int k = 0 ; k < size ; k++){
    for(int i = 0 ; i < size ; i++){
      for(int j = 0 ; j < size ; j++){
        if(dist[i][j] > dist[i][k] + dist[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j]; 
        }
      }
      
    }
  }
  for(int i = 0 ; i < size ; i++){
    for(int j = 0 ; j < size ; j++){
      if(dist[i][j] == 2){
        pos[i]++;
        
      }
    }
  }
}




int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  cin >> t; 
  while(t--){
   
    string temp; 
    string s ; 
    cin >> s ; 
    int length = s.size(); 
    graph = vector<vector<int>>(length, vector<int>(length)); 
    
    dist = vector<vector<int>>(length, vector<int>(length)); 
      
    pos = vector<int>(length);  
    for(int i = 0 ; i < s.size() ; i++){
      if(i == 0){
        graph[0][i] = 0; 
      }
      else{
        if(s[i] == 'N'){
          graph[0][i] = INF ; 
        }
        else if(s[i] == 'Y'){
          graph[0][i] = 1 ; 
        }
        
      }
    }
    
    for(int i = 1 ; i < length  ; i++){
      cin >> temp; 
      for(int j = 0 ; j < length ; j++){
        
        if(temp[j] == 'N' && i != j){
          graph[i][j] = INF ; 
        }
        else if(temp[j] == 'Y'){
          graph[i][j] = 1 ; 
        }
        else if(i == j){
          graph[i][j] = 0 ; 
        }
      }
    }
    
    Floyd(graph,dist,s.size(),pos); 
    int max = -INF; 
    int peopleID; 
    int possibleFriends ; 
    for(int i = 0 ; i < pos.size() ; i++){
      if(pos[i] > max){
        max = pos[i]; 
        peopleID = i ; 
      }
    }
    cout << peopleID << " " << max  << endl; 
  }
 return 0 ; 
}
