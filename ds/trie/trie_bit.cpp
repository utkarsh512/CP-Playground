template <int SZ>
struct IntegerTrie {
  /**
   * Description: Trie data structure for bit manipulation
   * Source: Self
   */

  struct Node {
    int v;
    int nxt[2];
  } lt[40 * SZ];

  int tot = 0;

  int newNode() {
    lt[tot].v = 0;
    lt[tot].nxt[0] = -1;
    lt[tot].nxt[1] = -1;
    return tot++;
  } 

  IntegerTrie() {}

  void update (int rt, int x, int v) {
    for (int i = 31; i >= 0; i--) {
      int id = (x >> i) & 1;
      if (lt[rt].nxt[id] == -1) {
        lt[rt].nxt[id] = newNode();
      }
      rt = lt[rt].nxt[id];
      lt[rt].v += v;
    }
  }

  int query (int rt, int x) {
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
      int id = (x >> i) & 1;
      int crt = lt[rt].nxt[id ^ 1];
      if (crt != -1 && lt[crt].v > 0) ans |= (1ll << i);
      else crt = lt[rt].nxt[id];
      rt = crt;
    }
    return ans;
  }
};