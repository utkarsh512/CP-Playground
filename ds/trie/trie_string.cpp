#undef int

const int maxn = 1e5 + 10;

struct Node {
  int v;
  int nxt[26];
} lt[maxn * 30];

struct Trie {
  /**
   * Decription: Trie data structure for strings containing only lower case letters
   *             (Can be modified of other types of strings as well)
   * Source: self
   * Verification: Not done yet
   */

  int tot = 0;

  int newNode() {
    lt[tot].v = 0;
    for (int i = 0; i < 26; i++) {
      lt[tot].nxt[i] = -1;
    }
    return tot++;
  }

  Trie() {}

  void update(int rt, const string& s, int v) {
    for (int i = 0; i < sz(s); i++) {
      int id = s[i] - 'a';
      if (lt[rt].nxt[id] == -1) {
        lt[rt].nxt[id] = newNode();
      }
      rt = lt[rt].nxt[id];
      lt[rt].v += v;
    }
  }
  
  bool search (int rt, const string& s) {
    for (int i = 0; i < sz(s); i++) {
      int id = s[i] - 'a';
      int crt = lt[rt].nxt[id];
      if (crt == -1 || lt[crt].v <= 0) return false;
      rt = crt;
    }
    return true;
  }
};