#include <bits/stdc++.h> 
using namespace std; 
#define MAX 1000 
bool visited[MAX][MAX]; 
char graph[MAX][MAX]; 
bool valid[MAX][MAX]; 
int n , m , k ; 
struct point{
    int x; 
    int y; 
    point(int a = 0 , int b = 0){
        x = a ; 
        y = b ; 
    };
};
int dx[] = {1,0,-1,0}; 
int dy[] = {0,1,0,-1}; 
vector<int>  a , b  ; 
vector<point> c;
void BFS(point r){
    int cnt = 1; 
    c.push_back(r); 
    visited[r.x][r.y] = true; 
    point u ; 
    queue<point> q; 
    q.push(r); 
    int x , y ; 
    while(!q.empty()){
        u = q.front(); 
        q.pop(); 
        for(int i = 0 ; i < 4 ; i++){ 
            x = u.x + dx[i]; 
            y = u.y + dy[i]; 
            if(x >=1 && x <= n-2 && y >= 1 && y <= m-2){  
                if(!visited[x][y] && graph[x][y] == '.' && valid[x][y] == true){
                    visited[x][y] = true; 
                    q.push(point(x,y)); 
                    cnt += 1; 
                }
            } 
        }
    }
   a.push_back(cnt); 
}

void BFSInvalid(point r){
    valid[r.x][r.y] = false; 
    visited[r.x][r.y] = true; 
    queue<point> q ; 
    point u ; 
    int xx , yy ; 
    q.push(r); 
    while(!q.empty()){
        u = q.front(); 
        q.pop(); 
        for(int i = 0 ; i < 4 ; i++){
             xx = u.x + dx[i]; 
             yy = u.y + dy[i]; 
             if(xx >= 0 && xx <= n-1 && yy >= 0 && yy <= m-1){
                 if(valid[xx][yy] == true && visited[xx][yy] == false && graph[xx][yy] == '.' ){
                     valid[xx][yy] = false ; 
                     visited[xx][yy] = true ; 
                     q.push(point(xx,yy)); 
                     
                 }
             }
        }
    }
}
 
void fill(point a){
    if(graph[a.x][a.y] == '*'){
        return ; 
    }
    graph[a.x][a.y] = '*' ; 
    int xx, yy ; 
    for(int i = 0 ; i < 4 ; i++){
        xx = a.x + dx[i]; 
        yy = a.y + dy[i]; 
        if(xx >=1 && xx <= n-1 && yy >= 1 && yy <= m-1){
            if(graph[xx][yy] == '.' && valid[xx][yy] == true && visited[xx][yy] ==true){
                graph[xx][yy] == '*'; 
                fill(point(xx,yy)); 
            }
        }
    }
}
bool option(int a, int b){
    return a < b ; 
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cin >> n >> m >> k ; 
    point start; 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m  ; j ++){
            valid[i][j] = true; 
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            visited[i][j] = false; 
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> graph[i][j]; 
 
        }
    }
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            if(!visited[i][j] && graph[i][j] == '.' && (i == 0 || i == n-1 || j == 0 || j == m-1) && valid[i][j] == true){
                BFSInvalid(point(i,j)); 
            }
           
        }
    }
    for(int i = 0 ; i < n ; i++){ 
        for(int j = 0 ; j < m ; j++){
            if(!visited[i][j] && graph[i][j] == '.' && (i >= 1 && i <= n-2 && j >= 1 && j <= m-2) && valid[i][j] == true){
                BFS(point(i,j)); 
            }
        }
    }
    
   b = a ; 
    
   sort(b.begin(), b.end(), option); 
   int count = 0 ; 
    int res = a.size() ; 
    while(res > k){
        for(int i = 0 ; i < b.size() ; i++){
            for(int j = 0 ; j < b.size() ; j++){
                if(a[j] == b[i] ){
                   
                    int temp1 = c[j].x , temp2 = c[j].y ; 
                    if(graph[temp1][temp2] == '.'){
                        fill(c[j]); 
                        count += a[j]; 
                      res--;
                    }
                }
                
                if(res == k){
                  
                   cout << count << endl ; 
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ;j < m ; j++){
            cout << graph[i][j]; 
        }
        cout << "\n"  ; 
    }
    return 0 ; 
                }
            }        
        }
    }
    cout << count << endl ; 
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ;j < m ; j++){
            cout << graph[i][j]; 
        }
        cout << "\n"  ; 
    }
    return 0 ; 
}
