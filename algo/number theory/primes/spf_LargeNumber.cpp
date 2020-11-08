long long mult (long long a, long long b, long long mod) {
  long long result = 0;
  while (b) {
    if (b & 1)
      result = (result + a) % mod;
    a = (a + a) % mod;
    b >>= 1;
  }
  return result;
}

long long f (long long x, long long c, long long mod) {
  return (mult(x, x, mod) + c) % mod;
}

long long rho (long long n, long long x0=2, long long c=1) {
  long long x = x0;
  long long y = x0;
  long long g = 1;
  while (g == 1) {
    x = f(x, c, n);
    y = f(y, c, n);
    y = f(y, c, n);
    g = gcd(abs(x - y), n);
  }
  return g;
}