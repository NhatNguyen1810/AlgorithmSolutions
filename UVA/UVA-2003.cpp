#include<bits/stdc++.h> 
using namespace std; 

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0); 
  string str; 
  set<string> s; 
  vector<string> v;
  string temp = "" ; 
  while(cin >> str){
    
    if(str[str.size() - 1] == '-'){
      str.erase(str.size() -1 , str.size() + 1); 
      temp += str;
    }
    else{
      temp += str; 
      
      for(int i = 0 ; i < temp.size() ; i++){
        temp[i] = tolower(temp[i]); 
        if(!isalpha(temp[i]) && temp[i] != '-'){
          temp[i] = ' '; 
        }
      }
      stringstream ss(temp); 
      string token; 
      while(ss >> token){
        s.insert(token); 
      }
      temp = ""; 
    }
  }
  set<string>::iterator it; 
  for(it = s.begin() ; it != s.end() ; it++){
    v.push_back(*it); 
  }
  sort(v.begin(),v.end()); 
  for(int i = 0 ; i < v.size() ; i++){
    cout << v[i] << endl; 
  }
  return 0 ; 
}
