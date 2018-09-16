#include <bits/stdc++.h> 
using namespace std; 
#define MAX 200
int path[MAX]; 
bool visited[MAX]; 
int fromx, fromy; 
int tox, toy; 
int m , n ; 
int errflag ; 
char graph[MAX][MAX]; 

void BFS(int a, int b){
    if(errflag == 1) return ; 
    if(a > n || b > m || a < 1 || b < 1 ){
        return ; 
    }
    if(graph[a][b] == 'X' && a == tox && b == toy){
      
        cout << "YES"; 
        errflag = 1; 
        return ; 
    }
    if(graph[a][b] == 'X'){
        return; 
    }
    graph[a][b] = 'X';
    BFS(a+1,b); 
    BFS(a-1,b); 
    BFS(a,b+1); 
    BFS(a,b-1); 
    
}

int main(){
    cin >> n >> m ; 
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j ++){
            cin >> graph[i][j]; 
        }
    }
    cin >> fromx >> fromy ; 
    graph[fromx][fromy] = '.'; 
    cin >> tox >> toy; 
    BFS(fromx,fromy); 
    if(errflag == 0){
        cout << "NO"; 
        return 0 ; 
    }
}
