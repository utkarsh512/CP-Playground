// Visit: https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/ for explanation

Node *start_loop_node(Node *A) {
  if (!A || !A->next) return NULL;
  Node *fast = A;
  Node *slow = A;
  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {
      fast = A;
      while (fast != slow) {
        fast = fadt->next;
        slow = slow->next;
      }
      return slow;
    }
  }
  return NULL;
}
