// segtree with one-based indexing
// `SZ` must be a power of 2
//
// build:
//    segtree<int, (1 << 18)> seg;
//    seg.build(a); // vector `a` must be zero-indexed
// 
// update:
//    seg.update(pos, inc);
//
// query:
//    seg.query(l, r)

template <class T, int SZ>
class segtree {
  vector<T> t;

  void pull(int v) {
    t[v] = t[v << 1] + t[v << 1 | 1]; // check pulling
  }

public:
  segtree() {
    T default_value = 0; // check default value
    t.assign(SZ << 1, default_value);
  }

  void build(const vector<T>& a) {
    assert(sz(a) <= SZ);
    for (int i = 0; i < sz(a); i++) {
      t[SZ + i] = a[i];
    }
    for (int i = SZ - 1; i >= 1; i--) {
      pull(i);
    }
  }

  void update(int pos, T inc, int v = 1, int tl = 1, int tr = SZ) {
    if (tl == tr) {
      t[v] += inc; // check update rule
    } else {
      int tm = (tl + tr) >> 1;
      if (pos <= tm) {
        update(pos, inc, v << 1, tl, tm);
      } else {
        update(pos, inc, v << 1 | 1, tm + 1, tr);
      }
      pull(v);
    }
  }

  T query(int l, int r, int v = 1, int tl = 1, int tr = SZ) {
    if (l > tr || r < tl) return 0; // check out-of-index value
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) >> 1;
    // check query operation
    return query(l, r, v << 1, tl, tm) + query(l, r, v << 1 | 1, tm + 1, tr);
  }
};
