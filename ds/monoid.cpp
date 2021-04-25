/*
 * Description: Using y/x format to store a floating point value
 * Note: Only for verification purpose, don't use this during submission
 *       as it has undefined behavior if either of the numerator or
 *       denominator exceed (1 << 63) - 1
 */

struct Monoid {
  int y, x;

  Monoid() {
    y = 0; x = 1;
  }

  Monoid(int a) {
    y = a; x = 1;
  }

  Monoid(int a, int b) {
    int g = __gcd(abs(a), abs(b));
    a /= g;
    b /= g;
    y = a;
    x = b;
  }

  Monoid operator+(const Monoid& oth) const {
    Monoid r;
    int x1 = x;
    int x2 = oth.x;
    int y1 = y;
    int y2 = oth.y;
    int g = __gcd(x1, x2);
    __int128 den = ((__int128) x1 * x2) / g;
    __int128 num = ((__int128) y1 * x2) / g;
    num += ((__int128) y2 * x1) / g;
    __int128 G = __gcd(num, den);
    num /= G;
    den /= G;
    r.y = (int) num;
    r.x = (int) den;
    return r;
  }

  Monoid& operator+=(const Monoid& oth) {
    *this = (*this) + oth;
    return *this;
  }

  Monoid neg() {
    Monoid r = Monoid(y, x);
    r.y *= -1;
    return r;
  }

  Monoid operator*(const Monoid& oth) const {
    Monoid r;
    int x1 = x;
    int x2 = oth.x;
    int y1 = y;
    int y2 = oth.y;
    __int128 num = (__int128) y1 * y2;
    __int128 den = (__int128) x1 * x2;
    __int128 G = __gcd(num, den);
    num /= G;
    den /= G;
    r.y = (int) num;
    r.x = (int) den;
    return r;
  }

  Monoid& operator*=(const Monoid& oth) {
    *this = (*this) * oth;
    return *this;
  }

  friend string to_string(Monoid m) {
    string s = to_string(m.y) + "/" + to_string(m.x);
    return s;
  }
};
