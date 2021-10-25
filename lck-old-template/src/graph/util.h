#pragma once
#include "../general.h"

vec<int> top_sort(const vec<vec<int>> &adj) {
  int n = sz(adj);
  vec<int> in_deg(n);
  rep(i, 0, n) {
    for_each(all(adj[i]), [&](int v) { in_deg[v]++; });
  }
  queue<int> q;
  rep(i, 0, n) if (in_deg[i] == 0) q.push(i);
  vec<int> top_order;
  int u;
  while (!q.empty()) {
    top_order.pb(u = q.front());
    q.pop();
    for (int v : adj[u]) {
      if (--in_deg[v] == 0) q.push(v);
    }
  }
  return top_order;
}

bool is_dag(const vec<vec<int>> &adj) { return sz(top_sort(adj)) == sz(adj); }

bool is_chain(const vec<vec<int>> &adj) {
  int n = sz(adj);
  vec<int> top_order = top_sort(adj);
  if (sz(top_order) != n) return false;
  rep(i, 0, n - 1) {
    int u = top_order[i];
    if (sz(adj[u]) != 1 || adj[u][0] != top_order[i + 1]) return false;
  }
  return sz(adj[top_order[n - 1]]) == 0;
}

vec<vec<int>> tranpose(const vec<vec<int>> &gr) {
  vec<vec<int>> res;
  int n = sz(gr);
  res.assign(n, vec<int>());
  rep(u, 0, n) {
    for (int v : gr[u]) {
      res[v].pb(u);
    } 
  }
  return res;
}