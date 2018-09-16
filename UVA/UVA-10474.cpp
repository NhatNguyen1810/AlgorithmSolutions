#include <bits/stdc++.h>
using namespace std;

int BFSFirst(vector<int> &a, int left, int right, int x) {
  if (left <= right) {
    int mid = left + (right - left) / 2;
    
    if (a[mid] == x && (mid == left || a[mid - 1] < x)) {
      return mid;
    }
    else if (a[mid] < x) {
      return BFSFirst(a, mid + 1, right, x);
    }
    else {
      return BFSFirst(a, left, mid - 1, x);
    }
  }
  
  return -1;
}

int main() {
  int x, index, N, Q;
  int t = 1;
  vector<int> a;
  
  while (true) {
    cin >> N >> Q;
    
    if (N == 0 && Q == 0) {
      break;
    }
    
    a.resize(N);
    
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    cout << "CASE# " << t++ << ":" << endl;
    
    for (int i = 0; i < Q; i++) {
      cin >> x;
      
      index = BFSFirst(a, 0, N - 1, x);
      
      if (index == -1) {
        cout << x << " not found" << endl;
      }
      else {
        cout << x << " found at " << index + 1 << endl;
      }
    }
  }
  return 0;
}
