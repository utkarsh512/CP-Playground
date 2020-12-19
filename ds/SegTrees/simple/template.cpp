/**
 * Description: Template for Segment Tree without Lazy Propagation
 * How to use:
 *  SZ -> maximum length of the array (in powers of 2)
 *  init:
 *    SegTree<int, (1 << 18)> seg;
 *  operation:
 *    build  -> seg.build(a); Note: a must be zero-indexed
 *    update -> seg.update(pos, inc);
 *    query  -> seg.query(L, R);
 * Source: self
 */

template <class T, int SZ>
struct SegTree {
  T t[2*SZ];

  SegTree () {
    // initialization
    memset(t, 0, sizeof t);
  }

  void pull (int v) {
    // operation
    t[v] = t[2*v] + t[2*v+1];
  }

  void build (const vector<int>& a) {
    assert((int)a.size() <= SZ);
    for (int i = 0; i < (int)a.size(); i++) {
      t[SZ + i] = a[i];
    }
    for (int i = SZ - 1; i >= 1; i--) {
      pull(i);
    }
  }

  void update (int pos, T inc, int v = 1, int tl = 1, int tr = SZ) {
    if (tl == tr) {
      // update operation
      t[v] += inc;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm) {
        update(pos, inc, 2 * v, tl, tm);
      } else {
        update(pos, inc, 2 * v + 1, tm + 1, tr);
      }
      pull(v);
    }
  }

  T query (int l, int r, int v = 1, int tl = 1, int tr = SZ) {
    if (l > tr || r < tl) return 0; // out-of-index value
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    // query operation
    return query(l, r, 2*v, tl, tm) + query(l, r, 2*v+1, tm+1, tr);
  }
};