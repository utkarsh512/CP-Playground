struct bit {
  /**
   * Decription: Template for bit-manipulation
   * Source: Self
   * Warning: Use 0-indexing while using this template
   */
  
  int set(int b, int i) { return (b | (1 << i)); }
  int unset(int b, int i) { return (b & ~(1 << i)); }
  int flip(int b, int i) { return (b ^ (1 << i)); }
  bool isset(int b, int i) { int temp = (b & (1 << i)); if (temp) return true; return false; }
  int count(int x) { int cnt = 0; while (x) { x &= (x - 1); cnt++; } return cnt; }     // No. of set-bits

  int unite(int a, int b) { return (a | b); }
  int common(int a, int b) { return (a & b); }
  int twt(int a, int b) { return (a & ~b); }   // This without That

  int unset_l(int b, int i) { int mask =  ~((1 << (i + 1)) - 1); return (b & mask); }  // Unset all bits from LSB to i-th bit
  int unset_m(int b, int i) { int mask = (1 << i) - 1; return (b & mask); }            // Unset all bits from MSB to i-th bit
  bool is2p (int x) { return (x && !(x & (x - 1))); }                                  // Is x a power of 2?

  int flip (int x) { // Flips every 0 -> 1 and 1 -> 0
    x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
    x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
    x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
    x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
    x = ((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16);
    return x;
  }

  vector<int> k_subsets (int n, int k) {
    // returns vector of masks for k-element subsets of a set of cardinality n
    vector<int> h;
    int s = (1 << k) - 1;
    while (!(s & 1 << n)) {
      h.pb(s);
      int lo = s & ~(s - 1);       // lowest one bit
      int lz = (s + lo) & ~s;      // lowest zero bit above lo
      s |= lz;                     // add lz to the set
      s &= ~(lz - 1);              // reset bits below lz
      s |= (lz / lo / 2) - 1;      // put back right number of bits at end
    }
    return h;
  }
} bit;