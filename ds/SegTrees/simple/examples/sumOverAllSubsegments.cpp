template <class T, int SZ>
struct SegTree {
  /**
   * Description: Implementation of segment tree to find sum over
   *              all possible subsegment of any given segment [l, r]
   *              with point updates
   * Source: self
   */
  
struct Node {
  T ans, pref, suff, sum;
  int length;
};

Node newNode (T val, int len = 1) {
  Node p = {val, val, val, val, len};
  return p;
}

Node combine (Node left, Node right) {
  Node parent;
  parent.length = left.length + right.length;
  parent.ans = left.ans + right.ans;
  parent.sum = left.sum + right.sum;
  parent.pref = left.pref;
  parent.pref += left.sum * right.length + right.pref;
  parent.suff = right.suff;
  parent.suff += right.sum * left.length + left.suff;
  parent.ans += right.length * left.suff + left.length * right.pref;
  return parent;
}

  Node t[2*SZ];

  SegTree() {
    memset(t, 0, sizeof t);
  }

  void pull (int v) {
    t[v] = combine(t[2*v], t[2*v+1]);
  }

  void build (vector<T> a) {
    for (int i = 0; i < (int)a.size(); i++) {
      t[SZ + i] = newNode(a[i]);
    }
    for (int i = SZ - 1; i >= 1; i--) pull(i);
  }

  void update (int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
      t[v] = newNode(val);
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm) update(2*v, tl, tm, pos, val);
      else update(2*v+1, tm+1, tr, pos, val);
      pull(v);
    }
  }

  void upd (int pos, val) {
    update(1, 1, SZ, pos, val);
  }

  Node query (int v, int tl, int tr, int l, int r) {
    if (l > r) return newNode(0, 0);
    if (l == tl && r == tr) {
      return t[v];
    } else {
      int tm = (tl + tr) / 2;
      auto px = query(2*v, tl, tm, l, min(tm, r));
      auto py = query(2*v+1, tm+1, tr, max(tm+1, l), r);
      return combine(px, py);
    }
  }

  T get (int l, int r) {
    return query(1, 1, SZ, l, r).ans;
  }
};