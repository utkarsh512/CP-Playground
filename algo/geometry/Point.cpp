template <class T>
struct Point {
  T x, y;
  Point() {}
  Point(T x_, T y_) : x(x_), y(y_) {}
  Point& operator+=(const Point& oth) {
    x += oth.x;
    y += oth.y;
    return *this;
  }
  Point& operator-=(const Point& oth) {
    x -= oth.x;
    y -= oth.y;
    return *this;
  }
  Point& operator*=(const T& k) {
    x *= k;
    y *= k;
    return *this;
  }
  Point& operator/=(const T& k) {
    x /= k;
    y /= k;
    return *this;
  }
  Point operator+(const Point& oth) const {
    return Point(*this) += oth;
  }
  Point operator-(const Point& oth) const {
    return Point(*this) -= oth;
  }
  Point operator*(const T& k) const {
    return Point(*this) *= k;
  }
  Point operator/(const T& k) const {
    return Point(*this) /= k;
  }
  T cross(const Point& oth) const {
    return x * oth.y - y * oth.x;
  }
  T cross(const Point& P, const Point& Q) const {
    return (P - *this).cross(Q - *this);
  }
  friend Point operator*(T k, Point self) {
    return self * k;
  }
};
