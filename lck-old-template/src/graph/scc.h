#pragma once
#include "../general.h"
#include "../util.h"

int tarjan_dfs(const vec<vec<int>> &adj, vec<int> &id, vec<int> &dfn,
               vec<int> &low, stack<int> &s, vec<bool> &in, int &cid, int &ord,
               int u) {
  s.push(u);
  in[u] = 1;
  dfn[u] = low[u] = ord++;
  for (int v : adj[u]) {
    if (in[v])
      low[u] = min(low[u], dfn[v]);
    else if (dfn[v] < 0)
      low[u] = min(low[u], tarjan_dfs(adj, id, dfn, low, s, in, cid, ord, v));
  }
  if (low[u] == dfn[u]) {
    while (s.top() != u) {
      int v = s.top();
      id[v] = cid;
      in[v] = false;
      s.pop();
    }
    id[u] = cid++;
    in[u] = false;
    s.pop();
  }
  return low[u];
}

int scc(const vec<vec<int>> &adj, vec<int> &id) {
  stack<int> s;
  int cid = 0, ord = 0, n = sz(adj);
  vec<int> dfn(n), low(n);
  vec<bool> in(n);
  dfn.assign(n, -1);
  id.assign(n, 0);
  rep(u, 0, n) if (dfn[u] < 0)
      tarjan_dfs(adj, id, dfn, low, s, in, cid, ord, u);
  return cid;
}

vec<vec<int>> condense_scc(const vec<vec<int>> &adj, vec<int> &id, int m) {
  int n = sz(adj);
  vec<vec<int>> res(m);
  rep(u, 0, n) {
    for (int v : adj[u]) {
      if (id[v] != id[u]) res[id[u]].pb(id[v]);
    }
  }
  rep(i, 0, m) make_unique(res[i]);
  return res;
}