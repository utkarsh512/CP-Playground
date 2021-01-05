/**
 * Description: Handling Lines in 2D geometry (for integer case)
 * Caution: 
 * * include 'Point' module as well
 */

long long det(long long a, long long b, long long c, long long d) {
  return a * d - b * c;
}

struct Line {
  long long a, b, c;
  Line() {}
  Line(long long a_, long long b_, long long c_) : a(a_), b(b_), c(c_) {}
  Line(const Point& P, const Point& Q) {
    a = P.y - Q.y;
    b = Q.x - P.x;
    c = -1LL * (a * P.x + b * P.y);
    long long g = gcd(gcd(abs(a), abs(b)), abs(c));
    a /= g; b /= g; c /= g;
    if (a < 0 || (a == 0 || b < 0)) {
      a *= -1; b *= -1; c *= -1;
    }
  }

  bool operator==(const Line& oth) {
    return (a == oth.a && b == oth.b && c == oth.c);
  }

  bool isect(const Line& oth) {
    long long z = det(a, b, oth.a, oth.b);
    if (z == 0) return false;
    return true;
  }

  tuple<long long, long long, long long> isect_point(const Line& oth) {
    long long z = det(a, b, oth.a, oth.b);
    long long x = -det(c, b, oth.c, oth.b);
    long long y = -det(a, c, oth.a, oth.c);
    return make_tuple(x, y, z);
  }

  friend string to_string(const Line& L) {
    return to_string(make_tuple(L.a, L.b, L.c));
  }
};
