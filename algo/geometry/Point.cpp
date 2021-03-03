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
  T dot(const Point& oth) const {
    return x * oth.x + y * oth.y;
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
  friend istream& operator>> (istream& is, Point& P) { 
    return is >> P.x >> P.y;
  }
  friend ostream& operator<< (ostream& os, Point& P) {
    return os << P.x << " " << P.y;
  }
  friend string to_string(Point P) {
    string res = "(" + to_string(P.x) + ", " + to_string(P.y) + ")";
    return res;
  }
};
