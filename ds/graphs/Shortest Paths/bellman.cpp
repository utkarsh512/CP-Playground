/**
 * Description: Determining single source shortest paths if negative weights exist
 * Complexity: O(nm)
 * Return type: <bool, shotest_path, parent_list, negative_cycle>
 */

struct edge {
  int from;
  int to;
  int cost;
};
using vi = vector<int>;
tuple<bool, vi, vi, vi> bellman (vector<edge> e, int n, int u) {
  const int MX = (int)(1e15);
  vector<int> d(n, MX);
  vector<int> p(n);
  iota(all(p), 0);
  d[u] = 0;
  int x;
  for (int i = 0; i < n; i++) {
    x = -1;
    for (auto l : e) {
      if (d[l.from] < MX) {
        if (d[l.to] > d[l.from] + l.cost) {
          p[l.to] = l.from;
          d[l.to] = max(-MX, d[l.from] + l.cost);
          x = l.to;
        }
      }
    }
  }
  vector<int> cycle;
  bool flag = 1;
  if (~x) {
    flag = 0;
    int y = x;
    for (int i = 0; i < n; i++) y = p[y];
    for (int cur = y;; cur = p[cur]) {
      cycle.pb(cur);
      if (cur == y && sz(cycle) > 1) break;
    }
    reverse(all(cycle));
  }
  tuple<bool, vi, vi, vi> res = {flag, d, p, cycle};
  return res;
}