// For more info, see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html

int popcnt(int x) {
  return __builtin_popcountll(x); // count of set-bits
}

int log_2(int x) {
  return 63 - __builtin_clzll(x);
}

int lsb(int x) {
  return __builtin_ffsll(x) - 1; // lowest set bit
}

bool is2p (int x) {
  return (x && !(x & (x - 1)));  // power of 2?
} 

vector<int> subsets(int n, int k) {
  vector<int> h;
  int s = (1 << k) - 1;
  while (!(s & (1 << n))) {
    h.pb(s);
    int lo = s & ~(s - 1);       // lowest one bit
    int lz = (s + lo) & ~s;      // lowest zero bit above lo
    s |= lz;                     // add lz to the set
    s &= ~(lz - 1);              // reset bits below lz
    s |= (lz / lo / 2) - 1;      // put back right number of bits at end
  }
  return h;
}
