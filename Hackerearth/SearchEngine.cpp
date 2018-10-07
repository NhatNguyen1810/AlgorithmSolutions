#include <bits/stdc++.h> 
using namespace std; 
#define MAX 27
int RES = 0 ; 
struct node{
  struct node *child[MAX]; 
  int countWord = 0; 
  int prior = 0 ; 
  bool cont = false; 
}; 
struct node *newNode(){
  struct node *Node = new struct node; 
  Node->countWord = 0; 
  Node->prior = 0 ; 
  Node->cont = false; 
  for(int i = 0 ; i < MAX ; i++){
    Node -> child[i] = NULL; 
  }
  return Node; 
}

void addWord(struct node *root, string s, int num){
  int ch; 
  int length = s.size(); 
  struct node *temp = root; 
  for(int i = 0 ; i < s.size(); i++){
    ch = s[i] - 'a'; 
    
    if(temp->child[ch] == NULL){
      temp->child[ch] = newNode(); 
    }
    temp->cont = true; 
    temp->prior = max(temp->prior,num);  
    temp = temp->child[ch]; 
    
    
  }
    temp->countWord++; 
    temp->prior = num;
}

  
  


node* findWord(struct node *root, string s){
  int ch; 
  int res = 0 ; 
  struct node *temp = root; 
  for(int i = 0 ; i < s.size() ; i++){
    ch = s[i] - 'a'; 
    if(temp -> child[ch] == NULL){
      return 0; 
    }
    res = max(res,temp->prior); 
    temp = temp->child[ch]; 
  }
  return temp; 
}

void DFS(struct node *cur){
  if(cur == NULL){
    return ; 
  }
  if(cur->cont == true){
    if(cur->prior > RES){
      RES = cur->prior; 
    }
  }
  for(int i = 0; i < MAX ; i++){
    if(cur->child[i] != NULL){
      DFS(cur->child[i]); 
    }
  }
}
int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  
  int n , m ;
  cin >> n >> m ; 
  struct node *root = newNode(); 
  for(int i = 0 ; i < n ; i++){
    string str;
    int prior; 
    cin >> str >> prior; 
    addWord(root,str,prior); 
  }
  for(int i = 0 ; i < m ; i++){
    string str; 
    cin >> str;
    RES = -1; 
    node* temp = findWord(root,str); 
    DFS(temp); 
    cout << RES << endl; 
  }
  return 0 ; 
}
