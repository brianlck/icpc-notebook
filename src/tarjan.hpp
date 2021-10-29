#pragma once
#include "general.hpp"

class SCC {
    public:
    SCC(int n, vector<vector<int>> gr)
            : n(n), gr(gr), count(0), cid(0) {
        id.resize(n);
        low.resize(n);
        dfn.assign(n, -1);
        in_stk.assign(n, false);
    }

    int dfs(int u) {
        stk.push(u);
        dfn[u] = low[u] = count++;
        in_stk[u] = true;
        for (const int v : gr[u]) {
            if (in_stk[v]) low[u] = min(low[u], dfn[v]);
            else if (dfn[v] < 0) low[u] = min(low[u], dfs(v)); 
        }
        if (low[u] == dfn[u]) {
            while (stk.top() != u) {
                int v = stk.top(); stk.pop();
                id[v] = cid;
                in_stk[v] = false;
            }
            id[u] = cid++;
            in_stk[u] = false;
            stk.pop();
        }
        return low[u];
    }

    void run() {
        for (int i = 0; i < n; ++i) {
            if (dfn[i] < 0) dfs(i);
        }
        return;
    }

    int count;
    int cid;
    vector<int> id;
    stack<int> stk;
    vector<int> dfn, low;
    vector<bool> in_stk;

    int n;
    vector<vector<int>> gr;
    int tot = 0;
};