
#include <bits/stdc++.h> 
using namespace std; 
#define MAX 11

struct node{
  struct node *child[MAX]; 
  int countWord = 0; 

struct node *newNode(){
  struct node *Node = new struct node; 
  Node->countWord = 0; 
  for(int i = 0 ; i < MAX ; i++){
    Node -> child[i] = NULL; 
  }
  return Node; 
}

void addWord(struct node *root, string s){


  struct node *temp = root; 
  for(int i = 0 ; i < s.size(); i++){
    ch = s[i] - '0'; 
    
    if(temp->child[ch] == NULL){
      temp->child[ch] = newNode(); 
    }
    
    temp = temp->child[ch]; 
    
    
  }
  temp->countWord++; 
}

bool findWord(struct node *root, string s){
  int ch; 
  struct node *temp = root; 
  for(int i = 0 ; i < s.size() ; i++){
    ch = s[i] - '0'; 
    if(temp -> child[ch] == NULL){
      return false; 
    }
    if(temp->countWord > 0){
      return true; 
    }
    temp = temp->child[ch]; 
  }
  return false; 
}

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  //cout.tie(0); 
  int t; 
  cin >> t ; 
  int n ; 
  int kase = 1; 
  
  while(t--){
    cin >> n ; 
    struct node *root = newNode(); 
    vector<string> v; 
    bool res = false;
    for(int i = 0 ; i < n ; i++){
      string s; 
      cin >> s ; 
      v.push_back(s); 
    }
    sort(v.begin(),v.end()); 
   
    for(int i = 0 ; i < n ; i++){
      
      addWord(root, v[i]); 
      res = findWord(root,v[i]); 
      if(res == true){
        cout << "NO" << endl; 
        break;
      }
      
    }
    if(res == false){
      cout << "YES" << endl;
    }
    
    
    kase++; 
  }
  return 0 ; 
}
