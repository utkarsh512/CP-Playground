template <class T>
struct fenwick {
  vector<T> a;
  int n;

  fenwick() {}

  fenwick(int n_) : n(n_) {
    // initialization
    a.assign(n, (T)0);
  }

  T query(int r) {
    T q = 0; // out-of-bound values
    for (; r >= 0; r = (r & (r + 1)) - 1) {
      // operation
      q += a[r];
    }
    return q;
  }

  void update(int idx, T val) {
    for (; idx < n; idx = idx | (idx + 1)) {
      // operation
      a[idx] += val;
    }
  }
};
