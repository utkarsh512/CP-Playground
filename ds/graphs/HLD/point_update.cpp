/**
 * Description: Heavy-light decomposition for point updates
 * Complexity: Query - O((logN)^2); Update - O(logN)
 * Caution: SZ is the maxnimum number of vertices (in powers of 2) and the tree must be rooted
 * Source: https://cp-algorithms.com/graph/hld.html
 */

template <class T, int SZ>
struct HeavyLight {
  vector<vector<int>> g;
  SegTree<T, SZ> seg;
  vector<int> parent, depth, heavy, head, pos;
  int cur_pos;

  int dfs(int u) {
    int size = 1;
    int max_c_size = 0;
    for (int c : g[u]) {
      if (c == parent[u]) continue;
      parent[c] = u, depth[c] = depth[u] + 1;
      int c_size = dfs(c);
      size += c_size;
      if (c_size > max_c_size) {
        max_c_size = c_size;
        heavy[u] = c;
      }
    }
    return size;
  }

  int decomp(int v, int h) {
    head[v] = h;
    pos[v] = cur_pos++; // position of v in segtree
    if (~heavy[v]) {
      decomp(heavy[v], h);
    }
    for (int c : g[v]) {
      if (c != parent[v] && c != heavy[v]) {
        decomp(c, c);
      }
    }
  }

  HeavyLight() {}

  HeavyLight(vector<vector<T>> g_) : g(g_) {
    int n = sz(g);
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 1;
    dfs(0); // root of tree
    decomp(0, 0);
  }

  void update(int v, T val) {
    // updating value of vertex v
    seg.update(pos[v], val);
  }

  T query(int a, int b) {
    T res = 0; // default value for query
    for (; head[a] != head[b]; b = parent[head[b]]) {
      if (depth[head[a]] > depth[head[b]]) swap(a, b);
      T cur = seg.query(pos[head[b]], pos[b]);
      // operation
      res += cur;
    }
    if (depth[a] > depth[b]) swap(a, b);
    T lst = seg.query(pos[a], pos[b]);
    // operation
    res += lst;
    return res;
  }
};
