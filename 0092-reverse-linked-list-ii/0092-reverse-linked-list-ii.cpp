/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prevLeft = &dummy;

    for (int i = 0; i < left - 1; i++) {
        prevLeft = prevLeft->next;
    }

    stack<ListNode*> st;
    ListNode* curr = prevLeft->next;
    for (int i = 0; i < right - left + 1; i++) {
        st.push(curr);
        curr = curr->next;
    }

    ListNode* tail = prevLeft;
    while (!st.empty()) {
        tail->next = st.top();
        tail = tail->next;
        st.pop();
    }

    tail->next = curr;

    return dummy.next;
}
};