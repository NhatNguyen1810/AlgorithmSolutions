#include<bits/stdc++.h> 
using namespace std; 
#define MAX 500
char s[MAX][MAX]; 
int visited[MAX][MAX]; 
int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  int n , m ; 
  cin >> n >> m ;
  memset(visited,0,sizeof(visited));
  for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < m ; j++){
        cin >> s[i][j]; 
      }
    cout << endl; 
  }
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      for(int k = 0 ; k < n ; k++){
        if(s[k][j] == s[i][j] && k != i){
          visited[i][j] = 1 ; 
        }
      }
      for(int k = 0 ; k < m ; k++){
        if(s[i][k] == s[i][j] && k != j){
          visited[i][j] = 1; 
        }
      }
    }
  }
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      if(visited[i][j] == 0){
        cout << s[i][j]; 
      } 
    }
  }
  return 0 ; 
}
