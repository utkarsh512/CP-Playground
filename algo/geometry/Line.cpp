/**
 * Description: Handling Lines in 2D geometry
 *              (Implemented for both integer and real case, real case is the default)
 * Caution: 
 * * include Point as well
 */

template <class T>
struct Line {
  T a, b, c;
  Line() {}
  Line(T a_, T b_, T c_) : a(a_), b(b_), c(c_) {}
  Line(const Point<T>& P, const Point<T>& Q) {
    a = P.y - Q.y;
    b = Q.x - P.x;
    c = -1LL * (a * P.x + b * P.y);

    /*
    T g = gcd(gcd(abs(a), abs(b)), abs(c));
    a /= g; b /= g; c /= g;
    if (a < 0 || (a == 0 || b < 0)) {
      a *= -1; b *= -1; c *= -1;
    }
    */

    T z = (T)sqrt(a * a + b * b);
    a /= z; b /= z; c /= z;
    if (a < (-eps) || (abs(a) < eps && b < (-eps))) {
      a *= -1; b *= -1; c *= -1;
    }
  }

  bool operator==(const Line& oth) {
    // return (a == oth.a && b == oth.b && c == oth.c);
    T A = abs(det(a, b, oth.a, oth.b));
    T B = abs(det(a, c, oth.a, oth.c));
    T c = abs(det(b, c, oth.b, oth.c));
    return (A < eps && B < eps && C < eps);
  }

  bool isect(const Line& oth) {
    T z = det(a, b, oth.a, oth.b);
    if (abs(z) < eps) return false;
    return true;

    /*
    if (z == 0) return false;
    return true;
    */
  }

  template <class U = T> Point<U> isect_point(const Line& oth) {
    // return point of intersection as Point<U>
    // class 'U' is for explicit typecasting
    assert(isect(oth));
    T z = det(a, b, oth.a, oth.b);
    U x = static_cast<U>(-det(c, b, oth.c, oth.b)) / z;
    U y = static_cast<U>(-det(a, c, oth.a, oth.c)) / z;
    return Point(x, y);
  }

  friend string to_string(const Line& L) {
    return to_string(make_tuple(a, b, c));
  }
};
