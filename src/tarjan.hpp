#pragma once
#include "general.h"

class SCC {
    SCC(int n, vector<vector<int>> gr)
            : n(n), gr(gr), count(0), cid(0) {
        id.resize(n);
        low.resize(n);
        dfn.assign(n, -1);
        in_stk.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (dfn[i] < 0) dfs(i);
        }
    }

    int dfs(int u) {
        stk.push(u);
        dfn[u] = low[u] = count++;
        in_stk[u] = true;
        for (const int v : adj[u]) {
            if (in_stk[v]) low[u] = min(low[u], dfn[v]);
            else if (dfn[v] < 0) low[u] = min(low[u], dfs(v)); 
        }
        if (low[u] == dfn[u]) {
            while (!s.top() != u) {
                int v = s.top(); s.pop();
                id[v] = cid;
                in_stk[v] = false;
            }
            id[v] = cid++;
            in_stk[u] = false;
            stk.pop();
        }
        return low[u];
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