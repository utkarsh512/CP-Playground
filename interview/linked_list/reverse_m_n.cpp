// Reverse a linked list from index [m, n] (VVIP)

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head || !head->next || !m) {
        return head;
    }
    
    ListNode dummy(0), *it = &dummy;
    it->next = head;
    
    for (int i = 0; i < m - 1; ++i) {
        it = it->next;
    }
    
    ListNode* front = it;            
    ListNode* last = it->next; 
    
    ListNode* prev = NULL, *cur = it->next, *next = NULL;
    for (int i = m; i <= n; ++i) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    front->next = prev;
    last->next = cur;
    
    return dummy.next;
}
