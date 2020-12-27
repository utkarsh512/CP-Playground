// Computing smallest prime factor as sieve in O(nloglogn)
vector<int> spf(int n) {
  n++;
  vector<int> a(n);
  a[1] = 1;
  for (int i = 2; i < n; i++) {
    if (a[i] == 0) {
      a[i]  = i;
      for (int j = 2 * i; j < n; j += i) {
        if (a[j] == 0) a[j] = i;
      }
    }
  }
  return a;
}
