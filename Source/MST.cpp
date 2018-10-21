#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define MAX 10000
#define INF 0x3f3f3f3f

using namespace std;

int V, E;
typedef pair<int, int> iPair;
vector<iPair> G[MAX];

void addE(int u, int v, int w) {
    G[u].push_back(make_pair(w, v));
    G[v].push_back(make_pair(w, u));
}

long long PrimWeightMST(int s) {
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

    vector<int> key(V, INF);
    vector<bool> inMST(V, false);

    pq.push(make_pair(0, s));
    key[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        inMST[u] = true;

        pq.pop();

        for (int i = 0; i < G[u].size(); i++) {
            int w = G[u][i].first;
            int v = G[u][i].second;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    long long total_w = 0;

    for (int i = 0; i < V; i++) {
        if (!inMST[i]) {
            continue;
        }

        total_w += key[i];
    }

    return total_w;
}

int main() {
    ios::sync_with_stdio(false);
    int u, v, w;
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        addE(u - 1, v - 1, w);
    }

    cout << 2*PrimWeightMST(v - 1);
    
    return 0;
}
