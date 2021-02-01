/**
 * Description: Implementation of Kosaraju's algorithm for finding strongly connected components
 * in a directed graph and building the condensation graph
 * Complexity: O(n + m)
 * Tutorial: https://cp-algorithms.com/graph/strongly-connected-components.html
 */

struct SCC {
  vector<vector<int>> g, gt;
  vector<int> id, order;         // id[u] = scc in which u lies
  vector<bool> mark;
  int scc, n;                    // scc is the total count of SCCs present in the digraph

  void dfs1(int u) {
    mark[u] = 1;
    for (int v : g[u]) {
      if (mark[v]) continue;
      dfs1(v);
    }
    order.pb(u);
  }

  void dfs2(int u) {
    mark[u] = 1;
    id[u] = scc;
    for (int v : gt[u]) {
      if (mark[v]) continue;
      dfs2(v);
    }
  }

  void get() {
    gt.resize(n);
    for (int i = 0; i < n; i++) {
      for (int v : g[u]) {
        gt[v].pb(u);
      }
    }
    for (int i = 0; i < n; i++) {
      if (!mark[i]) dfs1(i);
    }
    mark = vector<bool>(n);
    for (int i = 0; i < n; i++) {
      int u = order[n - 1 - i];
      if (!mark[u]) {
        dfs2(u);
        scc++;
      }
    }
  }

  SCC() {}
  
  SCC(vector<vector<int>> g_) : g(g_) {
    n = sz(g); scc = 0;
    id.resize(n); mark.resize(n);
    get();
  }
};
