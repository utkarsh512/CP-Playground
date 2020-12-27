// Get primes not greater than n in O(nloglogn)
vector<int> getprimes(int n) {
  vector<int> p;
  vector<bool> is(n + 1, 1);
  for (int i = 2; i <= n; i++) {
    if (is[i]) {
      p.pb(i);
      for (int j = 2 * i; j <= n; j += i) is[j] = 0;
    }
  }
  return p;
}
