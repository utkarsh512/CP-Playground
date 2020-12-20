template <class T>
struct fenwick {
  vector<T> a;
  int n;

  fenwick() {}

  fenwick(int n_) : n(n_) {
    a.resize(n);
  }

  T query(int r) {
    T sum = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
      sum += a[r];
    }
    return sum;
  }

  void add(int idx, T del) {
    for (; idx < n; idx = idx | (idx + 1)) {
      a[idx] += del;
    }
  }
};
