#include <bits/stdc++.h> 
using namespace std; 
#define MAX 11 

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

void addWord(struct node *root, string s,bool &flag){
  int ch; 
  struct node *temp = root; 
  for(int i = 0 ; i < s.size(); i++){
    ch = s[i] - '0'; 
    if (temp->countWord > 0){
      flag = true; 
    }
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
    temp = temp->child[ch]; 
  }
  return temp->countWord > 0 ; 
}
int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  int t; 
  cin >> t ; 
  int n ; 
  int kase = 1; 
  
  while(t--){
    cin >> n ; 
    struct node *root = newNode(); 
    vector<string> v; 
    bool res = false;
    cout << "Case " << kase << ": " ; 
    for(int i = 0 ; i < n ; i++){
      string str; 
      cin >> str; 
      v.push_back(str); 
      addWord(root, str, res); 
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








