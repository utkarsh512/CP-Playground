template <class T>
struct linked_list {

  struct Node {
    T val;
    Node *nxt;
  };

  Node *newNode(T x = 0) {
    Node *p = new Node();
    p->val = x;
    p->nxt = nullptr;
    return p;
  }

  Node **head_ref;
  int n;

  linked_list() {
    head_ref = nullptr;
    n = 0;
  }

  int size() {
    return n;
  }

  bool empty() {
    return n == 0;
  }

  friend ostream& operator<<(ostream& out, linked_list& L) {
    if (L.empty()) return out << "{ }";
    Node *p = *L.head_ref;
    out << "{ ";
    for(; p != nullptr; p = p->nxt) {
      out << p->val << " ";
    }
    return out << "}";
  }

  void push_front(T x) {
    Node *p = newNode(x);
    if (empty()) {
      head_ref = new Node*();
      *head_ref = p;
      n++;
      return;
    }
    p->nxt = *head_ref;
    *head_ref = p;
    n++;
  }

  void push_back(T x) {
    Node *p = newNode(x);
    if (empty()) {
      head_ref = new Node*();
      *head_ref = p;
      n++;
      return;
    }
    Node *cur = *head_ref;
    for (; cur->nxt != nullptr; cur = cur->nxt);
    cur->nxt = p;
    n++;
  }

  void insert(int pos, T x) {
    assert(pos >= 0);
    assert(pos <= n);
    if (pos == 0) {
      push_front(x);
      return;
    }
    if (pos == n) {
      push_back(x);
      return;
    }
    n++;
    Node *p = newNode(x);
    Node *cur = *head_ref;
    pos--;
    while (pos > 0) {
      cur = cur->nxt;
      pos--;
    }
    p->nxt = cur->nxt;
    cur->nxt = p;
  }

  void erase(T x) {
    if (empty()) return;
    Node *cur = *head_ref;
    Node *prv = nullptr;
    while (cur != nullptr) {
      if (cur->val == x) break;
      prv = cur;
      cur = cur->nxt;
    }
    if (cur == nullptr) return;
    if (prv == nullptr) {
      *head_ref = cur->nxt;
      delete cur;
    } else {
      prv->nxt = cur->nxt;
      delete cur;
    }
    n--;
  }

  void erase_at(int pos) {
    assert(pos >= 0);
    assert(pos < n);
    Node *cur = *head_ref;
    Node *prv = nullptr;
    while (pos > 0) {
      prv = cur;
      cur = cur->nxt;
      pos--;
    }
    if (prv == nullptr) {
      *head_ref = cur->nxt;
      delete cur;
    } else {
      prv->nxt = cur->nxt;
      delete cur;
    }
    n--;
  }

  void clear() {
    if (empty()) return;
    n = 0;
    Node *cur = *head_ref;
    Node *prv = nullptr;
    delete head_ref;
    while (cur != nullptr) {
      prv = cur;
      cur = cur->nxt;
      delete prv;
    }
  }
};
