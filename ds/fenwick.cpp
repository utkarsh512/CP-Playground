template <class T>
class fenwick {
  vector<T> a;
  int n;
  
public:
  fenwick() {}

  fenwick(int n_) : n(n_) {
    // check initial value
    a.assign(n, static_cast<T>(0));
  }

  T query(int r) {
    T q = 0; // check default value of query
    for (; r >= 0; r = (r & (r + 1)) - 1) {
      q += a[r]; // check query modification
    }
    return q;
  }

  void update(int r, T del) {
    for (; r < n; r = r | (r + 1)) {
      a[r] += del; //check update rule
    }
  }
};
