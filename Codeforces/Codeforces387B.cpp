#include <iostream> 
#include <vector> 
using namespace std; 

int main() {
    ios::sync_with_stdio(false) ; 
    cin.tie(0); 
    int n , m ; 
    cin >> n >> m ; 
    vector<int> a , b ; 
    a.resize(n); 
    b.resize(m);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i]; 
    }
    for (int i = 0 ; i < m ; i++){
        cin >> b[i]; 
    }
    int i = 0 , j = 0 ; 
    int total = n ; 
    int cnt = 0 ; 
    while(i < n && j < m ){
        if(a[i] > b[j]){
            j++; 
        }
        else {
            i++; 
            j++; 
            cnt++; 
        }
        
    }
   
    cout << n - cnt ; 
    return 0 ; 
}
