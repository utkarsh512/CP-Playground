/**
 * Various implementations of LCA
 * 
 * +---------------------------------+-------------------------------+-----------------------------------------------------------------+
 * | Data Structure & Algorithm Used | Preprocessing and Query Time  | Advantage over others                                           |
 * +---------------------------------+-------------------------------+-----------------------------------------------------------------|
 * | Segment Tree (Euler tour)       | P : O(N),     Q : O(logN)     | Trivial                                                         |
 * | Sparse Table (Euler tour)       | P : O(NlogN), Q : O(1)        | Less complexity for query                                       |
 * | Binary Lifting                  | P : O(NlogN), Q : O(logN)     | Expensive, but can be used to obtain any ancestor of a node     |
 * | Farach-Colton (Bit-masking)     | P : O(N),     Q : O(1)        | Not used in CP afaik                                            |
 * +---------------------------------+-------------------------------+-----------------------------------------------------------------|
 */

/**
 * Description: Computing min/max function in constant time
 * Source: tourist
 */

template <class T, class F = function<T (const T&, const T&)>>
struct SparseTable {
  int n;
  vector<vector<T>> st;
  F func;

  SparseTable () {}

  SparseTable (const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int maxlg = 64 - __builtin_clzll(n);
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
    int lg = 64 - __builtin_clzll(r - l + 1) - 1;
    return func(st[lg][l], st[lg][r - (1 << lg) + 1]);
  }
};

/**
 * Description: Answering LCA only in O(1) time with O(nlogn) pre-processing (Implemented through RMQ)
 * Source: https://cp-algorithms.com/graph/lca.html
 * Verification: https://codeforces.com/contest/29/submission/97877045
 */

struct LCA {
  vector<vector<int>> g;
  vector<int> euler; // storing euler tour of the tree
  vector<int> first; // storing the index where a vertex first appears in euler tour
  vector<int> depth;
  vector<bool> mark;
  SparseTable<int> rmq;

  void Dfs (int u) {
    mark[u] = 1;
    first[u] = sz(euler);
    euler.pb(u);
    for (int v : g[u]) {
      if (mark[v]) continue;
      depth[v] = depth[u] + 1;
      Dfs(v);
      euler.pb(u);
    }
  }

  LCA() {}

  LCA (const vector<vector<int>>& adj) : g(adj) {
    int N = sz(g);
    first.resize(N);
    depth.resize(N);
    mark.resize(N);
    Dfs(0);
    rmq = SparseTable<int>(euler, [&] (const int& L, const int& R) {
      return (depth[L] < depth[R])? L: R;
    });
  }

  int lca (int u, int v) {
    int left = first[u], right = first[v];
    if (left > right) swap(left, right);
    return rmq.get(left, right);
  }
};
