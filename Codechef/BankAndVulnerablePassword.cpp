#include <iostream>
using namespace std;
 
#define MAX 26 

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

void addWord(struct node *root, string s){
  int ch; 
  struct node *temp = root; 
  for(int i = 0 ; i < s.size(); i++){
    ch = s[i] - 'a'; 
    
    
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
    ch = s[i] - 'a'; 
    if(temp -> child[ch] == NULL){
      return false; 
    }
    if(temp->countWord != 0){
      return true; 
    }
    temp = temp->child[ch]; 
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  
  int n; 
  cin >> n;
  bool res = false; 
  struct node *root = newNode(); 
  
  
  for(int i = 0 ; i < n ; i++){
    string str;
    cin >> str;
    addWord(root,str); 
    bool flag = findWord(root,str);
    if(flag == true){
      cout << "vulnerable" ; 
      res = true; 
      break;
    }
    
  }
  if(res == false){
    cout << "non vulnerable" ; 
  }
  return 0;
}
