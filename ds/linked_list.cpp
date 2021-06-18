struct Node {
  int val;
  Node *nxt;
};

Node *newNode(int x = 0) {
  Node *p = new Node();
  p->val = x;
  p->nxt = nullptr;
  return p;
}

struct linked_list {
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

  void push_front(int x) {
    n++;
    Node *p = newNode(x);
    if (empty()) {
      head_ref = &p;
      return;
    }
    p->nxt = *head_ref;
    *head_ref = p;
  }

  void push_back(int x) {
    n++;
    Node *p = newNode(x);
    if (empty()) {
      head_ref = &p;
      return;
    }
    Node *cur = *head_ref;
    for (; cur->nxt != nullptr; cur = cur->nxt);
    cur->nxt = p;
  }

  void insert(int pos, int x) {
    static_assert(pos >= 0, "Error: Attempt to insert a node at pos < 0");
    static_assert(pos <= n, "Error: Attempt to insert a node at pos > size()");
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
    Node *a = cur->nxt;
    p->nxt = a;
    cur->nxt = p;
  }
};
