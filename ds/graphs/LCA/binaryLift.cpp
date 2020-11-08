/**
 * Description: Finding LCA and Kth Ancestor using Binary Lifting
 * Caution:
 *    * adj must be zero indexed
 *    * root must be 0 (can be modified if required)
 * Source : https://codeforces.com/contest/519/submission/10070146
 * Verification : https://codeforces.com/contest/519/problem/E
 */
 
struct LCA {
  vector<vector<int>> anc;
  vector<int> d, size;
  vector<vector<int>> adj;
  int lg;
 
  void Dfs (int p, int v) {
    anc[0][v] = p;
    for (int i = 1; i < lg; i++) {
      anc[i][v] = anc[i-1][anc[i-1][v]];
    }
    size[v] = 1;
    for (int u : adj[v]) {
      if (u == p) continue;
      d[u] = d[v] + 1;
      Dfs(v, u);
      size[v] += size[u];
    }
  }
 
  int get_parent (int v, int k) {
    for (int i = 0; i < lg; i++) {
      if ((1 << i) & k) v = anc[i][v];
    }
    return v;
  }
 
  int lca (int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    u = get_parent(u, d[u] - d[v]);
    if (u == v) return u;
    for (int i = lg - 1; i >= 0; i--) {
      if (anc[i][u] == anc[i][v]) continue;
      u = anc[i][u];
      v = anc[i][v];
    }
    return anc[0][v];
  }
 
  LCA (vector<vector<int>>& g) {
    int n = static_cast<int>(g.size());
    int lg = static_cast<int>(ceil(log2l(static_cast<ld>(n))));
    this->lg = lg;
    adj = g;
    anc.assign(lg, vector<int>(n, 0));
    d.assign(n, 0);
    size.assign(n, 0);
    Dfs(0, 0);
  }
};