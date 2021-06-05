template <class T>
struct max_queue {
  queue<T> q;
  deque<T> d;

  max_queue() {}

  void push(T x) {
    q.push(x);
    while (sz(d) && d.back() < x) {
      d.pop_back();
    }
    d.push_back(x);
  }

  T pop() {
    T x = q.front();
    q.pop();
    if (x == d.front()) {
      d.pop_front();
    }
    return x;
  }

  T get() {
    return d.front();
  }
};
