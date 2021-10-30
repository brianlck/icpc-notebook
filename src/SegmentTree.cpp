template<class T>
struct SegmentTree {
  // TODO: Seg Tree - Initial values of seg tree nodes
  const T INITIAL_NODE_VALUE;

  int n;
  vector<T> seg;

  SegmentTree(int n) : n(n) {
    seg.resize(n * 4 + 5, INITIAL_NODE_VALUE);
  }

  // TODO: Compute the node value from its two children
  // e.g. seg[i] = get_merged_node_value(seg[i * 2], seg[i * 2 + 1])
  T merge (T x, T y) {
    
  }

  // TODO: Update segment tree node value
  // e.g. seg[i] = merge_update_value_into_node(seg[i], v);
  template<class U>
  T merge_update_value_into_node (T v0, U val) {
    
  }

  T _query (int ql, int qr, int l, int r, int i) {
    if (qr < l || r < ql) return INITIAL_NODE_VALUE;
    if (ql <= l && r <= qr) return seg[i];
    int m = (l + r) >> 1;
    return merge(_query(ql, qr, l, m, i * 2), _query(ql, qr, m + 1, r, i * 2 + 1));
  }

  template<class U>
  void _update (int idx, U v, int l, int r, int i) {
    if (l == r) {
      seg[i] = merge_update_value_into_node(seg[i], v);
      return;
    }
    int m = (l + r) >> 1;
    if (idx <= m) _update(idx, v, l, m, i * 2);
    else _update(idx, v, m + 1, r, i * 2 + 1);
    seg[i] = merge(seg[i * 2], seg[i * 2 + 1]);
  }

  T query (int l, int r) {
    return _query(l, r, 1, n, 1);
  }

  template<class U>
  void update (int idx, U v) {
    return _update(idx, v, 1, n, 1);
  }
};
