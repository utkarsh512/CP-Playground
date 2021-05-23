struct Node {
  int cnt[26];
  Node *pt[26];
  Node() {
    for (int i = 0; i < 26; i++) {
      cnt[i] = 0;
      pt[i] = nullptr;
    }
  }
};

struct Trie {
  Node *root;
  Trie() {
    root = new Node();
  }
  void insert(string s) {
    insert(root, s, 0);
  }
  void erase(string s) {
    // make sure 's' was inserted in Trie before deletion
    erase(root, s, 0);
  }
  bool find(string s) {
    return find(root, s, 0);
  }
  bool insert(Node *cur, string s, int idx) {
    if (idx == sz(s)) return true;
    int c = s[idx] - 'a';
    if (cur->pt[c] == nullptr) {
      cur->pt[c] = new Node();
    }
    cur->cnt[c]++;
    return insert(cur->pt[c], s, idx + 1);
  }
  void erase(Node *cur, string s, int idx) {
    if (idx == sz(s)) return;
    int c = s[idx] - 'a';
    cur->cnt[c]--;
    erase(cur->pt[c], s, idx + 1);
  }
  bool find(Node *cur, string s, int idx) {
    if (idx == sz(s)) return true;
    int c = s[idx] - 'a';
    int f = cur->cnt[c];
    if (f > 0) return find(cur->pt[c], s, idx + 1);
    else return false;
  }
};
