#include <bits/stdc++.h> 
using namespace std; 

int main() {
    string::iterator it ; 
    vector<string> begin; 
    for(int i = 1 ; i <= 3 ; i++){
        string str; 
        cin >> str; 
        string str1 = ""; 
        
        for(int i = 0 ; i < str.size() ; i++){
            if( (isalpha(str[i])|| isalnum(str[i])) && !isupper(str[i])) {
                str1 += str[i]; 
            }
            if(isupper(str[i])){
                str[i] = tolower(str[i]); 
                str1 += str[i]; 
            }
        }
        begin.push_back(str1); 
        
    }
    int n ; 
    vector<string> contain; 
    cin >> n ; 
    for(int i = 0 ; i < n ; i++){
        string str1; 
        cin >> str1; 
        string str2 = "" ; 
        for(int i = 0 ; i < str1.size() ; i++){
            if( (isalpha(str1[i]) || isalnum(str1[i]) ) && !isupper(str1[i])){
                str2 += str1[i]; 
            }
            if(isupper(str1[i])){
                str1[i] = tolower(str1[i]); 
                str2 += str1[i]; 
            }
        }
        contain.push_back(str2);
     
    }
    vector<string> cmp ; 
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            for(int l = 0 ; l < 3 ; l++){
                if(i != l && l != j && j != i  && l + i + j == 3 ){
                   
                    string str = ""; 
                    str += begin[i]; 
                    str += begin[j]; 
                    str += begin[l]; 
                    cmp.push_back(str); 
                   
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        int cnt = 0 ;
        for(int j = 0 ; j < (int)cmp.size(); j ++){
             
            int pos = contain[i].find(cmp[j]); 
            if(pos != -1){
                cout << "ACC" << endl;
                break;
            }
            cnt++; 
            if(cnt == (int)cmp.size()){
                cout << "WA" << endl;
                break;
            }
        }
       
    }
    return 0 ; 
}
