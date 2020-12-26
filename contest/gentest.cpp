// Add header from template.cpp

#define MUTLIPLE_TEST_CASES 1

signed main() {
  freopen("input.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  if (MUTLIPLE_TEST_CASES) {
    int tt = 10;
    cout << tt << "\n";
    while (tt--) {
      int n = 1000;
      cout << n << "\n";
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
        a[i] = rng() % 1000 + i;
      }
      cout << a << "\n";
    }
  } else {
    int n = rng() % 1000;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = rng() % 1000 + i;
    }
    cout << a << "\n";
  }
  return 0;
}
