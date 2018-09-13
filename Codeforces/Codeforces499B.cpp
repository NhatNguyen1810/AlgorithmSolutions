#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll; 
#define maxn 5001 
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    int n , m ; 
    cin >> n >> m ; 
    vector<string> a, b ; 
    for(int i = 0 ; i < m ; i++){
        string x , y ; 
        cin >> x >> y ; 
        a.push_back(x) ;
        b.push_back(y); 
    }
    vector<string> d; 
    d.resize(n);
    for(int i = 0 ; i < n ; i++){
        cin >> d[i]; 
        for(int j = 0 ; j < m ; j++){
            if(d[i] == a[j] || d[i] == b[j]){
                if(a[j].size() <= b[j].size()){
                    cout << a[j] << " "; 
                }
                else {
                    cout << b[j] << " "; 
                }
            }
        }
    }
    
    return 0 ; 
}
