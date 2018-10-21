#include <bits/stdc++.h> 
using namespace std; 
const int MAX = 500; 
struct edge{
  int u , v ; 
  double w ; 
  bool operator<(const edge &a){
    return w < a.w; 
  }
}; 
vector<edge> e; 
vector<edge> e1;
int n;
int pr[MAX]; 
void makeset(int n){
  for(int i = 0 ; i < n ; i++){
    pr[i] = i ; 
  }
}
int find(int r){
  if(pr[r] == r){
    return r; 
  }
  return r = find(pr[r]); 
}

double kruskal(int n, int size){
  int cnt = 0 ; 
  double sum = 0 ; 
  makeset(n); 
  sort(e.begin(),e.end());
  
  for(int i = 0 ; i < e.size() ; i++){
    e1.push_back(e[i]); 
  }
  
  for(int i = 0; i < e1.size() ; i++){
    int x = find(e1[i].u); 
    int y = find(e1[i].v); 
    if(i < size){
      sum += e1[i].w; 
      pr[y] = x ; 
    }
    else{
      if(x != y){
          pr[y] = x ;
          sum += e1[i].w; 
          cnt++; 
       }
    }
    
  }
  for(int i = 0 ; i < size ; i++){
    sum -= e1[i].w; 
  }
  return sum; 
}
struct point{
  int x , y ; 
};

int main(){
  while(cin >> n){
    if(n == 0){
      break;
    }
    int m;
    vector<point> pt; 
    set<pair<int,int>> cable;
    
    for(int i = 0 ; i < n ; i++){
      point tmp; 
      int x , y; 
      cin >> x >> y ; 
      tmp.x = x ; 
      tmp.y = y ; 
      pt.push_back(tmp);
    }
    cin >> m ; 
    for(int i = 0 ; i < m ; i++){
      int x , y ; 
      cin >> x >> y; 
      x--;
      y--;
      
      cable.insert(make_pair(x,y)); 
      
    }
    set<pair<int,int>>::iterator it1; 
    set<pair<int,int>>::iterator it2; 
    for(int i = 0 ; i < pt.size() - 1 ; i++){
      for(int j = i + 1 ; j < pt.size() ; j++){
        it1 = cable.find(pair<int,int>(j,i)); 
        it2 = cable.find(pair<int,int>(i,j)); 
        if(it1 != cable.end() || it2 != cable.end()){
          edge data; 
          data.u = i ; 
          data.v = j; 
          data.w = sqrt(pow(pt[i].x - pt[j].x, 2) + pow(pt[i].y - pt[j].y, 2) );
          e1.push_back(data); 
        }
        else{
          edge data;
          double val = sqrt(pow(pt[i].x - pt[j].x, 2) + pow(pt[i].y - pt[j].y, 2) ) ; 
          data.u = i; 
          data.v = j; 
          data.w = val;
          e.push_back(data);
        }
      }
    }
    int size = e1.size(); 
    double ans = kruskal(n,size); 
    
    cout << fixed << setprecision(2) << ans << endl; 
    e.clear(); 
    e1.clear();
    pt.clear();
    cable.clear();
  }
  return 0 ; 
}

















