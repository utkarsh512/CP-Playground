/**
 * Description: Finding the diameter of tree in O(V + E)
 * Source: Self
 */

struct TD {
  int ans = 0;
  vector<vector<int>> g;

  int Dfs (int u, int pr) {
    pi lol = {0, 0};
    for (int v : g[u]) {
      if (v == pr) continue;
      int te = Dfs(v, u);
      if (lol.ff < te) {
        lol.ss = lol.ff;
        lol.ff = te;
      } else if (lol.ss < te) {
        lol.ss = te;
      }
    }
    imax(ans, lol.ff + lol.ss);
    return lol.ff + 1;
  }

  int run(int u = 0) {
    Dfs(u, u);
    return ans;
  }

  TD(vector<vector<int>>& _g) : g(_g) {}
};
