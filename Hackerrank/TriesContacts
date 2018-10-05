#include <bits/stdc++.h> 
using namespace std; 
#define MAX 27

struct node{
  struct node *child[MAX]; 
  int countWord = 0; 
}; 

struct node *newNode(){
  struct node *Node = new struct node; 
  for(int i = 0 ; i < MAX ; i++){
    Node -> child[i] = NULL; 
  }
  return Node; 
}

void addWord(struct node *root, string s){
  int ch; 
  struct node *temp = root; 
  for(int i = 0 ; i < s.size(); i++){
    ch = s[i] - 'a'; 
    
    if(temp->child[ch] == NULL){
      temp->child[ch] = newNode(); 
    }
     
    temp = temp->child[ch]; 
    temp->countWord++;
  }
}

int findWord(struct node *root, string s){
  int ch; 
  struct node *temp = root; 
  for(int i = 0 ; i < s.size() ; i++){
    ch = s[i] - 'a'; 
    if(temp -> child[ch] == NULL){
      return 0; 
    }
    temp = temp->child[ch]; 
  }
  return temp->countWord  ; 
}
int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  int n ; 
  cin >> n ; 
  struct node *root = newNode(); 
  for(int i = 0 ; i < n ; i++){
    string str1, str2; 
    cin >> str1; 
    if(str1 == "add"){
      cin >> str2; 
      addWord(root,str2); 
    }
    else if(str1 == "find"){
      cin >> str2;
      int res = findWord(root,str2); 
      cout << res << endl; 
    }
  }
  
  
  return 0 ; 
}
