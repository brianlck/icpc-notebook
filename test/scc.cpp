// M1321 - Going from u to v or from v to u?  

#include <bits/stdc++.h>
using namespace std;

#include "../src/tarjan.hpp"

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gr(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        gr[u].push_back(v);
    }
    auto t = SCC(n, gr);
    auto id = SCC(n, gr).id;
    int cid = ranges::max(id) + 1;
    vector<vector<int>> gr2(cid);
    vector<int> in(cid, 0);
    for (int u = 0; u < n; ++u) {
        for (int v : gr[u]) {
            if (id[u] != id[v]) {
                gr2[id[u]].push_back(id[v]);
                in[id[v]]++;
            }
        }
    }

    int count = 0;
    queue<int> q;
    for (int i = 0; i < cid; ++i)
        if (!in[i]) q.push(i);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        count++;
        if (q.size() > 0) {
            puts("No");
            return;
        }
        for (int v : gr2[u]) {
            if (--in[v] == 0) q.push(v);
        }
    }
    puts(count == cid ? "Yes" : "No");
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();    
}
