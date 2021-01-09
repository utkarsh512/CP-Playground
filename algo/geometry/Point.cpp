/**
 * Description: Handling points in 2D
 * Caution:
 * * while using it with 'Line' module, make the class 'T' explicit
 */

template <class T>
struct Point {
  //using T = int;
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
  friend Point operator*(T k, Point self) {
    return self * k;
  }
};
