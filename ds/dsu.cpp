struct dsu {
  vector<int> parent, size;
 
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
      if (size[a] < size[b]) swap(a, b);
      parent[b] = a;
      size[a] += size[b];
    }
  }

  dsu() {}
 
  dsu (int n) {
    parent.resize(n);
    size.assign(n, 1);
    iota(all(parent), 0LL);
  }
};

