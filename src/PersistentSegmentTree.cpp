template<class T>
struct PersistentSegmentTree {
  // TODO
  const static T INITIAL_NODE_VALUE;

  int n;
  vector<T> seg;
  vector< vector<int> > ch;
  vector<int> vsn;

  int init_node (T val = INITIAL_NODE_VALUE) {
    seg.push_back(val);
    ch.push_back(vector<int>{0, 0});
    return (int)seg.size() - 1;
  }

  PersistentSegmentTree(int _n) : n(_n) {
    vsn.push_back(init_node());
  }

  // TODO
  T merge (T x, T y) {
    
  }

  // TODO
  T get_updated_leaf_value (T leaf, T val) {
    
  }

  void _update (int i, int &j, int idx, T val, int l, int r) {
    if (l == r) {
      j = init_node(get_updated_leaf_value(seg[i], val));
      return;
    }
    if (!j) j = init_node();

    int m = (0LL + l + r) >> 1;
    if (idx <= m) {
      _update(ch[i][0], ch[j][0], idx, val, l, m);
      ch[j][1] = ch[i][1];
    } else {
      ch[j][0] = ch[i][0];
      _update(ch[i][1], ch[j][1], idx, val, m + 1, r);
    }
    seg[j] = merge(seg[ch[j][0]], seg[ch[j][1]]);
  }

  T _query (int ql, int qr, int l, int r, int i) {
    if (qr < l || r < ql) return INITIAL_NODE_VALUE;
    if (ql <= l && r <= qr) return seg[i];
    int m = (l + r) >> 1;
    return merge(_query(ql, qr, l, m, ch[i][0]), _query(ql, qr, m + 1, r, ch[i][1]));
  }

  // idx: Index to update
  // val: Value of update
  // vlas: The version from which the update takes place (defaults to the most updated version)
  void update (int idx, T val, int vlas = -1) {
    if (vlas == -1) vlas = (int)vsn.size() - 1;
    vsn.push_back(0);
    _update(vsn[vlas], vsn.back(), idx, val, 1, n);
  }

  // [l, r]: Query range (in Segment tree index)
  // v: Version of segment tree to query
  T query (int l, int r, int v = -1) {
    if (v == -1) v = (int)vsn.size() - 1;
    return _query(l, r, 1, n, vsn[v]);
  }
};