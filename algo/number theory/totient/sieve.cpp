int phi[N];

// source: cp-algorithms
void sieve() {
  phi[0] = 1;
  for (int i = 1; i < N; i++) {
    phi[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
}
