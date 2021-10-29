#include <bits/stdc++.h>
using namespace std;

template<class T>
struct SegmentTree {
  // TODO: Seg Tree - Initial values of seg tree nodes
  const T INITIAL_NODE_VALUE;
  
  // TODO: Lazy Propagation - Initial values of lazy tree nodes
  const T INITIAL_LAZY_VALUE;

  int n;
  vector<T> seg, lazy;

  SegmentTree(int _n) {
    n = _n;
    seg.resize(n * 4 + 5, INITIAL_NODE_VALUE);
    lazy.resize(n * 4 + 5, INITIAL_LAZY_VALUE);
  }

  // TODO: Seg Tree - Compute the node value from its two children
  // e.g. seg[i] = get_merged_node_value(seg[i * 2], seg[i * 2 + 1])
  T merge (T x, T y) {
    
  }

  // TODO: Lazy Propagation - Construct a new lazy tag from the update value
  // e.g. lazy[i] = get_lazy_tag(update_value, l, r)
  T get_lazy_tag_from_updated_value (T v, int l, int r) {
    
  }

  // TODO: Lazy Propagation - Merge the lazy tag into the main seg tree
  // e.g. seg[i] = get_updated_node_value(seg[i], lazy[i], l, r)
  T merge_lazy_tag_into_node (T v0, T t, int l, int r) {
    
  }

  // TODO: Lazy Propagation - Propagate the lazy tag downwards
  // e.g. lazy[i * 2] = get_merged_lazy_tag(lazy[i * 2], lazy[i], l, r)
  T propagate_lazy_tag (T t0, T tpar, int l, int r) {
    
  }

  void propagate (int l, int r, int i) {
    seg[i] = merge_lazy_tag_into_node(seg[i], lazy[i], l, r);
    if (l < r) {
      lazy[i * 2] = propagate_lazy_tag(lazy[i * 2], lazy[i], l, r);
      lazy[i * 2 + 1] = propagate_lazy_tag(lazy[i * 2 + 1], lazy[i], l, r);
    }
    lazy[i] = INITIAL_LAZY_VALUE;
  }

  T _query (int ql, int qr, int l, int r, int i) {
    propagate(l, r, i);
    if (qr < l || r < ql) return INITIAL_NODE_VALUE;
    if (ql <= l && r <= qr) return seg[i];
    int m = (l + r) >> 1;
    return merge(_query(ql, qr, l, m, i * 2), _query(ql, qr, m + 1, r, i * 2 + 1));
  }

  void _update (int ql, int qr, T v, int l, int r, int i) {
    propagate(l, r, i);
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
      lazy[i] = get_lazy_tag_from_updated_value(v, l, r);
      propagate(l, r, i);
      return;
    }
    int m = (l + r) >> 1;
    _update(ql, qr, v, l, m, i * 2);
    _update(ql, qr, v, m + 1, r, i * 2 + 1);
    seg[i] = merge(seg[i * 2], seg[i * 2 + 1]);
  }

  T query (int l, int r) {
    return _query(l, r, 1, n, 1);
  }

  void update (int l, int r, T v) {
    return _update(l, r, v, 1, n, 1);
  }
};