template <class T>
struct Mat {
  vector<vector<T>> a;
  int n, m;

  Mat() {}

  Mat(int _n, int _m) : n(_n), m(_m) {
    a = vector<vector<T>>(n, vector<T>(m));
  }

  Mat(int _n, int _m, T val) : n(_n), m(_m) {
    a = vector<vector<T>>(n, vector<T>(m, val));
  }

  Mat(const vector<vector<T>>& oth) {
    a = oth;
    n = sz(a);
    m = sz(a[0]);
  }

  Mat<T> operator*(const Mat<T>& oth) const {
    assert(m == oth.n);
    Mat<T> r(n, oth.m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < oth.m; j++) {
        for (int k = 0; k < m; k++) {
          r.a[i][j] += a[i][k] * oth.a[k][j];
        }
      }
    }
    return r;
  }

  template<class U> friend Mat<T> power(const Mat<T>& a, const U& b) {
    assert(b >= 0);
    assert(a.n == a.m);
    Mat<T> x = a;
    Mat<T> res(a.n, a.m);
    for (int i = 0; i < a.n; i++) res.a[i][i] = 1;
    U p = b;
    while (p > 0) {
      if (p & 1) res = res * x;
      x = x * x;
      p >>= 1;
    }
    return res;
  }
};
