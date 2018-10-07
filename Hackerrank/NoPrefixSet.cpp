#include <bits/stdc++.h> 
using namespace std; 
#define MAX 28

struct node{
  struct node *child[MAX]; 
  int countWord = 0; 
}; 
struct node *newNode(){
  struct node *Node = new struct node; 
  Node->countWord = 0; 
  for(int i = 0 ; i < MAX ; i++){
    Node -> child[i] = NULL; 
  }
  return Node; 
}

void addWord(struct node *root, string s, bool &flag){
  int ch; 
  struct node *temp = root; 
  for(int i = 0 ; i < s.size(); i++){
    ch = s[i] - 'a'; 
    
    if(temp->child[ch] == NULL){
      temp->child[ch] = newNode(); 
    }
    temp = temp->child[ch]; 
    
    if(temp -> countWord > 0){
      flag = true; 
    }
  }
  for(int i = 0 ; i < MAX ; i++){
    if(temp->child[i] != NULL){
      flag = true; 
      break;
    }
  }
  temp->countWord++; 
 
}



bool findWord(struct node *root, string s){
  int ch; 
  struct node *temp = root; 
  for(int i = 0 ; i < s.size() ; i++){
    ch = s[i] - 'a'; 
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
  cout.tie(0); 
  int n ; 
  cin >> n ; 
  vector<string> v; 
  bool res = false; 
  struct node *root = newNode(); 
  for(int i = 0 ; i < n ; i++){
    string str; 
    cin >> str ; 
    v.push_back(str); 
  }
 
  
  
  for(int i = 0 ; i < v.size() ; i++){
    bool flag; 
    addWord(root,v[i],res); 
    if(res == true){
      cout << "BAD SET" << endl; 
      cout << v[i] << endl; 
      break;
    }
    
  }
  if(res == false){
    cout << "GOOD SET" << endl; 
  }
  return 0 ; 
}
