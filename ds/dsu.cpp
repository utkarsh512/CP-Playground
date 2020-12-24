struct dsu {
  vector<int> parent, rank;
 
  int find (int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
  }
 
  bool ask (int a, int b) {
    a = find(a); b = find(b);
    return (a == b);
  }
 
  void join (int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (rank[a] < rank[b]) swap(a, b);
      parent[b] = a;
      if (rank[a] == rank[b]) rank[a]++;
    }
  }

  dsu() {}
 
  dsu (int n) {
    parent.resize(n);
    rank.resize(n);
    iota(all(parent), 0LL);
  }
};
