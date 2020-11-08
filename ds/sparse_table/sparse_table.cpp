/**
 * Description: Computing min/max function in constant time
 * Source: tourist
 */
#ifdef int
  #undef int
#endif
template <class T, class F = function<T (const T&, const T&)>>
struct SparseTable {
  int n;
  vector<vector<T>> st;
  F func;

  SparseTable () {}

  SparseTable (const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int maxlg = 32 - __builtin_clz(n);
    st.resize(maxlg);
    st[0] = a;
    for (int j = 1; j < maxlg; j++) {
      st[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        st[j][i] = func(st[j-1][i], st[j-1][i + (1 << (j-1))]);
      }
    }
  }

  T get (int l, int r) const {
    int lg = 32 - __builtin_clz(r - l + 1) - 1;
    return func(st[lg][l], st[lg][r - (1 << lg) + 1]);
  }
};